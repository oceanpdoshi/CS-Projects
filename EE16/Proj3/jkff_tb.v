`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Sagar Doshi , Jamie Yang 004979189
// Create Date:   03:07:00 03/07/2019
// Design Name:   jkff
// Module Name:   /home/ise/Xilnix/Project3/jkff_tb.v
// Project Name:  Project3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: jkff
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module jkff_tb;

	// Inputs
	reg J;
	reg K;
	reg clk;
	reg CLR;

	// Outputs
	wire Q;

	// Instantiate the Unit Under Test (UUT)
	jkff uut (
		.J(J), 
		.K(K), 
		.clk(clk), 
		.CLR(CLR), 
		.Q(Q)
	);

	initial begin
	
		// Initialize Inputs
		J = 0;
		K = 0;
		clk = 0;
		CLR = 0;
		// Wait 100 ns for global reset to finish
		#100;
        
		forever begin
			#10 clk = ~clk;
		end
	end
		// Add stimulus here
	
	initial begin
			#110;
			
			J = 1;
			K = 0; 
			#20;
			
			J = 0;
			K = 1;
			#20;
			
			J = 1;
			K = 1;
			#20;
			
			J = 0;
			K = 0;
			#20;
	end
		
	
		
      
endmodule

