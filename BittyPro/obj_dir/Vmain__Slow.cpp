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

void Vmain::_settle__TOP__2(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_settle__TOP__2\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->reg_0 = vlTOPp->main__DOT__reg0;
    vlTOPp->reg_1 = vlTOPp->main__DOT__reg1;
    vlTOPp->reg_2 = vlTOPp->main__DOT__reg2;
    vlTOPp->reg_3 = vlTOPp->main__DOT__reg3;
    vlTOPp->reg_4 = vlTOPp->main__DOT__reg4;
    vlTOPp->reg_5 = vlTOPp->main__DOT__reg5;
    vlTOPp->reg_6 = vlTOPp->main__DOT__reg6;
    vlTOPp->reg_7 = vlTOPp->main__DOT__reg7;
    vlTOPp->reg_C = vlTOPp->main__DOT__regC;
    vlTOPp->main__DOT__mux_out = ((4U & (IData)(vlTOPp->main__DOT__mux_sel))
                                   ? ((2U & (IData)(vlTOPp->main__DOT__mux_sel))
                                       ? ((1U & (IData)(vlTOPp->main__DOT__mux_sel))
                                           ? (IData)(vlTOPp->main__DOT__reg7)
                                           : (IData)(vlTOPp->main__DOT__reg6))
                                       : ((1U & (IData)(vlTOPp->main__DOT__mux_sel))
                                           ? (IData)(vlTOPp->main__DOT__reg5)
                                           : (IData)(vlTOPp->main__DOT__reg4)))
                                   : ((2U & (IData)(vlTOPp->main__DOT__mux_sel))
                                       ? ((1U & (IData)(vlTOPp->main__DOT__mux_sel))
                                           ? (IData)(vlTOPp->main__DOT__reg3)
                                           : (IData)(vlTOPp->main__DOT__reg2))
                                       : ((1U & (IData)(vlTOPp->main__DOT__mux_sel))
                                           ? (IData)(vlTOPp->main__DOT__reg1)
                                           : (IData)(vlTOPp->main__DOT__reg0))));
    if ((1U & (~ (IData)(vlTOPp->main__DOT__mode)))) {
        vlTOPp->main__DOT__Alu__DOT__cout = (1U & (
                                                   (8U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (1U 
                                                       & (((IData)(vlTOPp->main__DOT__regS) 
                                                           - (IData)(1U)) 
                                                          >> 0x10U))
                                                       : 
                                                      (1U 
                                                       & ((((IData)(vlTOPp->main__DOT__regS) 
                                                            & (~ (IData)(vlTOPp->main__DOT__mux_out))) 
                                                           + (IData)(vlTOPp->main__DOT__regS)) 
                                                          >> 0x10U)))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (1U 
                                                       & ((((IData)(vlTOPp->main__DOT__regS) 
                                                            & (IData)(vlTOPp->main__DOT__mux_out)) 
                                                           + (IData)(vlTOPp->main__DOT__regS)) 
                                                          >> 0x10U))
                                                       : 
                                                      (1U 
                                                       & (((IData)(vlTOPp->main__DOT__regS) 
                                                           + (IData)(vlTOPp->main__DOT__regS)) 
                                                          >> 0x10U))))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (1U 
                                                       & ((((IData)(vlTOPp->main__DOT__regS) 
                                                            | (IData)(vlTOPp->main__DOT__mux_out)) 
                                                           - (IData)(1U)) 
                                                          >> 0x10U))
                                                       : 
                                                      (1U 
                                                       & ((((IData)(vlTOPp->main__DOT__regS) 
                                                            & (~ (IData)(vlTOPp->main__DOT__mux_out))) 
                                                           + 
                                                           ((IData)(vlTOPp->main__DOT__regS) 
                                                            | (IData)(vlTOPp->main__DOT__mux_out))) 
                                                          >> 0x10U)))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (1U 
                                                       & (((IData)(vlTOPp->main__DOT__regS) 
                                                           + (IData)(vlTOPp->main__DOT__mux_out)) 
                                                          >> 0x10U))
                                                       : 
                                                      (1U 
                                                       & (((IData)(vlTOPp->main__DOT__regS) 
                                                           + 
                                                           ((IData)(vlTOPp->main__DOT__regS) 
                                                            | (IData)(vlTOPp->main__DOT__mux_out))) 
                                                          >> 0x10U)))))
                                                    : 
                                                   ((4U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (1U 
                                                       & (((0xffffU 
                                                            & ((IData)(vlTOPp->main__DOT__regS) 
                                                               | (~ (IData)(vlTOPp->main__DOT__mux_out)))) 
                                                           - (IData)(1U)) 
                                                          >> 0x10U))
                                                       : 
                                                      (1U 
                                                       & ((((IData)(vlTOPp->main__DOT__regS) 
                                                            - (IData)(vlTOPp->main__DOT__mux_out)) 
                                                           - (IData)(1U)) 
                                                          >> 0x10U)))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (1U 
                                                       & ((((IData)(vlTOPp->main__DOT__regS) 
                                                            & (IData)(vlTOPp->main__DOT__mux_out)) 
                                                           + 
                                                           (0xffffU 
                                                            & ((IData)(vlTOPp->main__DOT__regS) 
                                                               | (~ (IData)(vlTOPp->main__DOT__mux_out))))) 
                                                          >> 0x10U))
                                                       : 
                                                      (((IData)(vlTOPp->main__DOT__regS) 
                                                        & ((IData)(vlTOPp->main__DOT__regS) 
                                                           | (~ (IData)(vlTOPp->main__DOT__mux_out)))) 
                                                       >> 0x10U)))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((IData)(vlTOPp->main__DOT__sel) 
                                                      | (((IData)(vlTOPp->main__DOT__regS) 
                                                          & (~ (IData)(vlTOPp->main__DOT__mux_out))) 
                                                         >> 0x10U))
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      (((IData)(vlTOPp->main__DOT__regS) 
                                                        & (IData)(vlTOPp->main__DOT__mux_out)) 
                                                       >> 0x10U)
                                                       : 
                                                      ((IData)(vlTOPp->main__DOT__regS) 
                                                       >> 0x10U))))));
    }
    vlTOPp->main__DOT__Alu__DOT__out = (0xffffU & ((IData)(vlTOPp->main__DOT__mode)
                                                    ? 
                                                   ((8U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? (IData)(vlTOPp->main__DOT__regS)
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        & (IData)(vlTOPp->main__DOT__mux_out)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        & (~ (IData)(vlTOPp->main__DOT__mux_out)))
                                                        : 0xffffU))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        | (IData)(vlTOPp->main__DOT__mux_out))
                                                        : (IData)(vlTOPp->main__DOT__mux_out))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (~ 
                                                        ((IData)(vlTOPp->main__DOT__regS) 
                                                         ^ (IData)(vlTOPp->main__DOT__mux_out)))
                                                        : 
                                                       ((~ (IData)(vlTOPp->main__DOT__regS)) 
                                                        & (IData)(vlTOPp->main__DOT__mux_out)))))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        | (~ (IData)(vlTOPp->main__DOT__mux_out)))
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        ^ (IData)(vlTOPp->main__DOT__mux_out)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (~ (IData)(vlTOPp->main__DOT__mux_out))
                                                        : 
                                                       (~ 
                                                        ((IData)(vlTOPp->main__DOT__regS) 
                                                         | (IData)(vlTOPp->main__DOT__mux_out)))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 0U
                                                        : 
                                                       ((~ (IData)(vlTOPp->main__DOT__regS)) 
                                                        | (IData)(vlTOPp->main__DOT__mux_out)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (~ 
                                                        ((IData)(vlTOPp->main__DOT__regS) 
                                                         & (IData)(vlTOPp->main__DOT__mux_out)))
                                                        : 
                                                       (~ (IData)(vlTOPp->main__DOT__regS))))))
                                                    : 
                                                   ((8U 
                                                     & (IData)(vlTOPp->main__DOT__sel))
                                                     ? 
                                                    ((4U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        - (IData)(1U))
                                                        : 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         & (~ (IData)(vlTOPp->main__DOT__mux_out))) 
                                                        + (IData)(vlTOPp->main__DOT__regS)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         & (IData)(vlTOPp->main__DOT__mux_out)) 
                                                        + (IData)(vlTOPp->main__DOT__regS))
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        + (IData)(vlTOPp->main__DOT__regS))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         | (IData)(vlTOPp->main__DOT__mux_out)) 
                                                        - (IData)(1U))
                                                        : 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         & (~ (IData)(vlTOPp->main__DOT__mux_out))) 
                                                        + 
                                                        ((IData)(vlTOPp->main__DOT__regS) 
                                                         | (IData)(vlTOPp->main__DOT__mux_out))))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        + (IData)(vlTOPp->main__DOT__mux_out))
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        + 
                                                        ((IData)(vlTOPp->main__DOT__regS) 
                                                         | (IData)(vlTOPp->main__DOT__mux_out))))))
                                                     : 
                                                    ((4U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         | (~ (IData)(vlTOPp->main__DOT__mux_out))) 
                                                        - (IData)(1U))
                                                        : 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         - (IData)(vlTOPp->main__DOT__mux_out)) 
                                                        - (IData)(1U)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       (((IData)(vlTOPp->main__DOT__regS) 
                                                         & (IData)(vlTOPp->main__DOT__mux_out)) 
                                                        + 
                                                        ((IData)(vlTOPp->main__DOT__regS) 
                                                         | (~ (IData)(vlTOPp->main__DOT__mux_out))))
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        & ((IData)(vlTOPp->main__DOT__regS) 
                                                           | (~ (IData)(vlTOPp->main__DOT__mux_out))))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 0xffffU
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        & (~ (IData)(vlTOPp->main__DOT__mux_out))))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(vlTOPp->main__DOT__regS) 
                                                        & (IData)(vlTOPp->main__DOT__mux_out))
                                                        : (IData)(vlTOPp->main__DOT__regS)))))));
}

