#define R 7
#define S 5
#define T 8

long A[R][S][T];

// We know that the last dimension of any N-dimension array is contiguous
// We know the general form will be & = Base + L * (offset)
// where L is the size of the elements (in this case long = 8)
:q

// Equation 3.1 states & = Base + L*(S*i + j)
// To add the last dimension we multiply by the size of the row dimension and add the offset index k to get
// & = Base + L*[(S*i + j)*T + k]
// This equation follows the general form, and you can repeat the procedure of multiplying by the next dimensions's size and adding the offset index for any dimension

// Now that we have this equation we just have to trace through the assembly code and see if we can write out the derived
// Based on the pattern of the assembly code, it is clear that up until the last step, we are computing expr where expr is:
// & = Base + L*(expr)
// So if we can find the formula in %rax, then we can deduce the sizes.
// First the assembly code stores (7-i) into %rax, so clearly R is 7
// We then store 5*(7-i) - j into the assembly code
// This means that S is 5, and we have the -j because we are indexing at 1-j
// We then store 8[5*(7-i) - j] + 7 + k into %rax meaning that T must be 8, and we move (7 + k) because we are indexing by k + 1
// At the last step, we take the value at A + 8*expr, and the 8 is because sizeof(long) == 8, and A is the base address of our entire 3D array.

long ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}
