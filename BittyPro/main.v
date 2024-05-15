module main(
	/* verilator lint_off UNUSED */
	input wire [15:0] instruction,
	/* verilator lint_on UNUSED */
	input wire clk,
	input wire reset,	
	output wire done,
	output wire [15:0] reg_0, reg_1, reg_2, reg_3, reg_4, reg_5, reg_6, reg_7, reg_C
);

wire [15:0] inst, reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, regS, regC, mux_out;
wire [3:0] sel;
/* verilator lint_off UNUSED */
wire cout, comp;
/* verilator lint_on UNUSED */
wire mode, S_enable, C_enable;
wire [2:0] mux_sel;
wire [7:0] reg_enable;

Reg Inst (instruction, clk, reset, 1'b1, inst);

controlunit cu (inst, clk, reset, sel, mode, mux_sel, reg_enable, S_enable, C_enable, done);

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

wire [15:0] regCval;
alu Alu (1'b0, regS, mux_out, sel, mode, cout, comp, regCval);
Reg RegC (regCval, clk, C_enable, reset, regC);

Reg Reg0 (regC, clk, reset, reg_enable[0], reg0);
Reg Reg1 (regC, clk, reset, reg_enable[1], reg1);
Reg Reg2 (regC, clk, reset, reg_enable[2], reg2);
Reg Reg3 (regC, clk, reset, reg_enable[3], reg3);
Reg Reg4 (regC, clk, reset, reg_enable[4], reg4);
Reg Reg5 (regC, clk, reset, reg_enable[5], reg5);
Reg Reg6 (regC, clk, reset, reg_enable[6], reg6);
Reg Reg7 (regC, clk, reset, reg_enable[7], reg7);

assign reg_0 = reg0;
assign reg_1 = reg1;
assign reg_2 = reg2;
assign reg_3 = reg3;
assign reg_4 = reg4;
assign reg_5 = reg5;
assign reg_6 = reg6;
assign reg_7 = reg7;
assign reg_C = regC;

endmodule
