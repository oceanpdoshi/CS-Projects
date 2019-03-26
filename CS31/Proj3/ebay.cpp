#include<iostream>
#include<string>
#include<cassert>

//Make sure to get rid of error outputs when you are done!!!
using namespace std;

//Tests if the inputted string is a valid auction string
bool isValidEbayListingString(string auctionstring) {
	//Checks for empty string
	if (auctionstring == "") {
		return false;
	}
	
	//Converts all lowercase letters to uppercase letters
	for (size_t k = 0; k < auctionstring.size(); k++) { 
		if (islower(auctionstring[k])) {
			auctionstring[k] = toupper(auctionstring[k]);
		}
	}

	//Checks for spaces or periods
	for (size_t k = 0; k < auctionstring.size(); k++) {
		if ((auctionstring[k] == ' ') || (auctionstring[k] == '.')) {
			return false;
		}
	}
	
	//Checks to make sure that the number of U never exceeds the number of W
	int Wcounter = 0;
	int Ucounter = 0;
	for (size_t k = 0; k < auctionstring.size(); k++) {
		if (auctionstring[k] == 'W') Wcounter++;
		if (auctionstring[k] == 'U') Ucounter++;
		if (Ucounter > Wcounter) {
			return false;
		}
	}
	
	//Processes the string from the List price to the initial bid price
	if (auctionstring[0] == 'L') {
		int x = 0; //x marks the current position in the string
		for (size_t i = 1; i < auctionstring.size(); i++) {
			if (!isdigit(auctionstring[i])) {
				if ((auctionstring[i] != 'W') && (auctionstring[i] != 'U')) { //For loop will iterate to next character if the character after a number is a W or U
					if (auctionstring[i] = 'B') {
						x = i; //Position of B in string
						break;
					} 
					else return false; //Found an invalid character
				}
			}	
		}

		//Processes the string from the first bid price to the first B+
		if (x != 0) {
			if (auctionstring[x] == 'B') {
				if ((auctionstring[x + 1] == 'W') || (auctionstring[x+1] == 'U')) return false;
				for (size_t j = x + 1; j < auctionstring.size(); j++) {
					if (!isdigit(auctionstring[j])) {
						if ((auctionstring[j] != 'W') && (auctionstring[j] != 'U')) { //For loop will iterate to next character if the character after a number is a W or U
							if (auctionstring[j] == 'B') {
								x = j + 1; //Position of + in string
								break;
							}
							else return false; //Found an invalid alpha character like K+ for example
						}
					}
				}
			}
		}
		
		//Processes the string from the first B+ to the end of the string
		if (x != 0) {
			if (auctionstring[x] != '+') return false;
			if (auctionstring.substr(x - 1, 2) == "B+") {
				for (size_t l = x + 1; l < auctionstring.size(); l++) {
					if (!isdigit(auctionstring[l])) {
						if ((auctionstring[l] != 'U') && (auctionstring[l] != 'W')) {
							if (auctionstring[l] != 'B') return false;
							if (auctionstring.substr(l, 2) == "B+") {
								l += 1;
							}
							else return false; //found an invalid alpha character like K+
						}
					}
				}
			}
		}
		
		
		

	}
	else return false;

	return true;

}

//Determines whether or not the bids exceed the list price
bool listingSold(string auctionstring) {
	if (isValidEbayListingString(auctionstring)) {
		
		//Convert to Capital letters
		for (size_t k = 0; k < auctionstring.size(); k++) {
			if (islower(auctionstring[k])) {
				auctionstring[k] = toupper(auctionstring[k]);
			}
		}

		//Converts list price to an integer
		size_t location = 0;

		for (size_t j = 1; j < auctionstring.size(); j++) {
			if (!isdigit(auctionstring[j])) {
				location = j - 1;
				break;
			}
		}
		string listprice = auctionstring.substr(1, location);
		int list_price = stoi(listprice);

		int bidtotal = 0;
		size_t counter = 0;
		int initialposition = 0;
		int initialbid = 0;
		string stringholder = "";
		
		//Converts the initial bid to an integer
		for (int n = 0; n < auctionstring.size(); n++) {
			if (auctionstring[n] == 'B') {
				n += 1;
				initialposition = n;
				counter = n;
				while (isdigit(auctionstring[n])) {
					counter++;
					n++;
				}
				stringholder = auctionstring.substr(initialposition, counter - initialposition);
				initialbid = stoi(stringholder);
				break;
			}
		}

		//Sums up the bid increments
		for (size_t i = 0; i < auctionstring.size(); i++) {
			if (auctionstring[i] == 'B') {
				if (auctionstring[i + 1] == '+') {
					i += 2;
					counter = i;
					initialposition = i;
					while (isdigit(auctionstring[i])) {
							counter++;
							i++;
					}
					stringholder = auctionstring.substr(initialposition, counter - initialposition);
					bidtotal += stoi(stringholder); 
				}
			}
		}

		//Adds the initial bid and sum of bid increments to determine whether or not the item was sold
		int sum = initialbid + bidtotal;

		if (sum >= list_price) return true;
		else return false;
	}
	else return false;
}

//Returns -1 if string is invalid, 0 if the item didn't sell, and the sell price if the item actually sold
int howMuch(string auctionstring) {
	if (isValidEbayListingString(auctionstring)) {
		if (listingSold(auctionstring)) {
			
			//Convert to Capital letters
			for (size_t k = 0; k < auctionstring.size(); k++) {
				if (islower(auctionstring[k])) {
					auctionstring[k] = toupper(auctionstring[k]);
				}
			}
			
			int bidtotal = 0;
			size_t counter = 0;
			int initialposition = 0;
			int initialbid = 0;
			string stringholder = "";

			//Converts the initial bid to an integer
			for (int n = 0; n < auctionstring.size(); n++) {
				if (auctionstring[n] == 'B') {
					n += 1;
					initialposition = n;
					counter = n;
					while (isdigit(auctionstring[n])) {
						counter++;
						n++;
					}
					stringholder = auctionstring.substr(initialposition, counter - initialposition);
					initialbid = stoi(stringholder);
					break;
				}
			}

			//Sums up the bid increments
			for (size_t i = 0; i < auctionstring.size(); i++) {
				if (auctionstring[i] == 'B') {
					if (auctionstring[i + 1] == '+') {
						i += 2;
						counter = i;
						initialposition = i;
						while (isdigit(auctionstring[i])) {
							counter++;
							i++;
						}
						stringholder = auctionstring.substr(initialposition, counter - initialposition);
						bidtotal += stoi(stringholder);
					}
				}
			}

			//Adds the initial bid and sum of bid increments to determine whether or not the item was sold
			int sum = initialbid + bidtotal;
			return sum;
		}
		else return 0;
	}
	else return -1;
}

int watchers(string auctionstring) {
	if (isValidEbayListingString(auctionstring)) {
		
		//Convert to Capital letters
		for (size_t k = 0; k < auctionstring.size(); k++) {
			if (islower(auctionstring[k])) {
				auctionstring[k] = toupper(auctionstring[k]);
			}
		}

		//Count up the number of Ws - the number of Us
		int Wcounter = 0;
		for (size_t i = 0; i < auctionstring.size(); i++) {
			if (auctionstring[i] == 'W') {
				Wcounter += 1;

			}
			if (auctionstring[i] == 'U') {
				Wcounter -= 1;
			}
		}

		return Wcounter;

	}
	else return -1;
}

//Main method used to test functions
int main() {
}