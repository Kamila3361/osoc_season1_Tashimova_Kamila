#include <iostream>
#include "bitty_proc.h"

BittyProc::BittyProc():
    registers( std::vector<uint32_t>(8))
{ }

uint32_t BittyProc::Evaluate(uint32_t instruction)
{
    uint32_t sel = (instruction >> 2) & 0b1111;
    uint32_t mode =  (instruction >> 1) & 1;
    uint32_t mux_sel1 = (instruction >> 13) & 0b111;
    uint32_t mux_sel2 = (instruction >> 10) & 0b111;
    uint32_t a = registers[mux_sel1];
    uint32_t b = registers[mux_sel2];
    
    uint32_t out;
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
    registers[mux_sel1] = out;
    return out;
}

uint32_t BittyProc::GetRegister(uint32_t reg_num)
{
    return registers[reg_num];    
}
