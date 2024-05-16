module alu (
        input  wire        carry_in,
        input  wire [15:0] in_a,
        input  wire [15:0] in_b,
        input  wire [3:0]  select,
        input  wire        mode,
        output wire        carry_out,
        output wire        compare,
        output wire [15:0] alu_out
);

reg [15:0] out;
reg cout;

always @(*) begin 
	case({mode, select})
		5'b10000: out = ~in_a;         
        	5'b10001: out = ~(in_a & in_b);                            
        	5'b10010: out = ~(in_a) | in_b;                            
        	5'b10011: out = 16'b0000000000000000;
        	5'b10100: out = ~(in_a | in_b);                              
        	5'b10101: out = ~in_b;                                  
        	5'b10110: out = in_a ^ in_b;                               
        	5'b10111: out = in_a | ~(in_b);                            
        	5'b11000: out = ~in_a & in_b;                              
        	5'b11001: out = ~(in_a ^ in_b);                              
        	5'b11010: out = in_b;                                   
        	5'b11011: out = in_a | in_b;                              
        	5'b11100: out = 16'b1111111111111111;                                   
        	5'b11101: out = in_a & ~in_b;                               
        	5'b11110: out = in_a & in_b;                             
        	5'b11111: out = in_a;

		5'b00000: {cout, out} = {1'b0, in_a} + {16'd0, carry_in};
                5'b00001: {cout, out} = {1'b0, (in_a & in_b)} + {16'b0, carry_in};
                5'b00010: {cout, out} = {1'b0, (in_a & ~in_b)} + {16'b0, carry_in};
                5'b00011: {cout, out} = -1 + ({15'b0, carry_in});
                5'b00100: {cout, out} = {1'b0, (in_a & (in_a | ~in_b))} + {16'b0, carry_in};
                5'b00101: {cout, out} = {1'b0, (in_a & in_b)} + {1'b0, (in_a | ~in_b)} + {16'b0, carry_in};
                5'b00110: {cout, out} = {1'b0, in_a} - {1'b0, in_b} - 17'd1 + {16'b0, carry_in};
                5'b00111: {cout, out} = {1'b0, (in_a | ~(in_b))} - 17'd1 + {16'b0, carry_in};
                5'b01000: {cout, out} = {1'b0, in_a} + {1'b0, (in_a | in_b)} + ({16'b0, carry_in});
                5'b01001: {cout, out} = {1'b0, in_a} + {1'b0, in_b} + ({16'b0, carry_in});
                5'b01010: {cout, out} = {1'b0, (in_a & ~in_b)} + {1'b0, (in_a | in_b)} + ({16'b0, carry_in});
                5'b01011: {cout, out} = {1'b0, (in_a | in_b)} - 17'd1 + ({16'b0, carry_in});
                5'b01100: {cout, out} = {1'b0, in_a} + {1'b0, in_a} + ({16'b0, carry_in});
                5'b01101: {cout, out} = {1'b0, (in_a & in_b)} + {1'b0, in_a} + ({16'b0, carry_in});
                5'b01110: {cout, out} = {1'b0, (in_a & ~in_b)} + {1'b0, in_a} + ({16'b0, carry_in});
                5'b01111: {cout, out} = {1'b0, in_a} - 17'd1 + ({16'b0, carry_in});
	endcase		
end

assign alu_out = out;
assign carry_out = cout;
assign compare = (in_a == in_b) ? 1'b1 : 1'b0;

endmodule
