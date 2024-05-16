module controlunit (
	/* verilator lint_off UNUSED */
	input  reg [15:0]  inst,
	/* verilator lint_on UNUSED */
	input wire clk,
	input wire reset,
        output reg [3:0]  sel,
        output reg        mode,
        output reg [2:0]  mux_sel,
	output reg [7:0] reg_enable,
	output reg S_enable,
	output reg C_enable,
	output reg done
);
reg [2:0] state;

always @(posedge clk) begin 
	if(reset) begin 
		state <= 0;
		done <= 0;
	end else begin 
		case(state)
			0: begin
			        sel <= inst[5:2];
                                mode <= inst[1];	
				mux_sel <= inst[15:13];
				S_enable <= 1;
				reg_enable <= 0;
				C_enable <= 0;
				done <= 0;
				state <= 1;								
			end
			1: begin
				mux_sel <= inst[12:10];
				S_enable <= 0;
				reg_enable <= 0;
				C_enable <= 1;
				done <= 0;
				state <= 2;				
			end
			2: begin 
				reg_enable[inst[15:13]] <= 1;
				S_enable <= 0;
				C_enable <= 0;
				done <= 1;
				state <= 0;
			end
		endcase
	end
end
endmodule
