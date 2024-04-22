module alu (
        input  wire        carry_in,
        input  wire [15:0] in_a,
        input  wire [15:0] in_b,
        input  wire [3:0]  select,
        input  wire        mode,
        output wire        carry_out,
        output wire        compare,
        output wire [15:0] alu_out
);
reg [15:0] alu_out1, alu_out2;
Arithmetic arith(carry_in, in_a, in_b, select, carry_out, compare, alu_out1);
Logic log (in_a, in_b, select, alu_out2);

assign alu_out = (mode) ? alu_out2 : alu_out1;
endmodule

