unsigned long srl(unsigned long x, int k) {

        unsigned long  xrsa = (long) x >> k;
	
	if (k == 0)
		return xrsa;
	// Avoid shifting by a - number
	if (k >= sizeof(long)*8)
		return 0;
		
	// We want the mask to look like 00000...00001111111111111
        return  xrsa &  ~(-1 << ((sizeof(long)*8) - k));
}

long sra(long x, int k) {

        long  xrsl = (unsigned long) x >> k;
	
	if (k == 0)
		return xrsl;
	// avoid shifting by a - number
	if (k >= sizeof(long)*8)
		return 0;

	// arithemtically  shifting a positive integer is the same thing as a logical shift
	// as the most significant digit is 0 (twos complement representation).
	if (x > 0)
		return xrsl;	
	
	long mask = -1 << (sizeof(long)*8 - k); //111111111111111100000000000000
	
	long first_bit  = 1 << (sizeof(long)*8 - k); // 1000000000000000000000

	mask = mask & (!(x & first_bit) - 1);

        return xrsl | mask;

}

int main() {	
        return 0;
}

