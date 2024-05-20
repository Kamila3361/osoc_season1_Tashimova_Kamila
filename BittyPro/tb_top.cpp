#include <stdlib.h>
#include <iostream>
#include <queue>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "bitty_proc.h"

#define MAX_SIM_TIME 10000000
vluint64_t sim_time = 0;

BittyProc bittyProc;

class AluInTx
{
public:
    uint16_t inst;	
}; //Transaction Item

class AluOutTx
{
public:
    uint16_t done;
    uint16_t regOutputs[8];		
    uint16_t regC;				
};

AluInTx* generator()
{
    AluInTx* tx = new AluInTx();
    tx->inst = rand() % 32768;
    return tx;
}

class AluDrv
{
private:
    Vtop* dut;
public:
    AluDrv (Vtop* dut)
    {
        this->dut = dut;
    }

    void drive(AluInTx* tx)
    {
        if(tx != nullptr)
        {
            dut->instruction = tx->inst;
            delete tx;
        }
    }
};

class AluScb
{
private:
    std::deque<AluInTx*> in_q;
public:
    void writeIn(AluInTx* tx)
    {
        in_q.push_back(tx);
    }
    void writeOut(AluOutTx* tx, int state)
    {
        if(in_q.empty())
        {
            std::cout <<"Fatal Error in AluScb: empty AluInTx queue" << std::endl;
            exit(1);
        }
        
        
        AluInTx* in = in_q.front();
        in_q.pop_front();

        uint16_t out = 0;		

        if(state == 3){
            out = bittyProc.Evaluate(in->inst);
        }

        uint16_t sel = (in->inst >> 2) & 0b1111;
        uint16_t mode =  (in->inst >> 1) & 1;
        uint16_t mux_sel1 = (in->inst >> 13) & 0b111;
        uint16_t mux_sel2 = (in->inst >> 10) & 0b111;

        
        if(state == 3 && out != tx->regC)
        {
            std::cout << std::endl;
            std::cout << "sel: " << sel << "mode: " << mode << std::endl;
            std::cout << "MainScb: out != regC" << std::endl;
            std::cout << "  Expected: " << out
                   << "  Actual: " << tx->regC << std::endl;
            std::cout << "  Simtime: " << sim_time << std::endl;
        }
        if(state == 0){
            for(int i = 0; i < 8; i++)
            {
                if(bittyProc.GetRegister(i) != tx->regOutputs[i])
                {
                std::cout << std::endl;
                std::cout << "MainScb: reg" << i << std::endl;
                std::cout << "  Expected: " << bittyProc.GetRegister(i)
                       << "  Actual: " << tx->regOutputs[i] << std::endl;
                std::cout << "  Simtime: " << sim_time << std::endl;              
                }
            }
        }

        if(state == 3 && tx->done != 1)
        {
            std::cout << std::endl;
            std::cout << "MainScb: done" << std::endl;
            std::cout << "  Expected: 1"
                   << "  Actual: " << tx->done << std::endl;
            std::cout << "  Simtime: " << sim_time << std::endl;
        }
 
        delete in;
        delete tx;
    }
};

class AluInMon
{
private:
    Vtop* dut;
    AluScb* scb;
public:
    AluInMon(Vtop* dut, AluScb* scb)
    {
        this->dut = dut;
        this->scb = scb;
    }
	
    void monitor()
    {
        AluInTx* tx = new AluInTx();
        tx->inst = dut->instruction;
        scb->writeIn(tx);      
    }
};

class AluOutMon
{
private:
    Vtop* dut;
    AluScb* scb;
public:
    AluOutMon(Vtop* dut, AluScb* scb)
    {
        this->dut = dut;
        this->scb = scb;
    }

    void monitor(int state)
    {
        AluOutTx* tx = new AluOutTx();
        tx->done = dut->done;
        tx->regOutputs[0] = dut->reg_0;
        tx->regOutputs[1] = dut->reg_1;
        tx->regOutputs[2] = dut->reg_2;
        tx->regOutputs[3] = dut->reg_3;
        tx->regOutputs[4] = dut->reg_4;
        tx->regOutputs[5] = dut->reg_5;
        tx->regOutputs[6] = dut->reg_6;
        tx->regOutputs[7] = dut->reg_7;      
        tx->regC = dut->reg_C;                                
        scb->writeOut(tx, state);       
    }
};

void dut_reset (Vtop *dut, vluint64_t &sim_time){
    dut->reset = 0;
    if(sim_time < 6){
        dut->reset = 1;       
    }
}

int main(int argc, char** argv, char** env) {
    Vtop *dut = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    AluInTx   *tx;

    AluDrv    *drv    = new AluDrv(dut);
    AluScb    *scb    = new AluScb();
    AluInMon  *inMon  = new AluInMon(dut, scb);
    AluOutMon *outMon = new AluOutMon(dut, scb);
    int state = 0;    

    while (sim_time < MAX_SIM_TIME) {
        dut_reset(dut, sim_time);
        dut->clk ^= 1;
        dut->eval();
        // Do all the driving/monitoring on a positive edge
        if (dut->clk == 1){	
            if(dut->reset == 1){
                state = 0;
            }
            else{
                tx = generator();
                if(state == 0){
                    drv->drive(tx);
                    // Monitor the input interface
                    inMon->monitor();
                    inMon->monitor();
                    outMon->monitor(state);
                }
                if(state == 3){
                    // Monitor the output interface
                    outMon->monitor(state);
                }           
                state = (state + 1) % 4;
            }
           
        }
        // end of positive edge processing
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    delete outMon;
    delete inMon;
    delete scb;
    delete drv;

    exit(EXIT_SUCCESS);
}

