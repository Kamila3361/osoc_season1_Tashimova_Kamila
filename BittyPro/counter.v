module counter(
    input clk,
    input reset,
    input enable,
    output [10:0] new_address 
);

reg [10:0] counter;

always @(posedge clk) begin 
    if (reset) 
        counter <= 0;
    else if (enable) 
        counter <= counter + 1;
end

assign new_address = counter;

endmodule
