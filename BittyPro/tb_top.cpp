#include <stdlib.h>
#include <iostream>
#include <queue>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"

#define MAX_SIM_TIME 100
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;

class BittyPro
{
public:
        uint16_t alu(uint16_t sel, uint16_t mode, uint16_t a, uint16_t b)
        {
                uint16_t out;
                if(mode == 0)
                {
                        switch(sel)
                        {
                                case 0: 
                                        out = uint16_t(a); 
                                        break;
                                case 1: 
                                        out = uint16_t(a & b);
                                        break;
                                case 2:
                                        out = uint16_t(a & ~b);
                                        break;
                                case 3: 
                                        out = uint16_t(-1); 
                                        break;
                                case 4: 
                                        out = uint16_t(a & (a | ~b));
                                        break;
                                case 5:
                                        out = uint16_t((a & b) + (a | ~b));
                                        break;
                                case 6: 
                                        out = uint16_t(a - b - 1); 
                                        break;
                                case 7: 
                                        out = uint16_t((a | ~b) - 1);
                                        break;
                                case 8:
                                        out = uint16_t(a + (a | b));
                                        break;
                                case 9: 
                                        out = uint16_t(a + b); 
                                        break;
                                case 10: 
                                        out = uint16_t((a & ~b) + (a | b));
                                        break;
                                case 11:
                                        out = uint16_t((a | b) - 1);
                                        break;
                                case 12: 
                                        out = uint16_t(a + a); 
                                        break;
                                case 13: 
                                        out = uint16_t((a & b) + a);
                                        break;
                                case 14:
                                        out = uint16_t((a & ~b) + a);
                                        break;
                                case 15:
                                        out = uint16_t(a - 1);
                                        break;
                        }
                }
                if(mode == 1)
                {
                        switch(sel)
                        {
                                case 0: 
                                        out = uint16_t(~a); 
                                        break;
                                case 1: 
                                        out = uint16_t(~(a & b));
                                        break;
                                case 2:
                                        out = uint16_t(~a | b);
                                        break;
                                case 3: 
                                        out = uint16_t(0); 
                                        break;
                                case 4: 
                                        out = uint16_t(~(a | b));
                                        break;
                                case 5:
                                        out = uint16_t(~b);
                                        break;
                                case 6: 
                                        out = uint16_t(a ^ b); 
                                        break;
                                case 7: 
                                        out = uint16_t(a | ~b);
                                        break;
                                case 8:
                                        out = uint16_t(~a & b);
                                        break;
                                case 9: 
                                        out = uint16_t(~(a ^ b)); 
                                        break;
                                case 10: 
                                        out = uint16_t(b);
                                        break;
                                case 11:
                                        out = uint16_t(a | b);
                                        break;
                                case 12: 
                                        out = uint16_t(1); 
                                        break;
                                case 13: 
                                        out = uint16_t(a & ~b);
                                        break;
                                case 14:
                                        out = uint16_t(a & b);
                                        break;
                                case 15:
                                        out = uint16_t(a);
                                        break;
                        }
                }
                return out;
        }
};


class AluInTx{
	public:
		uint16_t inst;	
}; //Transaction Item

class AluOutTx{
	public:
		uint16_t done;
		uint16_t reg0;
		uint16_t reg1;
		uint16_t reg2;
                uint16_t reg3;
		uint16_t reg4;
                uint16_t reg5;
		uint16_t reg6;
                uint16_t reg7;		
                uint16_t regC;				
};

AluInTx* generator(){
	if(rand() % 5 == 0){
		AluInTx* tx = new AluInTx();
		tx->inst = rand() % 32768;
		return tx;
	} else {
		return nullptr;
	}
}

class AluDrv {
	private:
		Vtop* dut;
	public:
		AluDrv (Vtop* dut){
			this->dut = dut;
		}

		void drive(AluInTx* tx){
			if(tx != nullptr){
				dut->instruction = tx->inst;
				delete tx;
			}
		}
};

class AluScb{
	private:
		std::deque<AluInTx*> in_q;
	public:
		void writeIn(AluInTx* tx){
			in_q.push_back(tx);
		}
		void writeOut(AluOutTx* tx){
			if(in_q.empty()){
				std::cout <<"Fatal Error in AluScb: empty AluInTx queue" << std::endl;
                		exit(1);
			}

			AluInTx* in = in_q.front();
			in_q.pop_front();
				
			uint16_t mux_sel = (in->inst >> 13) & 0b111;
					
			switch(mux_sel){
				case 0:
					if(tx->reg0 != tx->regC){
						std::cout << std::endl;
						std::cout << "MainScb: reg0" << std::endl;
						std::cout << "  Expected: " << tx->regC
							<< "  Actual: " << tx->reg0 << std::endl;
						std::cout << "  Simtime: " << sim_time << std::endl;
					}
					break;
				case 1:
                                        if(tx->reg1 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg1" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg1 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
				case 2:
                                        if(tx->reg2 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg2" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg2 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
				case 3:
                                        if(tx->reg3 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg3" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg3 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
				case 4:
                                        if(tx->reg4 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg4" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg4 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
				case 5:
                                        if(tx->reg5 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg5" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg5 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
				case 6:
                                        if(tx->reg6 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg6" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg6 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
				case 7:
                                        if(tx->reg7 != tx->regC){
                                                std::cout << std::endl;
                                                std::cout << "MainScb: reg7" << std::endl;
                                                std::cout << "  Expected: " << tx->regC
                                                        << "  Actual: " << tx->reg7 << std::endl;
                                                std::cout << "  Simtime: " << sim_time << std::endl;
                                        }
                                        break;
			}
			if(tx->done != 1){
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

class AluInMon{
	private:
		Vtop* dut;
		AluScb* scb;
	public:
		AluInMon(Vtop* dut, AluScb* scb){
			this->dut = dut;
			this->scb = scb;
		}
		
		void monitor(){
			AluInTx* tx = new AluInTx();
			tx->inst = dut->instruction;	
			scb->writeIn(tx);
		}
};

class AluOutMon{
	private:
		Vtop* dut;
		AluScb* scb;
	public:
		AluOutMon(Vtop* dut, AluScb* scb){
			this->dut = dut;
			this->scb = scb;
		}

		void monitor(){
			AluOutTx* tx = new AluOutTx();
			tx->done = dut->done;
			tx->reg0 = dut->reg_0;
                	tx->reg1 = dut->reg_1;
			tx->reg2 = dut->reg_2;
                        tx->reg3 = dut->reg_3;
			tx->reg4 = dut->reg_4;
                        tx->reg5 = dut->reg_5;
			tx->reg6 = dut->reg_6;
                        tx->reg7 = dut->reg_7;
               		tx->regC = dut->reg_C;                        
			scb->writeOut(tx);
		}
};

/*
void dut_reset (Vtop *dut, vluint64_t &sim_time){
    dut->rst = 0;
    if(sim_time >= 3 && sim_time < 6){
        dut->rst = 1;
	dut->inst
    }
} */


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
        dut->eval();

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
    }

    m_trace->close();
    delete dut;
    delete outMon;
    delete inMon;
    delete scb;
    delete drv;

    exit(EXIT_SUCCESS);
}

