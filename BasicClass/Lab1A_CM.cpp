/*
@Lab: 1A
@Author: Casey Merritt
@Purpose: Demonstrate our understanding of polymorphism and inheritance :D
*/

/*
Psuedo Code:
	Main(){
		create pStartDollar
		create pStartPound
		create pStartYen
		create pStartRupee
		create pStartReal

		while(someTestVar == true)
			print menu

			if(menu == 1){
				create temporaryHolder
				cin >> temphold

				if(someVar == Dollar){
					pStartDollar + tempHold
					delete tempHold
				}
				if(someVar == Pound){
					pStartDollar + tempHold
					delete tempHold
				}
				if(someVar == Yen){
					pStartYen + tempHold
					delete tempHold
				}
				if(someVar == Rupee){
					pStartRupee + tempHold
					delete tempHold
				}
				if(someVar == Real){
					pStartReal + tempHold
					delete tempHold
				}
			}else if(menu == 2){
				create temporaryHolder
				cin >> temphold

				if(someVar == Dollar){
					pStartDollar - tempHold
					delete tempHold
				}
				if(someVar == Pound){
					pStartDollar - tempHold
					delete tempHold
				}
				if(someVar == Yen){
					pStartYen - tempHold
					delete tempHold
				}
				if(someVar == Rupee){
					pStartRupee - tempHold
					delete tempHold
				}
				if(someVar == Real){
					pStartReal - tempHold
					delete tempHold
				}
			}else if(menu == 3){
				print all vars
			}else if(menu == 4){
				print all vars
				delete all vars
				exit loop ie. someTestVar == false
			}
	}
*/

#include "pch.h"
#include "currency.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	currency* pStartDollar = new Dollar(0, 0);
	currency* pStartPound = new Pound(0, 0);
	currency* pStartYen = new Yen(0, 0);
	currency* pStartRupee = new Rupee(0, 0);
	currency* pStartReal = new Real(0, 0);

	cout << "Welcome Please enter what command you want: " << endl;

	bool con = true;
	while (con == true) {
		cout << endl;
		cout << "1. Add" << endl;
		cout << "2. Subtract" << endl;
		cout << "3. Print" << endl;
		cout << "4. Exit" << endl;

		int menu = 0;
		bool testLoop = false;
		while (testLoop == false) {
			cin >> menu;
			if (menu >= 1 && menu <= 4) {
				testLoop = true;
			}
			else {
				cout << "Invalid Input Try Again: " << endl;
			}
		}

		if (menu == 1) {
			cout << endl;
			cout << "Enter Command: " << endl;
			currency* tempHold = new currency();
			tempHold = cin >> tempHold;
			string note = tempHold->getNoteName();
			cout << endl;

			if (note == "Dollar" || note == "dollar") {
				*pStartDollar = *pStartDollar + *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartDollar;
			}
			else if (note == "Pound" || note == "pound") {
				*pStartPound = *pStartPound + *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartPound;
			}
			else if (note == "Yen" || note == "yen") {
				*pStartYen = *pStartYen + *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartYen;
			}
			else if (note == "Rupee" || note == "rupee") {
				*pStartRupee = *pStartRupee + *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartRupee;
			}
			else if (note == "Real" || note == "real") {
				*pStartReal = *pStartReal + *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartReal;
			}
		}
		else if (menu == 2) {
			cout << endl;
			cout << "Enter Command: " << endl;
			currency* tempHold = new currency();
			tempHold = cin >> tempHold;
			string note = tempHold->getNoteName();
			cout << endl;
			if (note == "Dollar" || note == "dollar") {
				*pStartDollar = *pStartDollar - *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartDollar;
			}
			else if (note == "Pound" || note == "pound") {
				*pStartPound = *pStartPound - *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartPound;
			}
			else if (note == "Yen" || note == "yen") {
				*pStartYen = *pStartYen - *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartYen;
			}
			else if (note == "Rupee" || note == "rupee") {
				*pStartRupee = *pStartRupee - *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartRupee;
			}
			else if (note == "Real" || note == "real") {
				*pStartReal = *pStartReal - *tempHold;
				delete tempHold;
				cout << "Current Value: ";
				cout << *pStartReal;
			}
		}
		else if (menu == 3) {
			cout << endl;

			cout << *pStartDollar;
			cout << *pStartPound;
			cout << *pStartYen;
			cout << *pStartRupee;
			cout << *pStartReal;
		}
		else if (menu == 4) {
			cout << endl;
			cout << "Final Values: " << endl;
			cout << endl;

			cout << *pStartDollar;
			cout << *pStartPound;
			cout << *pStartYen;
			cout << *pStartRupee;
			cout << *pStartReal;

			delete pStartDollar;
			delete pStartPound;
			delete pStartReal;
			delete pStartYen;
			delete pStartRupee;

			con = false;
		}
	}

	system("pause");

	return 0;
}
