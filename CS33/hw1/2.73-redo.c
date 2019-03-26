#include<limits.h>

int saturating_add(int x, int y) {
	
	// This funtion only tells u whether or not there was an overflow
	int  b;
	b  = __builtin_add_overflow_p(x,y, (__typeof__ ((x) + (y))) 0);

	// b == 000000000..0000 if no overflow
	// b == 111111.111111 if overflow	
	b = ~b + 1;

	int sum = x + y;
	int mask = INT_MIN;	

	//Do the same shifting trick as the non_original to make bitwise logic basically the same as boolean logic	
	int pos_over = b & ~(x & mask) & ~(y & mask);
        int neg_over = b & (x & mask) & (y & mask);

	int n_shifts = ((sizeof(int) << 3)) -1;
	
	pos_over = pos_over >> n_shifts;
	neg_over = neg_over >> n_shifts;

	return ((INT_MAX & pos_over) + (INT_MIN & neg_over)
		+ ( ((~pos_over) & (~neg_over)) & sum ) );

	return sum;
	
}

int main() {
	return 0;
}
