#include <limits.h>

int saturating_add(int x, int y) {
	
	// Exactly like the practice  problem but with the bit constraints
	
	int sum = x + y;
	int mask = INT_MIN; // 10000000000000000000000000000000...000

	// if x > 0 && y > 0 but sum < 0 => positive overflow
	// if x < 0 && y < 0 but sum >= 0 => negative overflow
	
	// Only care baout most significant integer to check sign
	int pos_over = ~(x & mask) & ~(y & mask) & (sum & mask);
	int neg_over = (x & mask) & (y & mask) & ~(sum & mask);

	// pos_over and neg_over are 1111....1111 or 0000...00000 depending on whether or not their respective overflow occured	

        // Instead of using short circuit evaluation, exploit shifting to basically treat these as booleans
        int n_shifts = (sizeof(int) << 3) - 1;

	pos_over =   pos_over >> n_shifts;
	neg_over = neg_over >> n_shifts;

	return ((INT_MAX & pos_over) + (INT_MIN & neg_over)
		+ ( ((~pos_over) & (~neg_over)) & sum ) );
	
		
}

int main() {
	return 0;
}
