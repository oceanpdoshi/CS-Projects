/* 
 * CS:APP Data Lab 
 * 
 * Sagar Doshi 604901376
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
 // if the bit vector has ANY 1s -> return 0
 // if the bit vector is all 0s -> return 1
 
  // uses the property that -x = ~x + 1, but -0 = 0 
  x = x & (~x +1);  

  x = ~x + 1;
  // Move  most significant bit to the least significant bit so that we can compare like a boolean operation
  x = x >> 31;
 return ~x & 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */

// Utilized hint of counting bits in parallel to figure this out
int bitCount(int x) {

   //000...0001000100010001    
   int mask1 = (0x11 << 8) + 0x11;
   
   //00010010001000100010001...
   int mask2 = (mask1 << 16) + mask1;

   // Sum keeps track of the count of 1s in x 
   int sum = x & mask2;
   
   // We shift right 1,2,3 to get the number of 1s in the least 4 significant bits
   sum = sum + ((x >> 1) & mask2);
   sum = sum + ((x >> 2) & mask2);
   sum = sum + ((x >> 3) & mask2);
  
   // At this points, bits beyond the last 4 are not needed
   sum = sum + (sum >> 16);
   // sum looks like 0000000000...<last 4 bits>
   //0xF = 1111
   // We change mask to keep the current sum and then to count the number of 1s in the next byte
   mask1 = (0xF << 8) + 0xF;
   // Alternating bits in the pattern 11110000111100001111....
   sum = (sum & mask1) + ((sum >> 4) & mask1);
   //0x3F = 00111111
   //Need to truncate sum to last 6 bits as 32 = 2^5, so last 6 bits represent our answer
   return((sum + (sum >> 8)) & 0x3F);

}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  int mask = ~0; // -1 = 111111111...

  // place 0s into the mask wherever BOTH  x was 0 AND y was 0. Using the bitwise not operator as follows accomplishes this.
  return (mask & ~(~x & ~y));
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
  
  //Edge case n == 32, nMax is either set to 1111... or 00000...
  int nMax = ~(!(n & 31)-1);  
  

  // Just the last n bits to form our pattern
  int pattern = ~(~0 << n) & x;  
  
  // Use the magic binary numbers {1,2,4,8,16}
  // if we overflow, that means that 32 % n bits overflowed
  // Need to check for the overflow at every step
 
  int n_two = n*2;
  int n_four = n*4;
  int n_eight = n*8;
  int n_sixteen = n*16;
 
  // the ~(2n) & over -1 portion does the overflow checking by either being all 1s or 0s depending on whether or n ot an overlow occurred
  // the pattern = pattern | appends the pattern onto the current pattern (growth is logarithmic)
  pattern = pattern  | pattern << n;
  pattern = pattern  | ((pattern << (n_two)*!(n_two/32)));
  pattern = pattern  | ((pattern << (n_four))*!(n_four/32));
  pattern = pattern  | ((pattern << (n_eight))*!(n_eight/32));
  pattern = pattern  | ((pattern << (n_sixteen))*!(n_sixteen/32));

  // Have to check the edge case of n = 32 
  return (pattern & ~nMax) | (x & nMax);  

}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  // [-2^(n-1), 2^(n-1) - 1] is the range of acceptable values
  
  // just the sign bit
  int mask = x >> 31;

  // ~0 = -1
  // (~x & mask) + (x & ~mask) yields a bit vector with the highest bits in x
  // (~x & mask) yields the highest bits if x was positive
  // (x & ~mask) yields  the highest bits if x was negative
  // Combining the two will yield the highest bit regardless of whether  x was positive or negative
  // We have to truncate the result and see if any 1s are remaining.
  return !(((~x & mask) + (x & ~mask)) >> (n + ~0));

}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int mask = 255; //0xff
  n = n << 3; // n = n*8 (bytes-> bit conversion)
  // reduce x so that the nth byte is now the least significant 8 bits
  // and that with 11111111 to get the answer
  return (x >> n) & mask;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // how to negate a number  
  
  // Generate INT_MAX and INT_MIN 
  int min = 1 << 31;
  int max = ~min;
  
  // The strategy is to check if y - x >= 0
  // You only actually need to do the subtraction if both x and y are negative or both or positive (negative numbers are, by definition less than positive numbers.
  // THEREFORE YOU CAN DO THE SUBTRACTION WHILE IGNORING THE SIGN BIT TO PREVENT OVERFLOW
  // Doing the subtraction (y - x = y + (~x + 1)), then you have to '&'  both the operands with INT_MAX (01111111111111...11) because you need to ignore the sign bit to prevent overflow.
  // In terms of logical syntax, this is equivalent to:
  // x < 0 && y >= 0 || (x < 0 && y < 0 || x >= 0 && y >= 0) && y - x > 0
  return  !! (((x & ~y) | (~(x ^ y) & ~((y & max) + ~(x & max) + 1))) & min);

}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {

  int mask = 1 << 31;

  // The left side evaluates to 0 if the number is negative, and it evaluates to 1 if the number was positive or 0
  // The right side evaluates to 0 ONLY if the number is 0, and it evaluates 1 if the number was negative OR positive
  // This takes advantage of the fact that !(anything) = 0, and !(0) = 1. So the double '!' basically  makes this a boolean expression.
  
  return !(x & mask) & !!(((mask & x)) | x);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n)
{
  // We want the mask to look like 0000001111111111111111111 with n 0s at the front
  // just apply the mask afer doing the arithmetic rihgt shift 
  int mi = 1 << 31;
  int ma = ~mi;
  int mask = ma >> n;

  x = x >> n;
  mask = mask << 1;
  mask = mask | 1;
  
  // ON THIS COMPILER 1 << 32 != 0 which is causing this to be buggy.
  return x & mask;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	return 1 << 31;
}
