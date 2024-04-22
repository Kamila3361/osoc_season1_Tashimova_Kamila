#include <stdlib.h>
#include <iostream>
#include <queue>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vmain.h"

#define MAX_SIM_TIME 50
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;

class AluInTx{
	public:
		uint16_t inst;
		uint16_t reg0;
		uint16_t reg1;
		uint16_t reg2;
		uint16_t reg3;
		uint16_t reg4;
		uint16_t reg5;
		uint16_t reg6;
		uint16_t reg7;
}; //Transaction Item

class AluOutTx{
	public:
		uint16_t out;
};

AluInTx* generator(){
	if(rand() % 5 == 0){
		AluInTx* tx = new AluInTx();
		tx->inst = rand() % 32768;
		tx->reg0 = rand() % 32768;
		tx->reg1 = rand() % 32768;
		tx->reg2 = rand() % 32768;
		tx->reg3 = rand() % 32768;
		tx->reg4 = rand() % 32768;
		tx->reg5 = rand() % 32768;
		tx->reg6 = rand() % 32768;
		tx->reg7 = rand() % 32768;
		return tx;
	} else {
		return nullptr;
	}
}

class AluDrv {
	private:
		Vmain* dut;
	public:
		AluDrv (Vmain* dut){
			this->dut = dut;
		}

		void drive(AluInTx* tx){
			if(tx != nullptr){
				dut->inst = tx->inst;
				dut->reg0 = tx->reg0;
   				dut->reg1 = tx->reg1;
				dut->reg2 = tx->reg2;
				dut->reg3 = tx->reg3;
				dut->reg4 = tx->reg4;
   				dut->reg5 = tx->reg5;
				dut->reg6 = tx->reg6;
				dut->reg7 = tx->reg7;
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

			uint16_t sel = (in->inst >> 2) & 0b1111;
			uint16_t mode =  (in->inst >> 1) & 1;			
			uint16_t mux_sel1 = (in->inst >> 13) & 0b111;
			uint16_t mux_sel2 = (in->inst >> 10) & 0b111;
			
			uint16_t a, b;

			switch(mux_sel1){
				case 0: 
					a = in->reg0;
					break;
				case 1:
                                        a = in->reg1;
                                        break;
				case 2:
                                        a = in->reg2;
                                        break;
				case 3:
                                        a = in->reg3;
                                        break;
				case 4:
                                        a = in->reg4;
                                        break;
				case 5:
                                        a = in->reg5;
                                        break;
				case 6:
                                        a = in->reg6;
                                        break;
				case 7:
                                        a = in->reg7;
                                        break;
			}
			
			switch(mux_sel2){
                                case 0:
                                        b = in->reg0;
                                        break;
                                case 1:
                                        b = in->reg1;
                                        break;
                                case 2:
                                        b = in->reg2;
                                        break;
                                case 3:
                                        b = in->reg3;
                                        break;
                                case 4:
                                        b = in->reg4;
                                        break;
                                case 5:
                                        b = in->reg5;
                                        break;
                                case 6:
                                        b = in->reg6;
                                        break;
                                case 7:
                                        b = in->reg7;
                                        break;
                        }
	
			if(mode == 0){
				switch(sel){
					case 0:
						if(tx->out != 1){
							std::cout << std::endl;
                        				std::cout << "AluScb: arithmetic 0" << std::endl;
                        				std::cout << "  Expected: alu_out = 1" << std::endl; 
                                  			std::cout << "  Actual: " << tx->out << std::endl;
                        				std::cout << "  Simtime: " << sim_time << std::endl;
						}
						break;
					case 1:
						if(tx->out != uint16_t(a - 1)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 1" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a - 1) 
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 2:
						if(tx->out != uint16_t(a + b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 2" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a + b) 
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 3:
						if(tx->out != uint16_t(a - b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 3" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a - b)
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 4:
						if(tx->out != uint16_t((a * b) - 1)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 4" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((a * b) - 1)
                                                        		<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 5:
						if(tx->out != uint16_t((a * ~b) - 1)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 5" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((a * ~b) - 1)
                                                        		<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 6:
						if(tx->out != uint16_t(a + a)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 6" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a + a)
                                                        		<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 7:
						if(tx->out != uint16_t(a + 1)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 7" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a + 1)
                                                        		 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
				}
			} else if(mode == 1){
				switch(sel){
					case 0:
						if(tx->out != uint16_t(a & b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 0" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a && b) << " " << a << " " << b
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 1:
						if(tx->out != uint16_t(~(a & b))){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 1" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~(a & b)) << " " << a << " " << b
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 2:
						if(tx->out != uint16_t(a | b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 2" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a | b)
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 3:
						if(tx->out != uint16_t(~(a | b))){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 3" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~(a | b))
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 4:
						if(tx->out != uint16_t(a ^ b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 4" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a ^ b)
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 5:
						if(tx->out != uint16_t(a & ~b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 5" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a & ~b)
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 6:
						if(tx->out != uint16_t(a | ~b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 6" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(a | ~b) << " " << a << " " << b
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 7:
						if(tx->out != (uint16_t(~(a)))){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 7" << std::endl;
                                                        std::cout << "  Expected: " << (uint16_t(~(a)))
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
				}
			}
			delete in;
			delete tx;
		}
};

class AluInMon{
	private:
		Vmain* dut;
		AluScb* scb;
	public:
		AluInMon(Vmain* dut, AluScb* scb){
			this->dut = dut;
			this->scb = scb;
		}
		
		void monitor(){
			AluInTx* tx = new AluInTx();
			tx->inst = rand() % 32768;
			tx->reg0 = rand() % 32768;
			tx->reg1 = rand() % 32768;
			tx->reg2 = rand() % 32768;
			tx->reg3 = rand() % 32768;
			tx->reg4 = rand() % 32768;
			tx->reg5 = rand() % 32768;
			tx->reg6 = rand() % 32768;
			tx->reg7 = rand() % 32768;	
			scb->writeIn(tx);
		}
};

class AluOutMon{
	private:
		Vmain* dut;
		AluScb* scb;
	public:
		AluOutMon(Vmain* dut, AluScb* scb){
			this->dut = dut;
			this->scb = scb;
		}

		void monitor(){
			AluOutTx* tx = new AluOutTx();
			tx->out = dut->out;

			scb->writeOut(tx);
		}
};

int main(int argc, char** argv, char** env) {
    Vmain *dut = new Vmain;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    AluInTx   *tx;

    AluDrv    *drv    = new AluDrv(dut);
    AluScb    *scb    = new AluScb();
    AluInMon  *inMon  = new AluInMon(dut, scb);
    AluOutMon *outMon = new AluOutMon(dut, scb);

    while (sim_time < MAX_SIM_TIME) {
            if (sim_time >= VERIF_START_TIME) {
                // Generate a randomized transaction item of type AluInTx
                tx = generator();

                // Pass the transaction item to the ALU input interface driver,
                // which drives the input interface based on the info in the
                // transaction item
                drv->drive(tx);
		dut->eval();
                // Monitor the input interface
                inMon->monitor();

                // Monitor the output interface
                outMon->monitor();
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

