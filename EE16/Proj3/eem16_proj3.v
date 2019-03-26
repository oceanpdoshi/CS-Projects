`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sagar Doshi 604901376, Jamie Yang 004979189
// 
// Create Date:    03:44:48 03/07/2019 
// Design Name: 
// Module Name:    eem16_proj3 
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
module eem16_proj3(
    input x1,
    input x0,
    input r,
    input clk,
    output z1,
    output z0
    );
		
		// Present state (connected to JK flip-flops)
		wire Q1;
		wire Q0;
		
		// Inputs to JK flip-flop
		reg J1;
		reg K1;
		reg J0;
		reg K0;

		
		// Instantiate the JK Flip-Flops with the appropriate connections.
		jkff JK1 (
				.J(J1), 
				.K(K1), 
				.clk(clk), 
				.CLR(r), 
				.Q(Q1)
			);
		
		jkff JK0 (
				.J(J0), 
				.K(K0), 
				.clk(clk), 
				.CLR(r), 
				.Q(Q0)
			);	
	
		
	
	always @(posedge clk) begin
		begin
			J1 = (Q0 || x1) && (~r) && (x0);
			K1 = (~Q0 || x1 || r) && (x0 || r);
			
			J0 = (x0) && ~r && ~Q1;
			K0 = (Q1 || x1 || r) && (x0 || r);
		end
	end
	
	// For now we're just testing to see if our states are correct
	assign z1 = Q1 && x0 && ~r && (~Q0 || x1);
	assign z0 = Q1 && ~Q0 && x1 && ~r;
	
endmodule
