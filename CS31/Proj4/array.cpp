#include<iostream>
#include<string>
#include<cassert>

using namespace std;

/* all functions that return an int must return −1 if they are passed any bad arguments
	e.g. a negative array size
	Don't worry about a position "n" that would require looking at the contents of an element past the last element we're interested in 
*/

/*
Return the index of the smallest item found in the array or -1 if n <= 0. 
*/
int findMinimum(const string array[], int n) {
	if (n <= 0) return -1;
	if (n == 1) return 0;

	int minimum_index = 0;
	string current_minimum = array[0];

	for (int i = 1; i < n; i++) {
		if (array[i] < current_minimum) {
			current_minimum = array[i];
			minimum_index = i;
		}
	}

	return minimum_index;

}


/*
	Return the total number of punctuation symbols found in all the elements of the passed array argument
	'.', ',', '!', ';', ''', ' - ', ' / ', ':', ' ? ', '"' count as punctuation symbols
	period, comma, exclamation mark, semicolon, apostrophe, dash, slash, colon, question mark, and double quote 
*/
int countAllPunctuation(const string array[], int n) {
	if (n <= 0) return -1;

	int punctuation_counter = 0;

	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < array[i].length(); j++)
			if (array[i][j] == '.' || array[i][j] == ',' || array[i][j] == '!' || array[i][j] == ';' || array[i][j] == '\'' || array[i][j] == '-' || array[i][j] == '/' || array[i][j] == ':' || array[i][j] == '?'|| array[i][j] == '\"') {
				punctuation_counter++;
			}
	}

	return punctuation_counter;

}

/* 
	Return the total number of floating-point values found in all the array elements of the passed array argument.
	For the purpose of this function, a floating-point value should have the form #.#, where # is one of the digits 0-9.
	The decimal point is optional but should only be found once for the element to count as a valid floating-point value.
	Return -1 if n <= 0.
*/

int countFloatingPointValues(const string array[], int   n) {
	if (n <= 0) return -1;
	
	int decimal_counter = 0;
	int floating_point_counter = 0;
	int length = 0;

	for (int i = 0; i < n; i++) {
		decimal_counter = 0;
		length = 0;
		if (array[i].length() == 0) continue; //handles the case of the empty string
		if (array[i].length() == 1 && (array[i] == "." || isalpha(array[i][0]))) continue; //handles the case of "." or just a letter as the first charcter of the string
		for (size_t j = 0; j < array[i].length(); j++) {
			if (array[i][j] == '.') decimal_counter++;
			if (decimal_counter > 1) break;
			if (!isdigit(array[i][j]) && array[i][j] != '.') break; //Nothing but numbers or periods allowed
			length++; //indicates that the for loop iterated through through the entire string
		}
		if (array[i].length() == length) floating_point_counter++;
	}

	return floating_point_counter;
}

/* 
	This function should ensure that none of the array elements are the same.  
	All the non-duplicated values should be kept together at the front of the array
	your function should use "" (the empty string) to fill out the array as needed.
	Return the number of elements which were removed or -1 if the array has no elements.
*/

int removeDuplicatedValues(string array[], int  n) {
	if (n <= 0) return -1;

	int remove_counter = 0;

	for (int i = 0; i < n - 1; i++) {
		if (array[i] == "") continue;  //Hopefully this won't have to check for duplicate empty strings otherwise the problem guideline doesn't make sense
		for (int j = i+1; j < n; j++) {
			if (array[i] == array[j]) {
				array[j] = "";
				remove_counter++;
				cerr << "plus1" << endl;
			}
		}
	}
	
	return remove_counter;
}

/*
This function should replace every occurrence of the letterToReplace value with the letterToFill value found in all the array elements of the passed array argument. 
Return the number of letters that were replaced or -1 if the array has no elements.
*/
int replaceAll(string array1[], int n, char letterToReplace, char letterToFill) {
	
	if (n <= 0) return -1;

	int number_replacements = 0;

	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < array1[i].length(); j++) {
			if (array1[i][j] == letterToReplace) {
				array1[i][j] = letterToFill;
				number_replacements++;
			}
		}
	}

	return number_replacements;

}

/*
Adjust the items found in the array, 
shifting each value to the right by amount parameter, 
filling the resulting first amount elements of the array with the placeholder parameter 
and returning the number of times the placeholder value was used after all the shifting has been performed 
or -1 if the array has no elements.
*/
int shiftRight(string array[], int n, int amount, string placeholder) {
	if (n <= 0) return -1;
	if (amount <= 0) return -1; //Shouldn't do anything if passed an amount less than 0, not trying to code shiftLeft().

	//Case where amount >= n 
	if (amount >= n) {
		for (int i = 0; i < n; i++) {
			array[i] = placeholder;
		}
		return n;
	}

	//Case where amount is < n
	if (amount < n) {
		int counter = 0;
		for (int k = amount; k < n; k++) {
			array[k] = array[counter];
			counter++;
		}

		for (int j = 0; j < amount; j++) {
			array[j] = placeholder;
		}
		return amount;
	}

	return -1;


}

//For test cases (commented out)
int main() {
	
	/*
	string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
	string bad[1] = { "urbunz" };
	string people2[6] = { "ayylmao", "samwell", "jon", "margaery", "daenerys", "tyrion"};
	string punctuation_test[2] = {".,!;\'-/:?\"", "Tester1234151542341...2,"};
	string floating_point_test[4] = { "4.4.3.3", "44", "33.098", "33.098a" };
	string floating_point_test1[5] = {"",".","a","1","2"};
	string duplicated_values_test[4] = { "happy", "days", "happy", "days" };
	*/

	/*
	cerr << findMinimum(bad, 1) << endl;
	cerr << findMinimum(bad, 0) << endl;
	cerr << findMinimum(bad, -1) << endl;
	*/

	//cerr << countAllPunctuation(punctuation_test, 2) << endl; //Should return 14
	
	/*
	cerr << countFloatingPointValues(floating_point_test1, 5) << endl;
	cerr << countFloatingPointValues(floating_point_test, -1) << endl;
	cerr << countFloatingPointValues(floating_point_test, 0) << endl;
	*/

	/*
	cerr << removeDuplicatedValues(people, 5) << endl;
	cerr << removeDuplicatedValues(duplicated_values_test, 4) << endl;
	for (int i = 0; i < 4; i++) {
		if (duplicated_values_test[i] != "") cerr << duplicated_values_test[i] << endl;
		else cerr << "_" << endl;
	} 
	*/

	/*
	cerr << replaceAll(people, 5, 'z', 'a') << endl;
	for (int i = 0; i < 5; i++) {
		cerr << people[i] << endl;
	}
	cerr << replaceAll(people, -5, 'z', 'a') << endl;
	cerr << replaceAll(duplicated_values_test, 4, 'a', 'z') << endl;
	for (int j = 0; j < 5; j++) {
		cerr << duplicated_values_test[j] << endl;
	}
	*/
	
	/*
	cerr << shiftRight(people, -5, 3, "foo") << endl;
	//cerr << shiftRight(people, 5, 25, "foo") << endl;
	cerr << shiftRight(people, 5, -25, "foo") << endl;
	cerr << shiftRight(people2, 6, 3, "foo") << endl;
	for (int j = 0; j < 6; j++) {
		cerr << people2[j] << endl;
	}
	cerr << endl;
	cerr << shiftRight(people, 5, 3, "foo") << endl;
	for (int j = 0; j < 5; j++) {
		cerr << people[j] << endl;
	}
	*/

}