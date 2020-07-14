/*
@Lab: Lab 6 Hash Tables
@Author: Casey Merritt
@Purpose: Show my understanding of Hash Tables

@Pseudocode:
	int main(){
		string x
		getling(cin, x)

		ifstream myFile
		myFile.open(x)

		string line
		while(getline(myFile, line)){
			count++
		}

		myFile.close()

		ifstream ifile
		ifile.open(x)

		hashtable table(29)

		for(int i; i < count; i++){
			ifile >> y
			table.insert(y)
		}

		table.getCollisions
		table.getLoadFactor

		bool mainLoop = true
		while(mainLoop){
			cout << choose
			cout << 1. insert
			cout << 2. remove
			cout << 3. search
			cout << 4. print
			cout << 5. exit

			cin >> input

			if(input = 1){
				cin >> y
				table.insert(y)
			}else if(input = 2){
				cin >> y
				table.remove(y)
			}else if(input = 3){
				cin >> y
				table.search(y)
			}else if(input = 4){
				table.print()
			}else if(input = 5){
				cout << bye!
				mainLoop = false
			}else{
				cout << try again!
			}
		}

		ifile.close()
		delete table
		system(pause)
		return 0
	}
*/

#include "pch.h"
#include "currency.h"
#include "HashTable.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string x;
	cout << "Enter Input File Location: " << endl;
	getline(cin, x);

	ifstream myFile;
	myFile.open(x);

	int count = 0;
	string line;
	while (getline(myFile, line)) {
		count++;
	}

	myFile.close();

	ifstream ifile;
	ifile.open(x);

	HashTable* table = new HashTable(29);

	for (int i = 0; i < count; i++) {
		currency* y = new currency;
		ifile >> y;
		table->insert(y);
	}

	cout << endl;
	cout << table->getCount() << " Values Have Been Imported From: " << endl;
	cout << x << endl;

	cout << endl;
	table->getCollisions();
	cout << endl;
	table->loadFactor();
	cout << endl;
	cout << endl;

	cout << "------- Welcome To The Hash Table Helper -------" << endl;
	cout << endl;

	bool mainLoop = true;
	while (mainLoop) {
		cout << "What Would You Like To Do: " << endl;
		cout << "1. Insert" << endl;
		cout << "2. Remove(Place Holder doesn't do anything)" << endl;
		cout << "3. Search" << endl;
		cout << "4. Print" << endl;
		cout << "5. Exit" << endl;

		int input = 0;
		cin >> input;

		if (input == 1) {
			cout << endl;
			cout << "Enter The Value To Insert: " << endl;
			currency* y = new currency;
			cin >> y;

			table->insert(y);
			cout << endl;
		}
		else if (input == 2) {
			cout << endl;
			cout << "Enter The Value To Remove: " << endl;
			currency* y = new currency;
			cin >> y;

			//table->remove(y);
			cout << endl;
		}
		else if (input == 3) {
			cout << endl;
			cout << "Enter The Value To Search For: " << endl;
			currency * y = new currency;
			cin >> y;

			table->search(y, true);
			cout << endl;
		}
		else if (input == 4) {
			cout << endl;
			table->getCollisions();
			cout << endl;
			table->loadFactor();
			cout << endl;
			table->printTable();
			cout << endl;
		}
		else if (input == 5) {
			cout << endl;
			cout << "Thank You Please Come Again!" << endl;
			cout << endl;
			mainLoop = false;
		}
		else {
			cout << endl;
			cout << "Invalid Input Please Try Again" << endl;
			cout << endl;
		}
	}

	ifile.close();

	delete table;
	cout << endl;

	system("pause");
	return 0;
}

