// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain.h"
#include "Vmain__Syms.h"

//==========

void Vmain::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmain::eval\n"); );
    Vmain__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("main.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmain::_eval_initial_loop(Vmain__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("main.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vmain::_sequent__TOP__1(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_sequent__TOP__1\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__main__DOT__cu__DOT__state;
    // Body
    __Vdly__main__DOT__cu__DOT__state = vlTOPp->main__DOT__cu__DOT__state;
    if (vlTOPp->reset) {
        vlTOPp->main__DOT__regS = 0U;
    } else {
        if (vlTOPp->main__DOT__S_enable) {
            vlTOPp->main__DOT__regS = vlTOPp->main__DOT__mux_out;
        }
    }
    if ((0x80U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg7 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg7 = vlTOPp->main__DOT__regC;
        }
    }
    if ((0x40U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg6 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg6 = vlTOPp->main__DOT__regC;
        }
    }
    if ((0x20U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg5 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg5 = vlTOPp->main__DOT__regC;
        }
    }
    if ((0x10U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg4 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg4 = vlTOPp->main__DOT__regC;
        }
    }
    if ((8U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg3 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg3 = vlTOPp->main__DOT__regC;
        }
    }
    if ((4U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg2 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg2 = vlTOPp->main__DOT__regC;
        }
    }
    if ((2U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg1 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg1 = vlTOPp->main__DOT__regC;
        }
    }
    if ((1U & (IData)(vlTOPp->main__DOT__reg_enable))) {
        vlTOPp->main__DOT__reg0 = 0U;
    } else {
        if (vlTOPp->reset) {
            vlTOPp->main__DOT__reg0 = vlTOPp->main__DOT__regC;
        }
    }
    vlTOPp->reg_7 = vlTOPp->main__DOT__reg7;
    vlTOPp->reg_6 = vlTOPp->main__DOT__reg6;
    vlTOPp->reg_5 = vlTOPp->main__DOT__reg5;
    vlTOPp->reg_4 = vlTOPp->main__DOT__reg4;
    vlTOPp->reg_3 = vlTOPp->main__DOT__reg3;
    vlTOPp->reg_2 = vlTOPp->main__DOT__reg2;
    vlTOPp->reg_1 = vlTOPp->main__DOT__reg1;
    vlTOPp->reg_0 = vlTOPp->main__DOT__reg0;
    if (vlTOPp->reset) {
        vlTOPp->main__DOT__regC = 0U;
    } else {
        if (vlTOPp->main__DOT__C_enable) {
            vlTOPp->main__DOT__regC = vlTOPp->main__DOT__Alu__DOT__out;
        }
    }
    vlTOPp->reg_C = vlTOPp->main__DOT__regC;
    if (vlTOPp->reset) {
        __Vdly__main__DOT__cu__DOT__state = 0U;
        vlTOPp->done = 0U;
    } else {
        if ((0U == (IData)(vlTOPp->main__DOT__cu__DOT__state))) {
            vlTOPp->main__DOT__sel = (0xfU & ((IData)(vlTOPp->main__DOT__inst) 
                                              >> 2U));
            vlTOPp->main__DOT__mode = (1U & ((IData)(vlTOPp->main__DOT__inst) 
                                             >> 1U));
            vlTOPp->main__DOT__mux_sel = (7U & ((IData)(vlTOPp->main__DOT__inst) 
                                                >> 0xdU));
            vlTOPp->main__DOT__S_enable = 1U;
            vlTOPp->main__DOT__reg_enable = 0U;
            vlTOPp->main__DOT__C_enable = 0U;
            __Vdly__main__DOT__cu__DOT__state = 1U;
        } else {
            if ((1U == (IData)(vlTOPp->main__DOT__cu__DOT__state))) {
                vlTOPp->main__DOT__mux_sel = (7U & 
                                              ((IData)(vlTOPp->main__DOT__inst) 
                                               >> 0xaU));
                vlTOPp->main__DOT__S_enable = 0U;
                vlTOPp->main__DOT__reg_enable = 0U;
                vlTOPp->main__DOT__C_enable = 1U;
                __Vdly__main__DOT__cu__DOT__state = 2U;
            } else {
                if ((2U == (IData)(vlTOPp->main__DOT__cu__DOT__state))) {
                    vlTOPp->main__DOT__reg_enable = 
                        ((IData)(vlTOPp->main__DOT__reg_enable) 
                         | ((IData)(1U) << (7U & ((IData)(vlTOPp->main__DOT__inst) 
                                                  >> 0xdU))));
                    vlTOPp->main__DOT__S_enable = 0U;
                    vlTOPp->main__DOT__C_enable = 0U;
                    vlTOPp->done = 1U;
                    __Vdly__main__DOT__cu__DOT__state = 0U;
                }
            }
        }
    }
    vlTOPp->main__DOT__cu__DOT__state = __Vdly__main__DOT__cu__DOT__state;
    vlTOPp->main__DOT__inst = 0U;
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

void Vmain::_eval(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vmain::_change_request(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_change_request\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vmain::_change_request_1(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_change_request_1\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmain::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
