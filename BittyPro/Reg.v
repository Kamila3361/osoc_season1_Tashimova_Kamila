module Reg(
	input  wire [15:0] d_in,
	input  wire        clk,
	input  wire        en,
	input wire reset,
	output reg  [15:0] d_out
);

always @(posedge clk) begin 
	if (reset)
            d_out <= 16'd0;
        else if (en)
            d_out <= d_in;
end
endmodule
