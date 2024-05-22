`define PATH_TO_INST "./instructions.txt"

module mem_instruction(
    input reset,
    input [10:0] address,
    output [15:0] instruction
);

reg [15:0] mem [1024:0];
reg [15:0] data;

always @(*) begin
    if (reset) begin
        $readmemh(`PATH_TO_INST, mem);
        data = 0;
    end else begin
        data = mem[address];
    end
end

assign instruction = data;

endmodule
