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
            tracep->chgCData(oldp+0,(vlTOPp->main__DOT__sel),4);
            tracep->chgBit(oldp+1,(vlTOPp->main__DOT__mode));
            tracep->chgSData(oldp+2,(vlTOPp->main__DOT__A),16);
            tracep->chgSData(oldp+3,(vlTOPp->main__DOT__B),16);
            tracep->chgSData(oldp+4,(vlTOPp->main__DOT__alu1__DOT__alu_out1),16);
            tracep->chgSData(oldp+5,(((8U & (IData)(vlTOPp->main__DOT__sel))
                                       ? 0U : (0xffffU 
                                               & ((4U 
                                                   & (IData)(vlTOPp->main__DOT__sel))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    (~ (IData)(vlTOPp->main__DOT__A))
                                                     : 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     | (~ (IData)(vlTOPp->main__DOT__B))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     & (~ (IData)(vlTOPp->main__DOT__B)))
                                                     : 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     ^ (IData)(vlTOPp->main__DOT__B))))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    (~ 
                                                     ((IData)(vlTOPp->main__DOT__A) 
                                                      | (IData)(vlTOPp->main__DOT__B)))
                                                     : 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     | (IData)(vlTOPp->main__DOT__B)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    (~ 
                                                     ((IData)(vlTOPp->main__DOT__A) 
                                                      & (IData)(vlTOPp->main__DOT__B)))
                                                     : 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     & (IData)(vlTOPp->main__DOT__B)))))))),16);
        }
        tracep->chgSData(oldp+6,(vlTOPp->inst),16);
        tracep->chgSData(oldp+7,(vlTOPp->reg0),16);
        tracep->chgSData(oldp+8,(vlTOPp->reg1),16);
        tracep->chgSData(oldp+9,(vlTOPp->reg2),16);
        tracep->chgSData(oldp+10,(vlTOPp->reg3),16);
        tracep->chgSData(oldp+11,(vlTOPp->reg4),16);
        tracep->chgSData(oldp+12,(vlTOPp->reg5),16);
        tracep->chgSData(oldp+13,(vlTOPp->reg6),16);
        tracep->chgSData(oldp+14,(vlTOPp->reg7),16);
        tracep->chgSData(oldp+15,(vlTOPp->out),16);
        tracep->chgBit(oldp+16,(vlTOPp->cout));
        tracep->chgBit(oldp+17,(vlTOPp->comp));
        tracep->chgCData(oldp+18,((7U & ((IData)(vlTOPp->inst) 
                                         >> 0xdU))),3);
        tracep->chgCData(oldp+19,((7U & ((IData)(vlTOPp->inst) 
                                         >> 0xaU))),3);
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
