// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n)
{
	//Empty and single element cases
	if (n <= 0) return true;

	//Reached the last element i.e Base Case.b 
	if (n == 1) return somePredicate(a[0]);

	//Can't use a global counter, can't shift the string, need to use recursion.
	
	//Does this work? It checks the current value a*, (can't use a[0] as that would cause infinite recursion), and then calls the function with a moved pointer and decremented size
	//Order is important as short circuit evaluation will cause the return statement to return false if somePredicate(a*) is false.
	return(somePredicate(*a) && allTrue(a + 1, n - 1));
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
	//Base and empty case
	if (n <= 0) return 0;
	
	//only increment returned integer by 1 if something is found, otherwise just go deeper into the recursion.
	if (!somePredicate(*a)) {
		return 1 + countFalse(a + 1, n - 1);
	}
	else return countFalse(a + 1, n - 1);

}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n)
{
	//Base case of empty/never found.
	if (n <= 0) return -1;

	if (!somePredicate(a[0])) return 0;
	else {
		//Need this to check next element.
		if (firstFalse(a + 1, n - 1) == -1) 
			return -1;
		//Otherwise increment the index
		return 1 + firstFalse(a + 1, n - 1);
	}

}

// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the array has no elements to examine,
// return -1.
int indexOfLeast(const string a[], int n)
{
	//no elements to examine.
	if (n <= 0) return -1;

	int index = 1 + indexOfLeast(a+1, n-1);
	if (a[0] <= a[index])
		return 0;
	else return index;
	
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const string a1[], int n1, const string a2[], int n2)
{

	//Base Case: it through entire string or found a mismatch.
	//Made it through both without finding a mismatch
	if (n1 == 0 && n2 == 0) return true;

	//Found a mismatch
	if (n1 == 0 && n2 != 0) return false;
	
	//Check for matching
	if (a1[0] == a2[0]) {
		//If match increment both strings
		return includes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
	}
	else {
		//Otherwise only increment the 1st array.
		return includes(a1+1, n1-1, a2, n2);
	}
}
