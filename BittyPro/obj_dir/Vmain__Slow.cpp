// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain.h"
#include "Vmain__Syms.h"

//==========

VL_CTOR_IMP(Vmain) {
    Vmain__Syms* __restrict vlSymsp = __VlSymsp = new Vmain__Syms(this, name());
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmain::__Vconfigure(Vmain__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmain::~Vmain() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vmain::_eval_initial(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_initial\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmain::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::final\n"); );
    // Variables
    Vmain__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmain::_eval_settle(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_settle\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vmain::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_ctor_var_reset\n"); );
    // Body
    inst = VL_RAND_RESET_I(16);
    reg0 = VL_RAND_RESET_I(16);
    reg1 = VL_RAND_RESET_I(16);
    reg2 = VL_RAND_RESET_I(16);
    reg3 = VL_RAND_RESET_I(16);
    reg4 = VL_RAND_RESET_I(16);
    reg5 = VL_RAND_RESET_I(16);
    reg6 = VL_RAND_RESET_I(16);
    reg7 = VL_RAND_RESET_I(16);
    out = VL_RAND_RESET_I(16);
    cout = VL_RAND_RESET_I(1);
    comp = VL_RAND_RESET_I(1);
    main__DOT__sel = VL_RAND_RESET_I(4);
    main__DOT__mode = VL_RAND_RESET_I(1);
    main__DOT__A = VL_RAND_RESET_I(16);
    main__DOT__B = VL_RAND_RESET_I(16);
    main__DOT__alu1__DOT__alu_out1 = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
