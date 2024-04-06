// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu__Syms.h"


//======================

void Valu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Valu::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Valu::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Valu::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Valu::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"carry_in", false,-1);
        tracep->declBus(c+2,"in_a", false,-1, 15,0);
        tracep->declBus(c+3,"in_b", false,-1, 15,0);
        tracep->declBus(c+4,"select", false,-1, 2,0);
        tracep->declBit(c+5,"mode", false,-1);
        tracep->declBit(c+6,"carry_out", false,-1);
        tracep->declBit(c+7,"compare", false,-1);
        tracep->declBus(c+8,"alu_out", false,-1, 15,0);
        tracep->declBit(c+1,"alu carry_in", false,-1);
        tracep->declBus(c+2,"alu in_a", false,-1, 15,0);
        tracep->declBus(c+3,"alu in_b", false,-1, 15,0);
        tracep->declBus(c+4,"alu select", false,-1, 2,0);
        tracep->declBit(c+5,"alu mode", false,-1);
        tracep->declBit(c+6,"alu carry_out", false,-1);
        tracep->declBit(c+7,"alu compare", false,-1);
        tracep->declBus(c+8,"alu alu_out", false,-1, 15,0);
        tracep->declBus(c+9,"alu alu_out1", false,-1, 15,0);
        tracep->declBus(c+10,"alu alu_out2", false,-1, 15,0);
        tracep->declBit(c+1,"alu arith carry_in", false,-1);
        tracep->declBus(c+2,"alu arith in_a", false,-1, 15,0);
        tracep->declBus(c+3,"alu arith in_b", false,-1, 15,0);
        tracep->declBus(c+4,"alu arith select", false,-1, 2,0);
        tracep->declBit(c+6,"alu arith carry_out", false,-1);
        tracep->declBit(c+7,"alu arith compare", false,-1);
        tracep->declBus(c+9,"alu arith alu_out", false,-1, 15,0);
        tracep->declBus(c+2,"alu log in_a", false,-1, 15,0);
        tracep->declBus(c+3,"alu log in_b", false,-1, 15,0);
        tracep->declBus(c+4,"alu log select", false,-1, 2,0);
        tracep->declBus(c+10,"alu log alu_out", false,-1, 15,0);
    }
}

void Valu::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Valu::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Valu::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Valu__Syms* __restrict vlSymsp = static_cast<Valu__Syms*>(userp);
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->carry_in));
        tracep->fullSData(oldp+2,(vlTOPp->in_a),16);
        tracep->fullSData(oldp+3,(vlTOPp->in_b),16);
        tracep->fullCData(oldp+4,(vlTOPp->select),3);
        tracep->fullBit(oldp+5,(vlTOPp->mode));
        tracep->fullBit(oldp+6,(vlTOPp->carry_out));
        tracep->fullBit(oldp+7,(vlTOPp->compare));
        tracep->fullSData(oldp+8,(vlTOPp->alu_out),16);
        tracep->fullSData(oldp+9,(vlTOPp->alu__DOT__alu_out1),16);
        tracep->fullSData(oldp+10,((0xffffU & ((4U 
                                                & (IData)(vlTOPp->select))
                                                ? (
                                                   (2U 
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
                                                : (
                                                   (2U 
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
