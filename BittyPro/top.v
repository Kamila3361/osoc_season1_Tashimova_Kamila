module top(
    input clk,
    input reset
);

wire [15:0] instruction, address, pgcounter;
wire done;

Reg pc (pgcounter, clk, done, reset, address);

counter count (reset, done, address, pgcounter);

mem_instruction inst (reset, address[10:0], instruction);

bitty_processor processor (instruction, clk, reset, done);

endmodule
