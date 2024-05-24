module counter(
    input reset,
    input enable,
    input [15:0] address,
    output [15:0] new_address 
);

reg [15:0] counter;

always @(*) begin 
    if (reset) 
        counter = 0;
    else if (enable) 
        counter = address + 1;
end

assign new_address = counter;

endmodule
