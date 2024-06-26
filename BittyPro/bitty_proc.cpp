// C++ libraries.
#include <cassert>
#include <iostream>

// Local libraries.
#include "bitty_proc.h"

BittyProc::BittyProc():
    registers_( std::vector<uint16_t>(8))
{ }

uint16_t BittyProc::Evaluate(uint16_t instruction)
{
    uint16_t sel = (instruction >> 2) & 0b1111;
    uint16_t mode =  (instruction >> 1) & 1;
    uint16_t mux_sel1 = (instruction >> 13) & 0b111;
    uint16_t mux_sel2 = (instruction >> 10) & 0b111;
    uint16_t a = registers_[mux_sel1];
    uint16_t b = registers_[mux_sel2];

    uint16_t out;

    // Mode can only be 0 or 1 according to the spec.
    assert(mode < 2);
    if(mode == 0)
    {
        switch(sel)
        {
            case 0:
                out = uint16_t(a);
                break;
            case 1:
                out = uint16_t(a | b);
                break;
            case 2:
                out = uint16_t(a | ~b);
                break;
            case 3:
                out = uint16_t(-1);
                break;
            case 4:
                out = uint16_t(a | (a & ~b));
                break;
            case 5:
                out = uint16_t((a | b) + (a & ~b));
                break;
            case 6:
                out = uint16_t(a - b - 1);
                break;
            case 7:
                out = uint16_t((a & ~b) - 1);
                break;
            case 8:
                out = uint16_t(a + (a & b));
                break;
            case 9:
                out = uint16_t(a + b);
                break;
            case 10:
                out = uint16_t((a | ~b) + (a & b));
                break;
            case 11:
                out = uint16_t((a & b) - 1);
                break;
            case 12:
                out = uint16_t(a + a);
                break;
            case 13:
                out = uint16_t((a | b) + a);
                break;
            case 14:
                out = uint16_t((a | ~b) + a);
                break;
            case 15:
                out = uint16_t(a - 1);
                break;
        }
    }
    else if(mode == 1)
    {
        switch(sel)
        {
            case 0:
                out = uint16_t(~a);
                break;
            case 1:
                out = uint16_t(~(a | b));
                break;
            case 2:
                out = uint16_t(~a & b);
                break;
            case 3:
                out = uint16_t(0);
                break;
            case 4:
                out = uint16_t(~(a & b));
                break;
            case 5:
                out = uint16_t(~b);
                break;
            case 6:
                out = uint16_t(a ^ b);
                break;
            case 7:
                out = uint16_t(a & ~b);
                break;
            case 8:
                out = uint16_t(~a | b);
                break;
            case 9:
                out = uint16_t(~(a ^ b));
                break;
            case 10:
                out = uint16_t(b);
                break;
            case 11:
                out = uint16_t(a & b);
                break;
            case 12:
                out = uint16_t(1);
                break;
            case 13:
                out = uint16_t(a | ~b);
                break;
            case 14:
                out = uint16_t(a | b);
                break;
            case 15:
                out = uint16_t(a);
                break;
        }
    }
    
    registers_[mux_sel1] = out;
    return out;
}

uint16_t BittyProc::GetRegister(int reg_num)
{
    return registers_[reg_num];    
}
