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

VL_INLINE_OPT void Vmain::_combo__TOP__1(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_combo__TOP__1\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->main__DOT__mode = (1U & ((IData)(vlTOPp->inst) 
                                     >> 1U));
    vlTOPp->main__DOT__sel = (0xfU & ((IData)(vlTOPp->inst) 
                                      >> 2U));
    vlTOPp->main__DOT__A = ((0x8000U & (IData)(vlTOPp->inst))
                             ? ((0x4000U & (IData)(vlTOPp->inst))
                                 ? ((0x2000U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg7)
                                     : (IData)(vlTOPp->reg6))
                                 : ((0x2000U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg5)
                                     : (IData)(vlTOPp->reg4)))
                             : ((0x4000U & (IData)(vlTOPp->inst))
                                 ? ((0x2000U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg3)
                                     : (IData)(vlTOPp->reg2))
                                 : ((0x2000U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg1)
                                     : (IData)(vlTOPp->reg0))));
    vlTOPp->main__DOT__B = ((0x1000U & (IData)(vlTOPp->inst))
                             ? ((0x800U & (IData)(vlTOPp->inst))
                                 ? ((0x400U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg7)
                                     : (IData)(vlTOPp->reg6))
                                 : ((0x400U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg5)
                                     : (IData)(vlTOPp->reg4)))
                             : ((0x800U & (IData)(vlTOPp->inst))
                                 ? ((0x400U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg3)
                                     : (IData)(vlTOPp->reg2))
                                 : ((0x400U & (IData)(vlTOPp->inst))
                                     ? (IData)(vlTOPp->reg1)
                                     : (IData)(vlTOPp->reg0))));
    vlTOPp->comp = ((IData)(vlTOPp->main__DOT__A) == (IData)(vlTOPp->main__DOT__B));
    vlTOPp->cout = (1U & ((~ ((IData)(vlTOPp->main__DOT__sel) 
                              >> 3U)) & ((4U & (IData)(vlTOPp->main__DOT__sel))
                                          ? ((2U & (IData)(vlTOPp->main__DOT__sel))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->main__DOT__sel))
                                                  ? 
                                                 (1U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlTOPp->main__DOT__A)) 
                                                     >> 0x10U))
                                                  : 
                                                 (1U 
                                                  & (((IData)(vlTOPp->main__DOT__A) 
                                                      + (IData)(vlTOPp->main__DOT__A)) 
                                                     >> 0x10U)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->main__DOT__sel))
                                                  ? 
                                                 (1U 
                                                  >= 
                                                  (0xffffU 
                                                   & ((IData)(vlTOPp->main__DOT__A) 
                                                      * 
                                                      (0xffffU 
                                                       & (~ (IData)(vlTOPp->main__DOT__B))))))
                                                  : 
                                                 (1U 
                                                  >= 
                                                  (0xffffU 
                                                   & ((IData)(vlTOPp->main__DOT__A) 
                                                      * (IData)(vlTOPp->main__DOT__B))))))
                                          : ((2U & (IData)(vlTOPp->main__DOT__sel))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->main__DOT__sel))
                                                  ? 
                                                 ((IData)(vlTOPp->main__DOT__A) 
                                                  <= (IData)(vlTOPp->main__DOT__B))
                                                  : 
                                                 (1U 
                                                  & (((IData)(vlTOPp->main__DOT__A) 
                                                      + (IData)(vlTOPp->main__DOT__B)) 
                                                     >> 0x10U)))
                                              : ((IData)(vlTOPp->main__DOT__sel) 
                                                 & (1U 
                                                    >= (IData)(vlTOPp->main__DOT__A)))))));
    vlTOPp->main__DOT__alu1__DOT__alu_out1 = ((8U & (IData)(vlTOPp->main__DOT__sel))
                                               ? 0U
                                               : (0xffffU 
                                                  & ((4U 
                                                      & (IData)(vlTOPp->main__DOT__sel))
                                                      ? 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(1U) 
                                                        + (IData)(vlTOPp->main__DOT__A))
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__A) 
                                                        + (IData)(vlTOPp->main__DOT__A)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(0xffffU) 
                                                        + 
                                                        ((IData)(vlTOPp->main__DOT__A) 
                                                         * 
                                                         (0xffffU 
                                                          & (~ (IData)(vlTOPp->main__DOT__B)))))
                                                        : 
                                                       ((IData)(0xffffU) 
                                                        + 
                                                        ((IData)(vlTOPp->main__DOT__A) 
                                                         * (IData)(vlTOPp->main__DOT__B)))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlTOPp->main__DOT__sel))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(1U) 
                                                        + 
                                                        ((IData)(vlTOPp->main__DOT__A) 
                                                         + 
                                                         (~ (IData)(vlTOPp->main__DOT__B))))
                                                        : 
                                                       ((IData)(vlTOPp->main__DOT__A) 
                                                        + (IData)(vlTOPp->main__DOT__B)))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlTOPp->main__DOT__sel))
                                                        ? 
                                                       ((IData)(0xffffU) 
                                                        + (IData)(vlTOPp->main__DOT__A))
                                                        : 1U)))));
    vlTOPp->out = (0xffffU & ((IData)(vlTOPp->main__DOT__mode)
                               ? ((8U & (IData)(vlTOPp->main__DOT__sel))
                                   ? 0U : ((4U & (IData)(vlTOPp->main__DOT__sel))
                                            ? ((2U 
                                                & (IData)(vlTOPp->main__DOT__sel))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   (~ (IData)(vlTOPp->main__DOT__A))
                                                    : 
                                                   ((IData)(vlTOPp->main__DOT__A) 
                                                    | (~ (IData)(vlTOPp->main__DOT__B))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   ((IData)(vlTOPp->main__DOT__A) 
                                                    & (~ (IData)(vlTOPp->main__DOT__B)))
                                                    : 
                                                   ((IData)(vlTOPp->main__DOT__A) 
                                                    ^ (IData)(vlTOPp->main__DOT__B))))
                                            : ((2U 
                                                & (IData)(vlTOPp->main__DOT__sel))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     | (IData)(vlTOPp->main__DOT__B)))
                                                    : 
                                                   ((IData)(vlTOPp->main__DOT__A) 
                                                    | (IData)(vlTOPp->main__DOT__B)))
                                                : (
                                                   (1U 
                                                    & (IData)(vlTOPp->main__DOT__sel))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlTOPp->main__DOT__A) 
                                                     & (IData)(vlTOPp->main__DOT__B)))
                                                    : 
                                                   ((IData)(vlTOPp->main__DOT__A) 
                                                    & (IData)(vlTOPp->main__DOT__B))))))
                               : (IData)(vlTOPp->main__DOT__alu1__DOT__alu_out1)));
}

void Vmain::_eval(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
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
}
#endif  // VL_DEBUG
