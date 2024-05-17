#include <stdlib.h>
#include <iostream>
#include <queue>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "bitty_proc.h"

#define MAX_SIM_TIME 100
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;

class AluInTx
{
public:
    uint32_t inst;	
}; //Transaction Item

class AluOutTx
{
public:
    uint32_t done;
    uint32_t regOutputs[8];		
    uint32_t regC;				
};

AluInTx* generator()
{
    if(rand() % 5 == 0){
        AluInTx* tx = new AluInTx();
        tx->inst = rand() % 32768;
        return tx;
    } else {
        return nullptr;
    }
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
    void writeOut(AluOutTx* tx)
    {
        if(in_q.empty())
        {
            std::cout <<"Fatal Error in AluScb: empty AluInTx queue" << std::endl;
            exit(1);
        }

        AluInTx* in = in_q.front();
        in_q.pop_front();
		
        BittyProc bittyProc;
        uint32_t out = bittyProc.Evaluate(in->inst);
        
        uint32_t sel = (in->inst >> 2) & 0b1111;
        uint32_t mode =  (in->inst >> 1) & 1;
        uint32_t mux_sel1 = (in->inst >> 13) & 0b111;
        uint32_t mux_sel2 = (in->inst >> 10) & 0b111;

        
        if(out != tx->regC)
        {
            std::cout << std::endl;
            std::cout << "MainScb: out != regC" << std::endl;
            std::cout << "  Expected: " << out
                   << "  Actual: " << tx->regC << std::endl;
            std::cout << "  Simtime: " << sim_time << std::endl;
        }

        for(uint32_t i = 0; i < 8; i++)
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

        if(tx->done != 1)
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

    void monitor()
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
        scb->writeOut(tx);
    }
};

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
    int state = -1;

    while (sim_time < MAX_SIM_TIME) {
        
        // Do all the driving/monitoring on a positive edge
        if (dut->clk == 1){
		state = (state + 1) % 3;

            if (state == 2 && sim_time >= VERIF_START_TIME) {
                // Generate a randomized transaction item of type AluInTx
                tx = generator();

                // Pass the transaction item to the ALU input interface driver,
                // which drives the input interface based on the info in the
                // transaction item
                drv->drive(tx);

                // Monitor the input interface
                inMon->monitor();

                // Monitor the output interface
                outMon->monitor();
            }
        }  
        dut->clk ^= 1;
        // end of positive edge processing
        m_trace->dump(sim_time);
        sim_time++;

        dut->eval();        
    }

    m_trace->close();
    delete dut;
    delete outMon;
    delete inMon;
    delete scb;
    delete drv;

    exit(EXIT_SUCCESS);
}

