`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// Sagar Doshi - UID : 604901376, Jamie Yang - UID: 004979189
// 
// Create Date:    06:49:24 02/14/2019 
// Design Name: 
// Module Name:    eem16_proj2 
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
module eem16_proj2(
    input w,
    input x,
    input y,
    input z,
    output a,
    output b,
    output c,
    output d,
    output e,
    output f,
    output g
    );
	 

assign a = (!x && !y && !z) || w || y || (x && z);
assign b = !x || (!y && !z) || (y && z);
assign c = !y || z || x || w;
assign d = w || (!x && !y && !z) || (x && !y && z) || (!x && y) || (y && !z);
assign e = (!x && !y && !z) || (y && !z);
assign f =  w || (x && !y) ||  (x && !z) || (!y && !z);
assign g = w || (x && !y) || (y && !z) || (!x && y);



endmodule
