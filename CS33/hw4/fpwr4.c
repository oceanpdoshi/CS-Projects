//Sagar Doshi
//UID: 604901376
//fpwr4.c

// Used ONLY for testing.
#include<math.h>
#include<assert.h>
#include<stdio.h>

// We need to do this pointer "trick" to preserve the bit pattern that fpwr4 returns
// This could also be done using a union
// We are only working with unsigned, so don't have to worry about sign bit.
static float u2f(unsigned u) {
 
 return * (float *) &u;
 
}

// When calculating the boundaries, we consider 4^x as equivalent to (2^2)^x = 2^2x
// This is helpful when determining the fractional and exponential componenets
float fpwr4(int x) {
 
 // Result exponent and fraction
 unsigned exp, frac;
 unsigned u;

 // Smallest representable floating point denormalized value is (2^-23 * 2^-126)
 // Solve the equation : 2^(2x) <  2^-126 * 2^-23 => x < -74.5 => x < -74
 if (x < -74) {
   // Too small. Return 0.0
   exp = 0;
   frac = 0;   
 }
 // Largest denormalized value is (2^-1 + 2^-2 + ... + 2^-23)* 2^-126
 // so solve the equation 4^x < (2^-1 + ... + 2^-23) * 2^-126 => x < -63
 else if (x < -63) {
   // Denormalized result.
   exp = 0;
   frac = 1 << (2*x + 149); // unsigned left shifting overflow SHOULD be ok
 }
 // Largest normalized value is (2 - e) * 2^127
 // so solve equation 4 ^ x < (2 - e) * 2^127 => x < 63.5 => x < 64
 else if (x < 64) {
   // Normalized result
   exp = 2*x + 127;
   frac = 0;
 }
 else {
   // Too big. Return +infinity (exp all 1s, frac all 0s)
   exp = 0xFF;
   frac = 0;
 }
 u = exp << 23 | frac;
 //return as float
 return u2f(u);

}

int main() {

  int i = -1000;
  float result;
  for (i; i < 1000; i++) {
    printf("%d \n", i);
    result = fpwr4(i);
    if (result == 0.0) {
    	assert(i < -74);
    }
    else if (result == INFINITY){
       assert(i >= 64);
    }
    else  {
      assert(result == pow(4,i));
    }
  }

  return 0;
}
