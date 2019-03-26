`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Sagar Doshi
// UID : 604901376

// Create Date:    19:41:09 01/31/2019 
// Design Name: 
// Module Name:    eem16_proj1_tb 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: This is the test bench file used to test eem16_proj1.v
//
//////////////////////////////////////////////////////////////////////////////////
module eem16_proj1_tb();

	reg x2,x1,x0;
	wire z;
	
	eem16_proj1 DUT(
		.x2(x2),
		.x1(x1),
		.x0(x0),
		.z(z)
	);
	
	initial begin
	x2 = 0;
	x1 = 0;
	x0 = 0;
	#20

	x2 = 0;
	x1 = 0;
	x0 = 1;
	#20

	x2 = 0;
	x1 = 1;
	x0 = 0;
	#20

	x2 = 0;
	x1 = 1;
	x0 = 1;
	#20

	x2 = 1;
	x1 = 0;
	x0 = 0;
	#20

	x2 = 1;
	x1 = 0;
	x0 = 1;
	#20

	x2 = 1;
	x1 = 1;
	x0 = 0;
	#20

	x2 = 1;
	x1 = 1;
	x0 = 1;
	#20
	$finish;
	end
	
endmodule
