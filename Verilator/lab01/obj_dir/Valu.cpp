// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu.h"
#include "Valu__Syms.h"

//==========

void Valu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Valu::eval\n"); );
    Valu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("alu.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Valu::_eval_initial_loop(Valu__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("alu.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Valu::_combo__TOP__1(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_combo__TOP__1\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->compare = ((IData)(vlTOPp->in_a) == (IData)(vlTOPp->in_b));
    if ((4U & (IData)(vlTOPp->select))) {
        vlTOPp->carry_out = (1U & ((2U & (IData)(vlTOPp->select))
                                    ? ((1U & (IData)(vlTOPp->select))
                                        ? (1U & (((IData)(1U) 
                                                  + 
                                                  ((IData)(vlTOPp->in_a) 
                                                   + (IData)(vlTOPp->carry_in))) 
                                                 >> 0x10U))
                                        : (1U & ((((IData)(vlTOPp->in_a) 
                                                   + (IData)(vlTOPp->in_a)) 
                                                  + (IData)(vlTOPp->carry_in)) 
                                                 >> 0x10U)))
                                    : ((1U & (IData)(vlTOPp->select))
                                        ? (1U >= (0xffffU 
                                                  & ((IData)(vlTOPp->in_a) 
                                                     * 
                                                     (0xffffU 
                                                      & (~ (IData)(vlTOPp->in_b))))))
                                        : (1U >= (0xffffU 
                                                  & ((IData)(vlTOPp->in_a) 
                                                     * (IData)(vlTOPp->in_b)))))));
        vlTOPp->alu__DOT__alu_out1 = (0xffffU & ((2U 
                                                  & (IData)(vlTOPp->select))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((IData)(1U) 
                                                   + 
                                                   ((IData)(vlTOPp->in_a) 
                                                    + (IData)(vlTOPp->carry_in)))
                                                   : 
                                                  (((IData)(vlTOPp->in_a) 
                                                    + (IData)(vlTOPp->in_a)) 
                                                   + (IData)(vlTOPp->carry_in)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((IData)(0xffffU) 
                                                   + 
                                                   ((IData)(vlTOPp->in_a) 
                                                    * 
                                                    (0xffffU 
                                                     & (~ (IData)(vlTOPp->in_b)))))
                                                   : 
                                                  ((IData)(0xffffU) 
                                                   + 
                                                   ((IData)(vlTOPp->in_a) 
                                                    * (IData)(vlTOPp->in_b))))));
    } else {
        vlTOPp->carry_out = (1U & ((2U & (IData)(vlTOPp->select))
                                    ? ((1U & (IData)(vlTOPp->select))
                                        ? ((IData)(vlTOPp->in_a) 
                                           <= (0xffffU 
                                               & ((IData)(vlTOPp->in_b) 
                                                  + (IData)(vlTOPp->carry_in))))
                                        : (1U & ((((IData)(vlTOPp->in_a) 
                                                   + (IData)(vlTOPp->in_b)) 
                                                  + (IData)(vlTOPp->carry_in)) 
                                                 >> 0x10U)))
                                    : ((IData)(vlTOPp->select) 
                                       & (1U >= (IData)(vlTOPp->in_a)))));
        vlTOPp->alu__DOT__alu_out1 = (0xffffU & ((2U 
                                                  & (IData)(vlTOPp->select))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  (((IData)(vlTOPp->in_a) 
                                                    + 
                                                    (~ (IData)(vlTOPp->in_b))) 
                                                   + 
                                                   (1U 
                                                    & (~ (IData)(vlTOPp->carry_in))))
                                                   : 
                                                  (((IData)(vlTOPp->in_a) 
                                                    + (IData)(vlTOPp->in_b)) 
                                                   + (IData)(vlTOPp->carry_in)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->select))
                                                   ? 
                                                  ((IData)(0xfffeU) 
                                                   + 
                                                   ((IData)(vlTOPp->in_a) 
                                                    + 
                                                    (1U 
                                                     & (~ (IData)(vlTOPp->carry_in)))))
                                                   : 1U)));
    }
    vlTOPp->alu_out = (0xffffU & ((IData)(vlTOPp->mode)
                                   ? ((4U & (IData)(vlTOPp->select))
                                       ? ((2U & (IData)(vlTOPp->select))
                                           ? ((1U & (IData)(vlTOPp->select))
                                               ? (~ (IData)(vlTOPp->in_a))
                                               : ((IData)(vlTOPp->in_a) 
                                                  | (~ (IData)(vlTOPp->in_b))))
                                           : ((1U & (IData)(vlTOPp->select))
                                               ? ((IData)(vlTOPp->in_a) 
                                                  & (~ (IData)(vlTOPp->in_b)))
                                               : ((IData)(vlTOPp->in_a) 
                                                  ^ (IData)(vlTOPp->in_b))))
                                       : ((2U & (IData)(vlTOPp->select))
                                           ? ((1U & (IData)(vlTOPp->select))
                                               ? (~ 
                                                  ((IData)(vlTOPp->in_a) 
                                                   | (IData)(vlTOPp->in_b)))
                                               : ((IData)(vlTOPp->in_a) 
                                                  | (IData)(vlTOPp->in_b)))
                                           : ((1U & (IData)(vlTOPp->select))
                                               ? (~ 
                                                  ((IData)(vlTOPp->in_a) 
                                                   & (IData)(vlTOPp->in_b)))
                                               : ((IData)(vlTOPp->in_a) 
                                                  & (IData)(vlTOPp->in_b)))))
                                   : (IData)(vlTOPp->alu__DOT__alu_out1)));
}

void Valu::_eval(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Valu::_change_request(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_change_request\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Valu::_change_request_1(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_change_request_1\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Valu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((carry_in & 0xfeU))) {
        Verilated::overWidthError("carry_in");}
    if (VL_UNLIKELY((select & 0xf8U))) {
        Verilated::overWidthError("select");}
    if (VL_UNLIKELY((mode & 0xfeU))) {
        Verilated::overWidthError("mode");}
}
#endif  // VL_DEBUG
