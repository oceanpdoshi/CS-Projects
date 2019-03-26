`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
// Sagar Doshi - UID : 604901376, Jamie Yang - UID: 004979189
//
// Create Date:   06:50:45 02/14/2019
// Design Name:   eem16_proj2
// Module Name:   /home/ise/EE16_Project2/eem16_proj2_tb.v
// Project Name:  EE16_Project2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: eem15_proj2
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module eem16_proj2_tb;

	// Inputs
	reg w;
	reg x;
	reg y;
	reg z;

	// Outputs
	wire a;
	wire b;
	wire c;
	wire d;
	wire e;
	wire f;
	wire g;

	// Instantiate the Unit Under Test (UUT)
	eem16_proj2 uut (
		.w(w), 
		.x(x), 
		.y(y), 
		.z(z), 
		.a(a), 
		.b(b), 
		.c(c), 
		.d(d), 
		.e(e), 
		.f(f), 
		.g(g)
	);

	initial begin
		// Initialize Inputs
		w = 0;
		x = 0;
		y = 0;
		z = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		//1
	w = 0;
	x = 0;
	y = 0;
	z = 1;
	#20
	
	//2
	w = 0;
	x = 0;
	y = 1;
	z = 0;
	#20
	
	//3
	w = 0;
	x = 0;
	y = 1;
	z = 1;
	#20
	
	//4
	w = 0;
	x = 1;
	y = 0;
	z = 0;
	#20
	
	//5
	w = 0;
	x = 1;
	y = 0;
	z = 1;
	#20
	
	//6
	w = 0;
	x = 1;
	y = 1;
	z = 0;
	#20
	
	//7
	w = 0;
	x = 1;
	y = 1;
	z = 1;
	#20
	
	//8
	w = 1;
	x = 0;
	y = 0;
	z = 0;
	#20
	
	//9
	w = 1;
	x = 0;
	y = 0;
	z = 1;
	#20
	
	//0
	w = 0;
	x = 0;
	y = 0;
	z = 0;
	#20
	
	$finish;
	end
      
endmodule

