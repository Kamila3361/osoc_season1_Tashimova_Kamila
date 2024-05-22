#include <stdlib.h>
#include <iostream>
#include <queue>
#include <bitset>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include "bitty_proc.h"

#define MAX_SIM_TIME 50000000
vluint64_t sim_time = 0;

class InstructionGenerator
{
public:
    InstructionGenerator() {}

    uint16_t generate()
    {
        uint16_t instruction = rand() % 32768;
        return instruction;
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

    InstructionGenerator instGenerator;
    int state = 0;    

    while(sim_time < MAX_SIM_TIME)
    {
        dut_reset(dut, sim_time);
        dut->clk ^= 1;
        dut->eval();
        if(dut->clk == 1)
        {
            if(dut->reset == 1)
            {
                state = 0;
            }
            else
            {
                if(state == 0)
                {
                    dut->instruction = instGenerator.generate();
                }

                //checking done 
                if(state == 3 && dut->done != 1)
                {
                    std::cout << std::endl;
                    std::cout << "MainScb: done" << std::endl;
                    std::cout << "  Expected: 1"
                        << "  Actual: " << dut->done << std::endl;
                    std::cout << "  Simtime: " << sim_time << std::endl;
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
    exit(EXIT_SUCCESS);
}