void Vmain::_eval_initial(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_initial\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
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
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vmain::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_ctor_var_reset\n"); );
    // Body
    instruction = VL_RAND_RESET_I(16);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    reg_0 = VL_RAND_RESET_I(16);
    reg_1 = VL_RAND_RESET_I(16);
    reg_2 = VL_RAND_RESET_I(16);
    reg_3 = VL_RAND_RESET_I(16);
    reg_4 = VL_RAND_RESET_I(16);
    reg_5 = VL_RAND_RESET_I(16);
    reg_6 = VL_RAND_RESET_I(16);
    reg_7 = VL_RAND_RESET_I(16);
    reg_C = VL_RAND_RESET_I(16);
    main__DOT__inst = VL_RAND_RESET_I(16);
    main__DOT__reg0 = VL_RAND_RESET_I(16);
    main__DOT__reg1 = VL_RAND_RESET_I(16);
    main__DOT__reg2 = VL_RAND_RESET_I(16);
    main__DOT__reg3 = VL_RAND_RESET_I(16);
    main__DOT__reg4 = VL_RAND_RESET_I(16);
    main__DOT__reg5 = VL_RAND_RESET_I(16);
    main__DOT__reg6 = VL_RAND_RESET_I(16);
    main__DOT__reg7 = VL_RAND_RESET_I(16);
    main__DOT__regS = VL_RAND_RESET_I(16);
    main__DOT__regC = VL_RAND_RESET_I(16);
    main__DOT__mux_out = VL_RAND_RESET_I(16);
    main__DOT__sel = VL_RAND_RESET_I(4);
    main__DOT__mode = VL_RAND_RESET_I(1);
    main__DOT__S_enable = VL_RAND_RESET_I(1);
    main__DOT__C_enable = VL_RAND_RESET_I(1);
    main__DOT__mux_sel = VL_RAND_RESET_I(3);
    main__DOT__reg_enable = VL_RAND_RESET_I(8);
    main__DOT__cu__DOT__state = VL_RAND_RESET_I(3);
    main__DOT__Alu__DOT__out = VL_RAND_RESET_I(16);
    main__DOT__Alu__DOT__cout = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
