module controlunit (
	/* verilator lint_off UNUSED */
	input  reg [15:0]  inst,
	/* verilator lint_on UNUSED */
	input  reg         number,
        output wire [3:0]  sel,
        output wire        mode,
        output wire [2:0]  mux_sel
);
reg [2:0] mux_sel_reg;
always @(*) begin 
	if(number)
		mux_sel_reg = inst[15:13];
	else
		mux_sel_reg = inst[12:10];
end

assign sel = inst[5:2];
assign mode = inst[1];
assign mux_sel = mux_sel_reg;
endmodule
