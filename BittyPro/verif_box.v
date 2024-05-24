import "DPI-C" function void verification(input bit [15:0] alu_out, input bit [15:0] instruction);

module verif_box(
    input wire clk,
    input wire [15:0] alu_out,
    input wire [15:0] instruction,
    input wire C_enable
);

always @(posedge clk) begin
    if(C_enable) begin
        verification(alu_out, instruction);
    end
end

endmodule
