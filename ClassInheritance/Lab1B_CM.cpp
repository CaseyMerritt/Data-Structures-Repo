/*
@Lab: 1B
@Author: Casey Merritt
@Purpose: Utilize contents from lab 1A to create a Wallet that can be used to track all currencies
*/

/*
Psuedo Code:
	Main(){
		create Wallet
		cout << some menu thing
		wallet.listWalletBalance()

		While(someVar == true){
			cout << menu
			cin >> x

			if(x == 1){
				int w,p
				string note
				cin >> w,p,note
				wallet.addMoney(note,w,p)
				wallet.listWalletBalance()
			}else if(x == 2){
				int w,p
				string note
				cin >> w,p,note
				wallet.removeMoney(note,w,p)
				wallet.listWalletBalance()
			}else if(x == 3){
				wallet.listWalletBalance()
			}else if(x == 4){
				wallet.empty()
			}else if(x == 5){
				someVar = false;
			}
		}
		delete Wallet
	}
*/

#include "pch.h"
#include "currency.h"
#include "Wallet.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Wallet* myWallet = new Wallet();
	cout << "Welcome" << endl;
	cout << endl;
	myWallet->listWallet();
	cout << endl;
	cout << "What Would You Like To Do Next: " << endl;

	bool con = true;
	while (con == true) {
		cout << endl;
		cout << "1. Add To Wallet" << endl;
		cout << "2. Subtract From Wallet" << endl;
		cout << "3. List Wallet Balances" << endl;
		cout << "4. Empty Your Wallet" << endl;
		cout << "5. Exit" << endl;

		//test loop for invalid types doesn't cover everything tho
		int menu = 0;
		bool testLoop = false;
		while (testLoop == false) {
			cin >> menu;
			if (menu >= 1 && menu <= 5) {
				testLoop = true;
			}
			else {
				cout << "Invalid Input Try Again: " << endl;
			}
		}

		string note;//note type
		string coin;//coin type this is pretty much irrelevant
		int w;//Whole 
		int p;//Part
		if (menu == 1) {//add
			cout << endl;
			cout << "Please Enter Values In This Format" << endl;
			cout << "(Note Name) (Whole) (Part) (Coin Name)" << endl;
			cin >> note >> w >> p >> coin;
			cout << endl;
			cout << "Adding..." << endl;
			cout << endl;
			myWallet->addMoney(note, w, p);
			myWallet->listWallet();
		}
		else if (menu == 2) {//subtract
			cout << endl;
			cout << "Please Enter Values In This Format" << endl;
			cout << "(Note Name) (Whole) (Part) (Coin Name)" << endl;
			cin >> note >> w >> p >> coin;
			cout << endl;
			cout << "Subtracting..." << endl;
			cout << endl;
			myWallet->removeMoney(note, w, p);
			myWallet->listWallet();
		}
		else if (menu == 3) {//List
			cout << endl;
			cout << "Listing..." << endl;
			cout << endl;
			myWallet->listWallet();
		}
		else if (menu == 4) {//Empty Wallet
			cout << endl;
			cout << "Emptying Wallet..." << endl;
			cout << endl;
			myWallet->emptyWallet();
		}
		else if (menu == 5) {//Exit Case
			cout << endl;
			cout << "Thank You Come Again :D" << endl;
			cout << endl;
			con = false;
		}
	}

	//deletes every created currency in the array
	for (int i = 0; i < myWallet->getSize(); i++) {
		delete myWallet->getArrayElem(i);
	}

	//deletes the object that holds the array
	delete myWallet;

	system("pause");

	return 0;
}
