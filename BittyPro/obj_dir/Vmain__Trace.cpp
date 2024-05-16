// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmain__Syms.h"


void Vmain::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vmain::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgSData(oldp+0,(vlTOPp->main__DOT__inst),16);
            tracep->chgSData(oldp+1,(vlTOPp->main__DOT__reg0),16);
            tracep->chgSData(oldp+2,(vlTOPp->main__DOT__reg1),16);
            tracep->chgSData(oldp+3,(vlTOPp->main__DOT__reg2),16);
            tracep->chgSData(oldp+4,(vlTOPp->main__DOT__reg3),16);
            tracep->chgSData(oldp+5,(vlTOPp->main__DOT__reg4),16);
            tracep->chgSData(oldp+6,(vlTOPp->main__DOT__reg5),16);
            tracep->chgSData(oldp+7,(vlTOPp->main__DOT__reg6),16);
            tracep->chgSData(oldp+8,(vlTOPp->main__DOT__reg7),16);
            tracep->chgSData(oldp+9,(vlTOPp->main__DOT__regS),16);
            tracep->chgSData(oldp+10,(vlTOPp->main__DOT__regC),16);
            tracep->chgSData(oldp+11,(vlTOPp->main__DOT__mux_out),16);
            tracep->chgCData(oldp+12,(vlTOPp->main__DOT__sel),4);
            tracep->chgBit(oldp+13,(vlTOPp->main__DOT__Alu__DOT__cout));
            tracep->chgBit(oldp+14,(((IData)(vlTOPp->main__DOT__regS) 
                                     == (IData)(vlTOPp->main__DOT__mux_out))));
            tracep->chgBit(oldp+15,(vlTOPp->main__DOT__mode));
            tracep->chgBit(oldp+16,(vlTOPp->main__DOT__S_enable));
            tracep->chgBit(oldp+17,(vlTOPp->main__DOT__C_enable));
            tracep->chgCData(oldp+18,(vlTOPp->main__DOT__mux_sel),3);
            tracep->chgCData(oldp+19,(vlTOPp->main__DOT__reg_enable),8);
            tracep->chgSData(oldp+20,(vlTOPp->main__DOT__Alu__DOT__out),16);
            tracep->chgCData(oldp+21,(vlTOPp->main__DOT__cu__DOT__state),3);
            tracep->chgBit(oldp+22,((1U & (IData)(vlTOPp->main__DOT__reg_enable))));
            tracep->chgBit(oldp+23,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 1U))));
            tracep->chgBit(oldp+24,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 2U))));
            tracep->chgBit(oldp+25,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 3U))));
            tracep->chgBit(oldp+26,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 4U))));
            tracep->chgBit(oldp+27,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 5U))));
            tracep->chgBit(oldp+28,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 6U))));
            tracep->chgBit(oldp+29,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                           >> 7U))));
        }
        tracep->chgSData(oldp+30,(vlTOPp->instruction),16);
        tracep->chgBit(oldp+31,(vlTOPp->clk));
        tracep->chgBit(oldp+32,(vlTOPp->reset));
        tracep->chgBit(oldp+33,(vlTOPp->done));
        tracep->chgSData(oldp+34,(vlTOPp->reg_0),16);
        tracep->chgSData(oldp+35,(vlTOPp->reg_1),16);
        tracep->chgSData(oldp+36,(vlTOPp->reg_2),16);
        tracep->chgSData(oldp+37,(vlTOPp->reg_3),16);
        tracep->chgSData(oldp+38,(vlTOPp->reg_4),16);
        tracep->chgSData(oldp+39,(vlTOPp->reg_5),16);
        tracep->chgSData(oldp+40,(vlTOPp->reg_6),16);
        tracep->chgSData(oldp+41,(vlTOPp->reg_7),16);
        tracep->chgSData(oldp+42,(vlTOPp->reg_C),16);
    }
}

void Vmain::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
