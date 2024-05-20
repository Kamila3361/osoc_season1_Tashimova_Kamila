#include <iostream>
#include <ostream>
#include "bitty_proc.h"

// DPI
#include "svdpi.h"
#include "Vtop__Dpi.h"

BittyProc bittyProc;

extern "C" void verification(const svBitVecVal* alu_out, const svBitVecVal* instruction) 
{
    uint16_t alu_out_val = alu_out[0];
    uint16_t instruction_val = instruction[0];
    uint16_t out = bittyProc.Evaluate(instruction_val);
    uint16_t sel = (instruction_val >> 2) & 0b1111;
    uint16_t mode = (instruction_val >> 1) & 1;

    if(out != alu_out_val)
    {
        std::cout << std::endl;
        std::cout << "sel: " << sel << "mode: " << mode << std::endl;
        std::cout << "MainScb: out != alu_out" << std::endl;
        std::cout << "  Expected: " << out
               << "  Actual: " << alu_out_val << std::endl;
        std::cout << "  Instruction: " << instruction_val  << std::endl;
    }
}
