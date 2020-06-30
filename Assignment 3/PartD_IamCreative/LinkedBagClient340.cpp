//	LinkedBagClient340.cpp
//	Created by: Duc Ta

#include "Include.h"

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

void displayBag(const unique_ptr<LinkedBag<string>>&);

int main() {

	cout << "----- LINKED BAG 340 C++-----" << endl << endl;

	cout << "--->>>>> Test 10 --->>>>>" << endl;
	unique_ptr<LinkedBag<string>> bagD{ make_unique <LinkedBag<string>>() };

	// A small vector of small objects to test the bag
	vector<string> itemsD{ "#-END", "5-FIVE", "4-FOUR", "4-FOUR", "3-THREE", "2-TWO", "1-ONE", "0-ZERO", "#-BEGIN" };
	cout << " !add()...     ";
	vector<string>::const_iterator cItrD;
	for (cItrD = itemsD.begin(); cItrD != itemsD.end(); cItrD++) {
		cout << *cItrD << " ";
		bool success = bagD->add(*cItrD);
		if (!success) {
			cout << " !add() FAILED: " << *cItrD << endl;
		}
	}
	displayBag(bagD);
	cout << endl << "Remove all occurences of " << bagD->removeAllOccurrences("4-FOUR");
	displayBag(bagD);

	cout << endl;
	return 0;
}

// Display the current contents in the bag
void displayBag(const unique_ptr<LinkedBag<string>>& bag) {
	cout << "\n !Display bag: ";
	auto bagItems = make_unique<vector<string>>(bag->toVector());

	vector<string>::const_iterator cItr;
	for (cItr = bagItems->begin(); cItr  != bagItems->end(); cItr++) {
		cout << *cItr << " ";
	}
	
	cout << "\n  -----------> " << bagItems->size() << " item(s) total";
	cout << endl;
}