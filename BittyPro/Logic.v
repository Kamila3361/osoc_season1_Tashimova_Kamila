module Logic(
        input  wire [15:0] in_a,
        input  wire [15:0] in_b,
        input  wire [3:0]  select,
        output reg  [15:0] alu_out
);
always @(*) begin
        case(select)
               4'd0: alu_out = in_a & in_b;
               4'd1: alu_out = ~(in_a & in_b);
               4'd2: alu_out = in_a | in_b;
               4'd3: alu_out = ~(in_a | in_b);
               4'd4: alu_out = in_a ^ in_b;
               4'd5: alu_out = in_a & ~in_b;
               4'd6: alu_out = in_a | ~in_b;
               4'd7: alu_out = ~in_a;
               default: alu_out = 0;
       endcase
end
endmodule 
