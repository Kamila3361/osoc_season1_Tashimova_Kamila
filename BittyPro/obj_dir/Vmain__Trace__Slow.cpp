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
        tracep->declBus(c+31,"instruction", false,-1, 15,0);
        tracep->declBit(c+32,"clk", false,-1);
        tracep->declBit(c+33,"reset", false,-1);
        tracep->declBit(c+34,"done", false,-1);
        tracep->declBus(c+35,"reg_0", false,-1, 15,0);
        tracep->declBus(c+36,"reg_1", false,-1, 15,0);
        tracep->declBus(c+37,"reg_2", false,-1, 15,0);
        tracep->declBus(c+38,"reg_3", false,-1, 15,0);
        tracep->declBus(c+39,"reg_4", false,-1, 15,0);
        tracep->declBus(c+40,"reg_5", false,-1, 15,0);
        tracep->declBus(c+41,"reg_6", false,-1, 15,0);
        tracep->declBus(c+42,"reg_7", false,-1, 15,0);
        tracep->declBus(c+43,"reg_C", false,-1, 15,0);
        tracep->declBus(c+31,"main instruction", false,-1, 15,0);
        tracep->declBit(c+32,"main clk", false,-1);
        tracep->declBit(c+33,"main reset", false,-1);
        tracep->declBit(c+34,"main done", false,-1);
        tracep->declBus(c+35,"main reg_0", false,-1, 15,0);
        tracep->declBus(c+36,"main reg_1", false,-1, 15,0);
        tracep->declBus(c+37,"main reg_2", false,-1, 15,0);
        tracep->declBus(c+38,"main reg_3", false,-1, 15,0);
        tracep->declBus(c+39,"main reg_4", false,-1, 15,0);
        tracep->declBus(c+40,"main reg_5", false,-1, 15,0);
        tracep->declBus(c+41,"main reg_6", false,-1, 15,0);
        tracep->declBus(c+42,"main reg_7", false,-1, 15,0);
        tracep->declBus(c+43,"main reg_C", false,-1, 15,0);
        tracep->declBus(c+1,"main inst", false,-1, 15,0);
        tracep->declBus(c+2,"main reg0", false,-1, 15,0);
        tracep->declBus(c+3,"main reg1", false,-1, 15,0);
        tracep->declBus(c+4,"main reg2", false,-1, 15,0);
        tracep->declBus(c+5,"main reg3", false,-1, 15,0);
        tracep->declBus(c+6,"main reg4", false,-1, 15,0);
        tracep->declBus(c+7,"main reg5", false,-1, 15,0);
        tracep->declBus(c+8,"main reg6", false,-1, 15,0);
        tracep->declBus(c+9,"main reg7", false,-1, 15,0);
        tracep->declBus(c+10,"main regS", false,-1, 15,0);
        tracep->declBus(c+11,"main regC", false,-1, 15,0);
        tracep->declBus(c+12,"main mux_out", false,-1, 15,0);
        tracep->declBus(c+13,"main sel", false,-1, 3,0);
        tracep->declBit(c+14,"main cout", false,-1);
        tracep->declBit(c+15,"main comp", false,-1);
        tracep->declBit(c+16,"main mode", false,-1);
        tracep->declBit(c+17,"main S_enable", false,-1);
        tracep->declBit(c+18,"main C_enable", false,-1);
        tracep->declBus(c+19,"main mux_sel", false,-1, 2,0);
        tracep->declBus(c+20,"main reg_enable", false,-1, 7,0);
        tracep->declBus(c+21,"main regCval", false,-1, 15,0);
        tracep->declBus(c+31,"main Inst d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Inst clk", false,-1);
        tracep->declBit(c+33,"main Inst en", false,-1);
        tracep->declBit(c+44,"main Inst reset", false,-1);
        tracep->declBus(c+1,"main Inst d_out", false,-1, 15,0);
        tracep->declBus(c+1,"main cu inst", false,-1, 15,0);
        tracep->declBit(c+32,"main cu clk", false,-1);
        tracep->declBit(c+33,"main cu reset", false,-1);
        tracep->declBus(c+13,"main cu sel", false,-1, 3,0);
        tracep->declBit(c+16,"main cu mode", false,-1);
        tracep->declBus(c+19,"main cu mux_sel", false,-1, 2,0);
        tracep->declBus(c+20,"main cu reg_enable", false,-1, 7,0);
        tracep->declBit(c+17,"main cu S_enable", false,-1);
        tracep->declBit(c+18,"main cu C_enable", false,-1);
        tracep->declBit(c+34,"main cu done", false,-1);
        tracep->declBus(c+22,"main cu state", false,-1, 2,0);
        tracep->declBus(c+2,"main mx reg0", false,-1, 15,0);
        tracep->declBus(c+3,"main mx reg1", false,-1, 15,0);
        tracep->declBus(c+4,"main mx reg2", false,-1, 15,0);
        tracep->declBus(c+5,"main mx reg3", false,-1, 15,0);
        tracep->declBus(c+6,"main mx reg4", false,-1, 15,0);
        tracep->declBus(c+7,"main mx reg5", false,-1, 15,0);
        tracep->declBus(c+8,"main mx reg6", false,-1, 15,0);
        tracep->declBus(c+9,"main mx reg7", false,-1, 15,0);
        tracep->declBus(c+19,"main mx mux_sel", false,-1, 2,0);
        tracep->declBus(c+12,"main mx out", false,-1, 15,0);
        tracep->declBus(c+12,"main RegS d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main RegS clk", false,-1);
        tracep->declBit(c+17,"main RegS en", false,-1);
        tracep->declBit(c+33,"main RegS reset", false,-1);
        tracep->declBus(c+10,"main RegS d_out", false,-1, 15,0);
        tracep->declBit(c+45,"main Alu carry_in", false,-1);
        tracep->declBus(c+10,"main Alu in_a", false,-1, 15,0);
        tracep->declBus(c+12,"main Alu in_b", false,-1, 15,0);
        tracep->declBus(c+13,"main Alu select", false,-1, 3,0);
        tracep->declBit(c+16,"main Alu mode", false,-1);
        tracep->declBit(c+14,"main Alu carry_out", false,-1);
        tracep->declBit(c+15,"main Alu compare", false,-1);
        tracep->declBus(c+21,"main Alu alu_out", false,-1, 15,0);
        tracep->declBus(c+21,"main Alu out", false,-1, 15,0);
        tracep->declBit(c+14,"main Alu cout", false,-1);
        tracep->declBus(c+21,"main RegC d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main RegC clk", false,-1);
        tracep->declBit(c+18,"main RegC en", false,-1);
        tracep->declBit(c+33,"main RegC reset", false,-1);
        tracep->declBus(c+11,"main RegC d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg0 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg0 clk", false,-1);
        tracep->declBit(c+33,"main Reg0 en", false,-1);
        tracep->declBit(c+23,"main Reg0 reset", false,-1);
        tracep->declBus(c+2,"main Reg0 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg1 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg1 clk", false,-1);
        tracep->declBit(c+33,"main Reg1 en", false,-1);
        tracep->declBit(c+24,"main Reg1 reset", false,-1);
        tracep->declBus(c+3,"main Reg1 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg2 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg2 clk", false,-1);
        tracep->declBit(c+33,"main Reg2 en", false,-1);
        tracep->declBit(c+25,"main Reg2 reset", false,-1);
        tracep->declBus(c+4,"main Reg2 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg3 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg3 clk", false,-1);
        tracep->declBit(c+33,"main Reg3 en", false,-1);
        tracep->declBit(c+26,"main Reg3 reset", false,-1);
        tracep->declBus(c+5,"main Reg3 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg4 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg4 clk", false,-1);
        tracep->declBit(c+33,"main Reg4 en", false,-1);
        tracep->declBit(c+27,"main Reg4 reset", false,-1);
        tracep->declBus(c+6,"main Reg4 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg5 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg5 clk", false,-1);
        tracep->declBit(c+33,"main Reg5 en", false,-1);
        tracep->declBit(c+28,"main Reg5 reset", false,-1);
        tracep->declBus(c+7,"main Reg5 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg6 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg6 clk", false,-1);
        tracep->declBit(c+33,"main Reg6 en", false,-1);
        tracep->declBit(c+29,"main Reg6 reset", false,-1);
        tracep->declBus(c+8,"main Reg6 d_out", false,-1, 15,0);
        tracep->declBus(c+11,"main Reg7 d_in", false,-1, 15,0);
        tracep->declBit(c+32,"main Reg7 clk", false,-1);
        tracep->declBit(c+33,"main Reg7 en", false,-1);
        tracep->declBit(c+30,"main Reg7 reset", false,-1);
        tracep->declBus(c+9,"main Reg7 d_out", false,-1, 15,0);
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
        tracep->fullSData(oldp+1,(vlTOPp->main__DOT__inst),16);
        tracep->fullSData(oldp+2,(vlTOPp->main__DOT__reg0),16);
        tracep->fullSData(oldp+3,(vlTOPp->main__DOT__reg1),16);
        tracep->fullSData(oldp+4,(vlTOPp->main__DOT__reg2),16);
        tracep->fullSData(oldp+5,(vlTOPp->main__DOT__reg3),16);
        tracep->fullSData(oldp+6,(vlTOPp->main__DOT__reg4),16);
        tracep->fullSData(oldp+7,(vlTOPp->main__DOT__reg5),16);
        tracep->fullSData(oldp+8,(vlTOPp->main__DOT__reg6),16);
        tracep->fullSData(oldp+9,(vlTOPp->main__DOT__reg7),16);
        tracep->fullSData(oldp+10,(vlTOPp->main__DOT__regS),16);
        tracep->fullSData(oldp+11,(vlTOPp->main__DOT__regC),16);
        tracep->fullSData(oldp+12,(vlTOPp->main__DOT__mux_out),16);
        tracep->fullCData(oldp+13,(vlTOPp->main__DOT__sel),4);
        tracep->fullBit(oldp+14,(vlTOPp->main__DOT__Alu__DOT__cout));
        tracep->fullBit(oldp+15,(((IData)(vlTOPp->main__DOT__regS) 
                                  == (IData)(vlTOPp->main__DOT__mux_out))));
        tracep->fullBit(oldp+16,(vlTOPp->main__DOT__mode));
        tracep->fullBit(oldp+17,(vlTOPp->main__DOT__S_enable));
        tracep->fullBit(oldp+18,(vlTOPp->main__DOT__C_enable));
        tracep->fullCData(oldp+19,(vlTOPp->main__DOT__mux_sel),3);
        tracep->fullCData(oldp+20,(vlTOPp->main__DOT__reg_enable),8);
        tracep->fullSData(oldp+21,(vlTOPp->main__DOT__Alu__DOT__out),16);
        tracep->fullCData(oldp+22,(vlTOPp->main__DOT__cu__DOT__state),3);
        tracep->fullBit(oldp+23,((1U & (IData)(vlTOPp->main__DOT__reg_enable))));
        tracep->fullBit(oldp+24,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 1U))));
        tracep->fullBit(oldp+25,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 2U))));
        tracep->fullBit(oldp+26,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 3U))));
        tracep->fullBit(oldp+27,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 4U))));
        tracep->fullBit(oldp+28,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 5U))));
        tracep->fullBit(oldp+29,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 6U))));
        tracep->fullBit(oldp+30,((1U & ((IData)(vlTOPp->main__DOT__reg_enable) 
                                        >> 7U))));
        tracep->fullSData(oldp+31,(vlTOPp->instruction),16);
        tracep->fullBit(oldp+32,(vlTOPp->clk));
        tracep->fullBit(oldp+33,(vlTOPp->reset));
        tracep->fullBit(oldp+34,(vlTOPp->done));
        tracep->fullSData(oldp+35,(vlTOPp->reg_0),16);
        tracep->fullSData(oldp+36,(vlTOPp->reg_1),16);
        tracep->fullSData(oldp+37,(vlTOPp->reg_2),16);
        tracep->fullSData(oldp+38,(vlTOPp->reg_3),16);
        tracep->fullSData(oldp+39,(vlTOPp->reg_4),16);
        tracep->fullSData(oldp+40,(vlTOPp->reg_5),16);
        tracep->fullSData(oldp+41,(vlTOPp->reg_6),16);
        tracep->fullSData(oldp+42,(vlTOPp->reg_7),16);
        tracep->fullSData(oldp+43,(vlTOPp->reg_C),16);
        tracep->fullBit(oldp+44,(1U));
        tracep->fullBit(oldp+45,(0U));
    }
}
