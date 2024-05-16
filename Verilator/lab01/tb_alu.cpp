#include <stdlib.h>
#include <iostream>
#include <queue>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Valu.h"

#define MAX_SIM_TIME 1000000
#define VERIF_START_TIME 7
vluint64_t sim_time = 0;

class AluInTx{
	public:
		uint16_t a;
		uint16_t b;
		uint16_t cin;
		uint16_t sel;
		uint16_t m;
}; //Transaction Item

class AluOutTx{
	public:
		uint16_t out;
                uint16_t cout;
                uint16_t com;
};

AluInTx* generator(){
	if(rand() % 5 == 0){
		AluInTx* tx = new AluInTx();
		tx->a = rand() % 101;
		tx->b = rand() % 101;
		tx->cin = rand() % 2;
		tx->sel = rand() % 8;
		tx->m = rand() % 2;
		return tx;
	} else {
		return nullptr;
	}
}

class AluDrv {
	private:
		Valu* dut;
	public:
		AluDrv (Valu* dut){
			this->dut = dut;
		}

		void drive(AluInTx* tx){
			if(tx != nullptr){
				dut->in_a = tx->a;
				dut->in_b = tx->b;
   				dut->carry_in = tx->cin;
				dut->select = tx->sel;
				dut->mode = tx->m;
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
			
			uint16_t com = (in->a == in->b) ? 1 : 0;	
		
			if(tx->com != com){
				std::cout << std::endl;
                                std::cout << "AluScb: add mismatch" << std::endl;
				std::cout << "  Expected: comp = " << com
				 		<< "  Actual: comp = " << tx->com << std::endl;
				std::cout << "  Simtime: " << sim_time << std::endl;

			}

			if(in->m == 0){
				switch(in->sel){
					case 0:
						if(tx->out != uint16_t(in->a + in->cin)){
							std::cout << std::endl;
                        				std::cout << "AluScb: arithmetic 0" << std::endl;
                        				std::cout << "  Expected:" << uint16_t(in->a + in->cin) 
                                  				 << "  Actual: " << tx->out << std::endl;
                        				std::cout << "  Simtime: " << sim_time << std::endl;
						}
						break;
					case 1:
						if(tx->out != uint16_t((in->a & in->b) + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 1" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & in->b) + in->cin) 
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 2:
						if(tx->out != uint16_t((in->a & ~in->b) + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 2" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & ~in->b) + in->cin) 
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 3:
						if(tx->out != uint16_t(-1 + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 3" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(-1 + in->cin)
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 4:
						if(tx->out != uint16_t((in->a & (in->a | ~in->b)) + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 4" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & (in->a | ~in->b)) + in->cin)
                                                        		<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 5:
						if(tx->out != uint16_t((in->a & in->b) + (in->a | ~in->b) + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 5" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & in->b) + (in->a | ~in->b) + in->cin)
                                                        		<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 6:
						if(tx->out != uint16_t(in->a - in->b - 1 + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout<<in->a<<" "<<in->b<<" "<<in->cin<<std::endl;
                                                        std::cout << "AluScb: arithmetic 6" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a - in->b - 1 + in->cin)
                                                        		<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 7:
						if(tx->out != uint16_t((in->a | ~in->b) - 1 + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout<<in->a<<" "<<in->b<<" "<<in->cin<<std::endl;
                                                        std::cout << "AluScb: arithmetic 7" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a | ~in->b) - 1 + in->cin)
                                                        		 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 8:
                                                if(tx->out != uint16_t(in->a + (in->a | in->b) + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 8" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a + (in->a | in->b) + in->cin)
                                                                        << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 9:
                                                if(tx->out != uint16_t(in->a + in->b + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 9" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a + in->b + in->cin)
                                                                        << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 10:
                                                if(tx->out != uint16_t((in->a & ~in->b) + (in->a | in->b) + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 10" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & ~in->b) + (in->a | in->b) + in->cin)
                                                                         << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 11:
                                                if(tx->out != uint16_t((in->a | in->b) - 1 + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 11" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a | in->b) - 1 + in->cin)
                                                                        << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 12:
                                                if(tx->out != uint16_t(in->a + in->a + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 12" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a + in->a + in->cin)
                                                                        << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 13:
                                                if(tx->out != uint16_t((in->a & in->b) + in->a + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 13" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & in->b) + in->a + in->cin)
                                                                         << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 14:
                                                if(tx->out != uint16_t((in->a & ~in->b) + in->a + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 14" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t((in->a & ~in->b) + in->a + in->cin)
                                                                        << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 15:
                                                if(tx->out != uint16_t(in->a - 1 + in->cin)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: arithmetic 15" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a - 1 + in->cin)
                                                                        << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;                                      
				}
			} else if(in->m == 1){
				switch(in->sel){
					case 0:
						if(tx->out != uint16_t(~in->a)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 0" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~in->a)
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 1:
						if(tx->out != uint16_t(~(in->a & in->b))){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 1" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~(in->a & in->b))
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 2:
						if(tx->out != uint16_t(~in->a | in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 2" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~in->a | in->b)
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 3:
						if(tx->out != uint16_t(0)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 3" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(0)
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 4:
						if(tx->out != uint16_t(~(in->a | in->b))){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 4" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~(in->a | in->b))       
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 5:
						if(tx->out != uint16_t(~in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 5" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~in->b)
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 6:
						if(tx->out != uint16_t(in->a ^ in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 6" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a ^ in->b)
                                                        	 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 7:
						if(tx->out != uint16_t(in->a | ~in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 7" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a | ~in->b)
                                                        	<< "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 8:
                                                if(tx->out != uint16_t(~in->a & in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 8" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~in->a & in->b)
                                                                 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 9:
                                                if(tx->out != uint16_t(~(in->a ^ in->b))){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 9" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(~(in->a ^ in->b))
                                                                 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 10:
                                                if(tx->out != uint16_t(in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 10" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->b)
                                                                << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 11:
                                                if(tx->out != uint16_t(in->a | in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 11" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a | in->b)
                                                                 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 12:
                                                if(tx->out != uint16_t(1)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 6" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(1)
                                                                 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 13:
                                                if(tx->out != uint16_t(in->a & ~in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 7" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a & ~in->b)
                                                                << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
					case 14:
                                                if(tx->out != uint16_t(in->a & in->b)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 14" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a & in->b)
                                                                 << "  Actual: " << tx->out << std::endl;
                                                        std::cout << "  Simtime: " << sim_time << std::endl;
                                                }
                                                break;
                                        case 15:
                                                if(tx->out != uint16_t(in->a)){
                                                        std::cout << std::endl;
                                                        std::cout << "AluScb: logic 15" << std::endl;
                                                        std::cout << "  Expected: " << uint16_t(in->a)
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
		Valu* dut;
		AluScb* scb;
	public:
		AluInMon(Valu* dut, AluScb* scb){
			this->dut = dut;
			this->scb = scb;
		}
		
		void monitor(){
			AluInTx* tx = new AluInTx();
			tx->a = dut->in_a;
			tx->b = dut->in_b;
			tx->cin = dut->carry_in;
			tx->sel = dut->select;
			tx->m = dut->mode;

			scb->writeIn(tx);
		}
};

class AluOutMon{
	private:
		Valu* dut;
		AluScb* scb;
	public:
		AluOutMon(Valu* dut, AluScb* scb){
			this->dut = dut;
			this->scb = scb;
		}

		void monitor(){
			AluOutTx* tx = new AluOutTx();
			tx->out = dut->alu_out;
			tx->cout = dut->carry_out;
			tx->com = dut->compare;

			scb->writeOut(tx);
		}
};

int main(int argc, char** argv, char** env) {
    Valu *dut = new Valu;

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

