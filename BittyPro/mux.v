module mux(
    input wire [15:0] reg0,
    input wire [15:0] reg1,
    input wire [15:0] reg2,
    input wire [15:0] reg3,
    input wire [15:0] reg4,
    input wire [15:0] reg5,
    input wire [15:0] reg6,
    input wire [15:0] reg7,
    input wire [2:0]  mux_sel,
    output reg [15:0] out
);

always @(*) begin 
    case(mux_sel)
        3'd0: out = reg0;
        3'd1: out = reg1;
        3'd2: out = reg2;
        3'd3: out = reg3;
        3'd4: out = reg4;
        3'd5: out = reg5;
        3'd6: out = reg6;
        3'd7: out = reg7;
    endcase
end

endmodule
