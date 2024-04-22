module main(
	/* verilator lint_off UNUSED */
	input  reg [15:0] inst,
	/* verilator lint_on UNUSED */
	input  reg [15:0] reg0,
        input  reg [15:0] reg1,
        input  reg [15:0] reg2,
        input  reg [15:0] reg3,
        input  reg [15:0] reg4,
        input  reg [15:0] reg5,
        input  reg [15:0] reg6,
        input  reg [15:0] reg7,
	output reg [15:0] out,
	output reg        cout,
	output reg        comp
);
reg [3:0] sel;
reg mode;
reg [2:0] mux_sel1, mux_sel2;

controlunit unit1 (inst, 1'b1, sel, mode, mux_sel1);
controlunit unit2 (inst, 1'b0, sel, mode, mux_sel2);

reg [15:0] A, B;

always @(*) begin
        case(mux_sel1)
                3'd0: A = reg0;
                3'd1: A = reg1;
                3'd2: A = reg2;
                3'd3: A = reg3;
                3'd4: A = reg4;
                3'd5: A = reg5;
                3'd6: A = reg6;
                3'd7: A = reg7;
        endcase
end

always @(*) begin
        case(mux_sel2)
                3'd0: B = reg0;
                3'd1: B = reg1;
                3'd2: B = reg2;
                3'd3: B = reg3;
                3'd4: B = reg4;
                3'd5: B = reg5;
                3'd6: B = reg6;
                3'd7: B = reg7;
        endcase
end

alu alu1(.carry_in(1'b0), .in_a(A), .in_b(B), .select(sel), .mode(mode), .carry_out(cout), .compare(comp), .alu_out(out));

endmodule
