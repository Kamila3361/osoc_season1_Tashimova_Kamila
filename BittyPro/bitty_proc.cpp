// C++ libraries.
#include <cassert>
#include <iostream>
#include <cstdint>

// Local libraries.
#include "bitty_proc.h"

BittyProc::BittyProc():
    registers_( std::vector<uint16_t>(8))
{ }

uint16_t BittyProc::Evaluate(uint16_t instruction)
{
    uint16_t sel = (instruction >> 2) & 0b111;
    uint16_t mux_sel1 = (instruction >> 13) & 0b111;
    uint16_t mux_sel2 = (instruction >> 10) & 0b111;
    uint16_t a = registers_[mux_sel1];
    uint16_t b = registers_[mux_sel2];

    uint16_t out;

    // Mode can only be 0 or 1 according to the spec.
   
    switch(sel)
    {
        case 0:
            out = uint16_t(a + b);
            break;
        case 1:
            out = uint16_t(a - b);
            break;
        case 2:
            out = uint16_t(a & b);
            break;
        case 3:
            out = uint16_t(a | b);
            break;
        case 4:
            out = uint16_t(a ^ b);
            break;
        case 5:
            out = uint16_t(a << (b & 0xF));
            break;
        case 6:
            out = uint16_t(a >> (b & 0xF));
            break;
        case 7:
            out = uint16_t((a == b) ? 0 : (a > b) ? 1 : 2);
            break;
        default:
            out = 0;
            break;
    }
    
    registers_[mux_sel1] = out;
    return out;
}

uint16_t BittyProc::GetRegister(int reg_num)
{
    return registers_[reg_num];    
}
