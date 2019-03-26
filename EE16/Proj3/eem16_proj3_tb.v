`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sagar Doshi - 604901376, Jamie Yang - 004979189
//
// Create Date:   04:12:22 03/07/2019
// Design Name:   eem16_proj3
// Module Name:   /home/ise/Xilnix/Project3/eem16_proj3_tb.v
// Project Name:  Project3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: eem16_proj3
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module eem16_proj3_tb;

	// Inputs
	reg x1;
	reg x0;
	reg r;
	reg clk;

	// Outputs
	wire z1;
	wire z0;

	// Instantiate the Unit Under Test (UUT)
	eem16_proj3 uut (
		.x1(x1), 
		.x0(x0), 
		.r(r), 
		.clk(clk), 
		.z1(z1), 
		.z0(z0)
	);

	initial begin
		// Initialize Inputs
		x1 = 0;
		x0 = 0;
		r = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		// start the clock
      forever begin
			#10 clk = ~clk;
		end
	end
	
	// Add stimulus here
	/* 3 Sequences are necessary
					 
					 x1,x0,r
					 
	D N D    === 110 010 110
	N N N N  === 010 010 010 010
	D r		=== 110 --1
	*/
	initial begin
			// We wait to stay in sync with the clk
			#130;
			
			
			// Sequence 1
			x1 = 1;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
			x1 = 0;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
			x1 = 1;
			x0 = 1;
			#10; // Maybe an issue?
			
			x1 = 0;
			x0 = 0;
			#10;
			
			// Sequence 2
			
			x1 = 0;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
			x1 = 0;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
			x1 = 0;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
			x1 = 0;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
		
			// Sequence 3
			
			x1 = 1;
			x0 = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
			x1 = 0;
			x0 = 0;
			r = 1;
			#10;
			
			x1 = 0;
			x0 = 0;
			#10;
			
	end
      
endmodule

