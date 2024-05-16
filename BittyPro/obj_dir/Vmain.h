// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMAIN_H_
#define _VMAIN_H_  // guard

#include "verilated.h"

//==========

class Vmain__Syms;
class Vmain_VerilatedVcd;


//----------

VL_MODULE(Vmain) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(done,0,0);
    VL_IN16(instruction,15,0);
    VL_OUT16(reg_0,15,0);
    VL_OUT16(reg_1,15,0);
    VL_OUT16(reg_2,15,0);
    VL_OUT16(reg_3,15,0);
    VL_OUT16(reg_4,15,0);
    VL_OUT16(reg_5,15,0);
    VL_OUT16(reg_6,15,0);
    VL_OUT16(reg_7,15,0);
    VL_OUT16(reg_C,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ main__DOT__sel;
    CData/*0:0*/ main__DOT__mode;
    CData/*0:0*/ main__DOT__S_enable;
    CData/*0:0*/ main__DOT__C_enable;
    CData/*2:0*/ main__DOT__mux_sel;
    CData/*7:0*/ main__DOT__reg_enable;
    CData/*2:0*/ main__DOT__cu__DOT__state;
    CData/*0:0*/ main__DOT__Alu__DOT__cout;
    SData/*15:0*/ main__DOT__inst;
    SData/*15:0*/ main__DOT__reg0;
    SData/*15:0*/ main__DOT__reg1;
    SData/*15:0*/ main__DOT__reg2;
    SData/*15:0*/ main__DOT__reg3;
    SData/*15:0*/ main__DOT__reg4;
    SData/*15:0*/ main__DOT__reg5;
    SData/*15:0*/ main__DOT__reg6;
    SData/*15:0*/ main__DOT__reg7;
    SData/*15:0*/ main__DOT__regS;
    SData/*15:0*/ main__DOT__regC;
    SData/*15:0*/ main__DOT__mux_out;
    SData/*15:0*/ main__DOT__Alu__DOT__out;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmain__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmain);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmain(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmain();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmain__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmain__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmain__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vmain__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmain__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vmain__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vmain__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
