// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu__Syms.h"


void Valu::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Valu::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->carry_in));
        tracep->chgSData(oldp+1,(vlTOPp->in_a),16);
        tracep->chgSData(oldp+2,(vlTOPp->in_b),16);
        tracep->chgCData(oldp+3,(vlTOPp->select),3);
        tracep->chgBit(oldp+4,(vlTOPp->mode));
        tracep->chgBit(oldp+5,(vlTOPp->carry_out));
        tracep->chgBit(oldp+6,(vlTOPp->compare));
        tracep->chgSData(oldp+7,(vlTOPp->alu_out),16);
        tracep->chgSData(oldp+8,(vlTOPp->alu__DOT__alu_out1),16);
        tracep->chgSData(oldp+9,((0xffffU & ((4U & (IData)(vlTOPp->select))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->select))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  (~ (IData)(vlTOPp->in_a))
                                                   : 
                                                  ((IData)(vlTOPp->in_a) 
                                                   | (~ (IData)(vlTOPp->in_b))))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((IData)(vlTOPp->in_a) 
                                                   & (~ (IData)(vlTOPp->in_b)))
                                                   : 
                                                  ((IData)(vlTOPp->in_a) 
                                                   ^ (IData)(vlTOPp->in_b))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->select))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlTOPp->in_a) 
                                                    | (IData)(vlTOPp->in_b)))
                                                   : 
                                                  ((IData)(vlTOPp->in_a) 
                                                   | (IData)(vlTOPp->in_b)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  (~ 
                                                   ((IData)(vlTOPp->in_a) 
                                                    & (IData)(vlTOPp->in_b)))
                                                   : 
                                                  ((IData)(vlTOPp->in_a) 
                                                   & (IData)(vlTOPp->in_b))))))),16);
    }
}

void Valu::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
