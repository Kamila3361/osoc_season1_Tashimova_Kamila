module controlunit (
    /* verilator lint_off UNUSED */
    input  reg [15:0]  inst,
    /* verilator lint_on UNUSED */
    input wire clk,
    input wire reset,
    output reg [2:0] sel,
    output reg [2:0] mux_sel,
    output reg [7:0] reg_enable,
    output reg S_enable,
    output reg C_enable,
    output reg inst_enable,
    output reg done
);

reg [2:0] present_state = 0; // Initializing to known value
reg [2:0] next_state = 0;    // Initializing to known value

always @(*) begin
    case(present_state)
        0: next_state = 1;
        1: next_state = 2;
        2: next_state = 3;
        3: next_state = 0;
        default: next_state = 0; // Add default case for safety
    endcase
    if(reset) begin 
        next_state = 0;
    end
end

always @(posedge clk) begin 
    if(reset) begin 
        present_state <= 0;
    end else begin 
        present_state <= next_state;
    end
end

always @(*) begin 
    sel = 3'b000;           // Initialize outputs to known states
    mux_sel = 3'b000;
    reg_enable = 8'b0;
    S_enable = 0;
    C_enable = 0;
    done = 0;
    inst_enable = 0;
    if(!reset) begin
        case(present_state)
            0: begin 
                sel = inst[4:2];
                mux_sel = inst[15:13];
                S_enable = 1;
                inst_enable = 1;
            end
            1: begin
                sel = inst[4:2];
                mux_sel = inst[15:13];
                S_enable = 1;
            end
            2: begin
                sel = inst[4:2];
                mux_sel = inst[12:10];
                C_enable = 1;
            end             
            3: begin
                sel = inst[4:2];
                mux_sel = inst[12:10]; 
                reg_enable[inst[15:13]] = 1; // Ensure inst[15:13] is within 0-7
                done = 1;
            end
        endcase
    end
end

endmodule

