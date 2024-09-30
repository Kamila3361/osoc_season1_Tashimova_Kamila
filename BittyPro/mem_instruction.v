`define PATH_TO_INST "./instructions.txt"

module mem_instruction(
    input [10:0] address,
    output [15:0] instruction
);

reg [15:0] mem [1024:0];
reg [15:0] data;

initial begin
    $readmemh(`PATH_TO_INST, mem); // Load memory contents from the file
end

always @(*) begin
    data = mem[address];
end

assign instruction = data;

endmodule
