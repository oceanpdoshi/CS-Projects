`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Sagar Doshi
// UID : 604901376
//
// Create Date:    19:17:54 01/31/2019 
// Design Name: 
// Module Name:    eem16_proj1 
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
module eem16_proj1(input x2, input x1, input x0, output z);
assign z = (!x2 && !x1 && x0) || (!x2 && x1 && !x0) || (x2 && x1 && !x0);

endmodule
