module Logic(
        input  wire [15:0] in_a,
        input  wire [15:0] in_b,
        input  wire [2:0]  select,
        output reg  [15:0] alu_out
);
always @(*) begin
        case(select)
               3'd0: alu_out = in_a & in_b;
               3'd1: alu_out = ~(in_a & in_b);
               3'd2: alu_out = in_a | in_b;
               3'd3: alu_out = ~(in_a | in_b);
               3'd4: alu_out = in_a ^ in_b;
               3'd5: alu_out = in_a & ~in_b;
               3'd6: alu_out = in_a | ~in_b;
               3'd7: alu_out = ~in_a;
               default: alu_out = 0;
       endcase
end
endmodule 
