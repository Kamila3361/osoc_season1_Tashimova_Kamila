module bitty_processor(
    /* verilator lint_off UNUSED */
    input wire [15:0] instruction,
    /* verilator lint_on UNUSED */
    input wire clk,
    input wire reset,	
    output wire done
);

wire [15:0] inst, reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, regS, regC, mux_out;
wire [2:0] sel;
wire S_enable, C_enable, inst_enable;
wire [2:0] mux_sel;
wire [7:0] reg_enable;
wire [15:0] regCval;

Reg Inst (instruction, clk, inst_enable, reset, inst);

controlunit cu (inst, clk, reset, sel, mux_sel, reg_enable, S_enable, C_enable, inst_enable, done);

mux mx (
    reg0,
    reg1,
    reg2,
    reg3,
    reg4,
    reg5,
    reg6,
    reg7,
    mux_sel,
    mux_out
);

Reg RegS (mux_out, clk, S_enable, reset, regS);

alu Alu (regS, mux_out, sel, regCval);
Reg RegC (regCval, clk, C_enable, reset, regC);

//Verification
verif_box verification(clk, regCval, inst, C_enable);

Reg Reg0 (regC, clk, reg_enable[0], reset, reg0);
Reg Reg1 (regC, clk, reg_enable[1], reset, reg1);
Reg Reg2 (regC, clk, reg_enable[2], reset, reg2);
Reg Reg3 (regC, clk, reg_enable[3], reset, reg3);
Reg Reg4 (regC, clk, reg_enable[4], reset, reg4);
Reg Reg5 (regC, clk, reg_enable[5], reset, reg5);
Reg Reg6 (regC, clk, reg_enable[6], reset, reg6);
Reg Reg7 (regC, clk, reg_enable[7], reset, reg7);

endmodule
