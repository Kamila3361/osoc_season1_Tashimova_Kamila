module alu (
    input  wire [15:0] in_a,
    input  wire [15:0] in_b,
    input  wire [2:0]  select,
    output wire [15:0] alu_out
);

reg [15:0] out;

always @(*) begin 
    out = 16'b0;
    case(select)
        3'b000: out = in_a + in_b;  
        3'b001: out = in_a - in_b;    
        3'b010: out = in_a & in_b;
        3'b011: out = in_a | in_b;
        3'b100: out = in_a ^ in_b;
        3'b101: out = in_a << in_b[3:0];
        3'b110: out = in_a >> in_b[3:0];
        3'b111: out = (in_a == in_b) ? 16'b0 : (in_a > in_b) ? 16'b1 : 16'b10;
        default: out = 16'b0;
    endcase		
end

assign alu_out = out;

endmodule
