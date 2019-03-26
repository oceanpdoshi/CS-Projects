`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sagar Doshi - 604901376, Jamie Yang - 004979189
// 
// Create Date:    04:57:58 03/05/2019 
// Design Name: 
// Module Name:    jkff 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module jkff(
    input J,
    input K,
    input clk,
    input CLR,
    output Q
    );
	
	reg Qout = 0;
   
	always @(negedge clk, posedge CLR) begin
		if (CLR == 1)
			Qout = 0;
		else if (J == 0 && K == 0)
			Qout = Qout;
		else if (J == 0 && K == 1)
			Qout = 0;
		else if (J == 1 && K == 0)
			Qout = 1;
		else if (J == 1 && K == 1)
			Qout = ~Qout;
		
	end
	
	assign Q  = Qout;
  

endmodule
