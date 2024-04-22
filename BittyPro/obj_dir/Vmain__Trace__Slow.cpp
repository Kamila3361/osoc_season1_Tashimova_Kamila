// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmain__Syms.h"


//======================

void Vmain::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vmain::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmain::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vmain::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vmain::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+7,"inst", false,-1, 15,0);
        tracep->declBus(c+8,"reg0", false,-1, 15,0);
        tracep->declBus(c+9,"reg1", false,-1, 15,0);
        tracep->declBus(c+10,"reg2", false,-1, 15,0);
        tracep->declBus(c+11,"reg3", false,-1, 15,0);
        tracep->declBus(c+12,"reg4", false,-1, 15,0);
        tracep->declBus(c+13,"reg5", false,-1, 15,0);
        tracep->declBus(c+14,"reg6", false,-1, 15,0);
        tracep->declBus(c+15,"reg7", false,-1, 15,0);
        tracep->declBus(c+16,"out", false,-1, 15,0);
        tracep->declBit(c+17,"cout", false,-1);
        tracep->declBit(c+18,"comp", false,-1);
        tracep->declBus(c+7,"main inst", false,-1, 15,0);
        tracep->declBus(c+8,"main reg0", false,-1, 15,0);
        tracep->declBus(c+9,"main reg1", false,-1, 15,0);
        tracep->declBus(c+10,"main reg2", false,-1, 15,0);
        tracep->declBus(c+11,"main reg3", false,-1, 15,0);
        tracep->declBus(c+12,"main reg4", false,-1, 15,0);
        tracep->declBus(c+13,"main reg5", false,-1, 15,0);
        tracep->declBus(c+14,"main reg6", false,-1, 15,0);
        tracep->declBus(c+15,"main reg7", false,-1, 15,0);
        tracep->declBus(c+16,"main out", false,-1, 15,0);
        tracep->declBit(c+17,"main cout", false,-1);
        tracep->declBit(c+18,"main comp", false,-1);
        tracep->declBus(c+1,"main sel", false,-1, 3,0);
        tracep->declBit(c+2,"main mode", false,-1);
        tracep->declBus(c+19,"main mux_sel1", false,-1, 2,0);
        tracep->declBus(c+20,"main mux_sel2", false,-1, 2,0);
        tracep->declBus(c+3,"main A", false,-1, 15,0);
        tracep->declBus(c+4,"main B", false,-1, 15,0);
        tracep->declBus(c+7,"main unit1 inst", false,-1, 15,0);
        tracep->declBit(c+21,"main unit1 number", false,-1);
        tracep->declBus(c+1,"main unit1 sel", false,-1, 3,0);
        tracep->declBit(c+2,"main unit1 mode", false,-1);
        tracep->declBus(c+19,"main unit1 mux_sel", false,-1, 2,0);
        tracep->declBus(c+19,"main unit1 mux_sel_reg", false,-1, 2,0);
        tracep->declBus(c+7,"main unit2 inst", false,-1, 15,0);
        tracep->declBit(c+22,"main unit2 number", false,-1);
        tracep->declBus(c+1,"main unit2 sel", false,-1, 3,0);
        tracep->declBit(c+2,"main unit2 mode", false,-1);
        tracep->declBus(c+20,"main unit2 mux_sel", false,-1, 2,0);
        tracep->declBus(c+20,"main unit2 mux_sel_reg", false,-1, 2,0);
        tracep->declBit(c+22,"main alu1 carry_in", false,-1);
        tracep->declBus(c+3,"main alu1 in_a", false,-1, 15,0);
        tracep->declBus(c+4,"main alu1 in_b", false,-1, 15,0);
        tracep->declBus(c+1,"main alu1 select", false,-1, 3,0);
        tracep->declBit(c+2,"main alu1 mode", false,-1);
        tracep->declBit(c+17,"main alu1 carry_out", false,-1);
        tracep->declBit(c+18,"main alu1 compare", false,-1);
        tracep->declBus(c+16,"main alu1 alu_out", false,-1, 15,0);
        tracep->declBus(c+5,"main alu1 alu_out1", false,-1, 15,0);
        tracep->declBus(c+6,"main alu1 alu_out2", false,-1, 15,0);
        tracep->declBit(c+22,"main alu1 arith carry_in", false,-1);
        tracep->declBus(c+3,"main alu1 arith in_a", false,-1, 15,0);
        tracep->declBus(c+4,"main alu1 arith in_b", false,-1, 15,0);
        tracep->declBus(c+1,"main alu1 arith select", false,-1, 3,0);
        tracep->declBit(c+17,"main alu1 arith carry_out", false,-1);
        tracep->declBit(c+18,"main alu1 arith compare", false,-1);
        tracep->declBus(c+5,"main alu1 arith alu_out", false,-1, 15,0);
        tracep->declBus(c+3,"main alu1 log in_a", false,-1, 15,0);
        tracep->declBus(c+4,"main alu1 log in_b", false,-1, 15,0);
        tracep->declBus(c+1,"main alu1 log select", false,-1, 3,0);
        tracep->declBus(c+6,"main alu1 log alu_out", false,-1, 15,0);
    }
}

void Vmain::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vmain::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vmain::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vmain__Syms* __restrict vlSymsp = static_cast<Vmain__Syms*>(userp);
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->main__DOT__sel),4);
        tracep->fullBit(oldp+2,(vlTOPp->main__DOT__mode));
        tracep->fullSData(oldp+3,(vlTOPp->main__DOT__A),16);
        tracep->fullSData(oldp+4,(vlTOPp->main__DOT__B),16);
        tracep->fullSData(oldp+5,(vlTOPp->main__DOT__alu1__DOT__alu_out1),16);
        tracep->fullSData(oldp+6,(((8U & (IData)(vlTOPp->main__DOT__sel))
                                    ? 0U : (0xffffU 
                                            & ((4U 
                                                & (IData)(vlTOPp->main__DOT__sel))
                                                ? (
                                                   (2U 
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
                                                : (
                                                   (2U 
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
        tracep->fullSData(oldp+7,(vlTOPp->inst),16);
        tracep->fullSData(oldp+8,(vlTOPp->reg0),16);
        tracep->fullSData(oldp+9,(vlTOPp->reg1),16);
        tracep->fullSData(oldp+10,(vlTOPp->reg2),16);
        tracep->fullSData(oldp+11,(vlTOPp->reg3),16);
        tracep->fullSData(oldp+12,(vlTOPp->reg4),16);
        tracep->fullSData(oldp+13,(vlTOPp->reg5),16);
        tracep->fullSData(oldp+14,(vlTOPp->reg6),16);
        tracep->fullSData(oldp+15,(vlTOPp->reg7),16);
        tracep->fullSData(oldp+16,(vlTOPp->out),16);
        tracep->fullBit(oldp+17,(vlTOPp->cout));
        tracep->fullBit(oldp+18,(vlTOPp->comp));
        tracep->fullCData(oldp+19,((7U & ((IData)(vlTOPp->inst) 
                                          >> 0xdU))),3);
        tracep->fullCData(oldp+20,((7U & ((IData)(vlTOPp->inst) 
                                          >> 0xaU))),3);
        tracep->fullBit(oldp+21,(1U));
        tracep->fullBit(oldp+22,(0U));
    }
}
