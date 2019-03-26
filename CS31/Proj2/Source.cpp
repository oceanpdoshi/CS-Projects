#include<string>
#include<iostream>

using namespace std;

int main() {
	
	//Variable declarations
	string donor_name = "";
	string gender = "";
	int age = 0;
	int weight = 0;
	int height = 0;
	
	//Collection and error handling of inputs
	cout << "Donor Name: ";
	getline(cin, donor_name);
	if (donor_name == "") {
		cout << "--- You must enter a valid name." << endl;
		return(0);
	}

	cout << "Gender: ";
	getline(cin, gender);
	if (gender != "Male" && gender != "Female" && gender != "Queer" && gender != "Different" && gender != "Trans Male" && gender != "Trans Female") {
		cout << "--- You must enter a valid gender." << endl;
		return(0);
	}

	cout << "Age: ";
	cin >> age;
	if (age <=  0) {
		cout << "--- You must enter a valid age." << endl;
		return(0);
	}

	cout << "Weight: ";
	cin >> weight;
	if (weight <= 0) {
		cout << "--- You must enter a valid weight." << endl;
		return(0);
	}

	cout << "Height: ";
	cin >> height;
	if (height <= 0) {
		cout << "--- You must enter a valid height." << endl;
		return(0);
	}

	//Logic to determine eligibility to donate
	if (age >= 16) {
		if (weight >= 110) {
			if (age <= 22) {
				if (gender == "Male") {
					if (height < 60) {
						cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
						return(0);
					}
					else {
						cout << "--- Yes, " << donor_name << " you can donate blood." << endl;
						return(0);
					}
				}
				else if (gender == "Female") {
					if (height < 58) {
						cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
						return(0);
					}
					else if (height == 58) {
						if (weight >= 146) {
							cout << "--- Yes, " << donor_name << " you can donate blood." << endl;
							return(0);
						}
						else {
							cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
							return(0);
						}
					}
					else if (height == 59) {
						if (weight >= 142) {
							cout << "--- Yes, " << donor_name << " you can donate blood." << endl;
							return(0);
						}
						else {
							cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
							return(0);
						}
					}
					else {
						cout << "--- Yes, " << donor_name << " you can donate blood." << endl;
						return(0);
					}
				}
				else if (gender == "Trans Male" || gender == "Trans Female" || gender == "Queer" || gender == "Different") {
					cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
					return(0);
				}
			}
			else {
				cout << "--- Yes, " << donor_name << " you can donate blood." << endl;
				return(0);
			}
		}
		else {
			cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
			return(0);
		}
	}
	else {
		cout << "--- No, " << donor_name << " you cannot donate blood." << endl;
		return(0);
	}

	return(0);
}