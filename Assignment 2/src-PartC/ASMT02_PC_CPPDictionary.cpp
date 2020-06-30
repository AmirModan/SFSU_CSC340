#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

string toLowerCase(string str);
vector<string> split(string str, string delimeter);
bool contains(vector<string> v, string str);

/**
 * Converts all the characters in this string to Lower-Case.
 *
 * @param str The string to be converted to Lower-Case.
 * @return str The string converted to Lower-Case.
 */
string toLowerCase(string str) {
	for_each(str.begin(), str.end(), [](char& c) {
		c = tolower(c);
		});
	return str;
}

/**
 * Splits this string around matches of the given regular expression.
 *
 * @param str The string to be split.
 * @param delimeter The delimiting regular expression.
 * @return splitted The vector of strings computed by splitting this string around matches of the given regular expression.
 */
vector<string> split(string str, string delimeter) {
	vector<string> splitted;
	int startIndex = 0;
	int  endIndex = 0;
	while ((endIndex = str.find(delimeter, startIndex)) < str.size()) {
		string piece = str.substr(startIndex, endIndex - startIndex);
		splitted.push_back(piece);
		startIndex = endIndex + delimeter.size();
	}
	if (startIndex < str.size()) {
		string piece = str.substr(startIndex);
		splitted.push_back(piece);
	}
	return splitted;
}

/**
 * Returns true if this vector contains the specified element.
 *
 * @param v The vector to be searched.
 * @param str The string whose presence in this vector is to be tested.
 * @return true if this list contains the specified element, otherwise false.
 */
bool contains(vector<string> v, string str) {
	for (string s : v) {
		if (s == str) {
			return true;
		}
	}
	return false;
}

int main() {

	// Opens text file.
	cout << "! Opening data file... ./Data.CS.SFSU.txt" << endl;
	ifstream file("Data.CS.SFSU.txt");

	// Loads data from text file to data structures.
	cout << "! Loading data..." << endl;
	string sent;
	vector<string> keywordVector;
	vector<string> speechVector;
	vector<string> defVector;

	if (!file) {
		cout << "Not found" << endl;
	}
	while (getline(file, sent)) {
		vector<string> v1 = split(sent, "|");
		string keyword = v1[0];
		v1.erase(v1.begin());
		sort(v1.begin(), v1.end());
		for (int i = 0; i < v1.size(); i++) {
			vector<string> v2 = split(v1[i], " -=>> ");
			keyword[0] = toupper(keyword[0]);
			if (keyword[1] == 's' && keyword[2] == 'c') {
				keyword[1] = 'S';
				keyword[2] = 'C';
			}
			keywordVector.push_back(keyword);
			speechVector.push_back(v2[0]);
			defVector.push_back(v2[1]);
		}

	}


	cout << "! Loading completed..." << endl;
	cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
	cout << "\n----- DICTIONARY 340 C++ -----\n" << endl;
	bool inProgress = true;

	// User input is repeatedly scanned for and queried until exit command is given.
	while (inProgress) {
		cout << "Search: ";
		string inputString;
		getline(cin, inputString);
		vector<string> input = split(toLowerCase(inputString), " ");
		bool found = false;
		string dPrev = "";
		string sPrev = "";
		switch (input.size()) {

			// If input contains one data field, prints all occurences of the field contained within the dictionary.
			// Or ends program if exit command is entered.
		case 1:
			if (input[0] == "!q") {
				cout << "\n-----THANK YOU-----" << endl;
				inProgress = false;
				break;
			}
			cout << "    |" << endl;
			for (int i = 0; i < keywordVector.size(); i++) {
				if (input[0] == toLowerCase(keywordVector[i])) {
					cout << "     " << keywordVector[i] << " [" << speechVector[i] << "] : " << defVector[i] << endl;
					found = true;
				}
			}
			if (!found) {
				cout << "     <Not found>" << endl;
			}
			cout << "    |" << endl;
			break;

			// If input contains two data fields, prints all occurences of the first field contained within the dictionary.
			// If second field contains a valid speech type, prints only occurences of that type.
			// Or if second field is equivalent to "distinct", filters out any duplicate entries.
			// Else will print an error.
		case 2:
			cout << "    |" << endl;
			if (!(input[1] == "distinct") && !contains(speechVector, input[1])) {
				cout << "     <2nd argument must be a part of speech or \"distinct\">" << endl;
				found = true;
			}
			for (int i = 0; i < keywordVector.size(); i++) {
				if (input[0] == toLowerCase(keywordVector[i])) {
					if (input[1] == speechVector[i]) {
						cout << "     " << keywordVector[i] << " [" << speechVector[i] << "] : " << defVector[i] << endl;
						found = true;
					}
					else if (input[1] == "distinct") {
						if (!(defVector[i] == dPrev) || !(speechVector[i] == sPrev)) {
							cout << "     " << keywordVector[i] << " [" << speechVector[i] << "] : " << defVector[i] << endl;
							found = true;
						}
					}


				}
				dPrev = defVector[i];
				sPrev = speechVector[i];
			}
			if (!found) {
				cout << "     <Not found>" << endl;
			}
			cout << "    |" << endl;
			break;

			// If input contains three data fields, prints all distinct occurences of the first field with a speech type of the second field contained within the dictionary.
			// Else will print an error.
		case 3:
			cout << "    |" << endl;
			if (!contains(speechVector, input[1])) {
				cout << "     <2nd argument must be a part of speech or \"distinct\">" << endl;
				found = true;
			}
			if (!(input[2] == "distinct")) {
				cout << "     <3rd argument must be \"distinct\">" << endl;
				found = true;
			}
			for (int i = 0; i < keywordVector.size(); i++) {
				if (input[0] == toLowerCase(keywordVector[i])) {
					if ((input[1] == speechVector[i]) && (!(defVector[i] == dPrev) || !(speechVector[i] == sPrev))) {
						cout << "     " << keywordVector[i] << " [" << speechVector[i] << "] : " << defVector[i] << endl;
						found = true;
					}
				}
				dPrev = defVector[i];
				sPrev = speechVector[i];
			}
			if (!found) {
				cout << "     <Not found>" << endl;
			}
			cout << "    |" << endl;
			break;
		}
	}

	return 0;
}

