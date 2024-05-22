module top(
    input clk,
    input reset
);

wire [10:0] address;
wire [15:0] instruction;
wire done;

counter count (clk, reset, done, address);

mem_instruction inst (reset, address, instruction);

BittyProcessor processor (instruction, clk, reset, done);

endmodule
