module Arithmetic (
        input  wire        carry_in,
        input  wire [15:0] in_a,
        input  wire [15:0] in_b,
        input  wire [3:0]  select,
        output reg         carry_out,
        output wire        compare,
        output reg  [15:0] alu_out
);
always @(*) begin
       case(select)
               4'd0: begin
                       alu_out = 1;
                       carry_out = 0;
               end
               4'd1: begin
                       alu_out = in_a + (~16'b1) + ({15'b0, ~carry_in});
                       carry_out = (in_a > 16'b1) ? 1'b0 : 1'b1;
               end
               4'd2: begin
                       {carry_out, alu_out} = in_a + in_b + ({16'b0, carry_in});
               end
               4'd3: begin
                       alu_out = in_a + (~in_b) + ({15'b0, ~carry_in});
                       carry_out = (in_a > (in_b + ({15'b0, carry_in}))) ? 1'b0 : 1'b1;
               end
               4'd4: begin
                       alu_out = (in_a * in_b) + (~16'b1 + 1'b1);
                       carry_out = ((in_a * in_b) > 16'b1) ? 1'b0 : 1'b1;
               end
               4'd5: begin
                       alu_out = (in_a * ~in_b) + (~16'b1 + 1'b1);
                       carry_out = ((in_a * ~in_b) > 16'b1) ? 1'b0 : 1'b1;
               end
               4'd6: begin
                       {carry_out, alu_out} = in_a + in_a + ({16'b0, carry_in});
               end
               4'd7: begin
                       {carry_out, alu_out} = in_a + 1'b1 + ({16'b0, carry_in});
               end
               default: begin
                       alu_out = 0;
                       carry_out = 0;
               end
       endcase
end
assign compare = (in_a == in_b) ? 1'b1 : 1'b0;
endmodule

