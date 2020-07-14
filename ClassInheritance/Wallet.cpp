/*
@Lab: 1B
@Author: Casey Merritt
@Purpose: Utilize contents from lab 1A to create a Wallet that can be used to track all currencies
*/

#include "pch.h"
#include "Wallet.h"
#include <string>
#include <iostream>


Wallet::Wallet()
{
	//initializing all values to 0
	for (int i = 0; i < size; i++) {
		myArray[i]->setWhole(0);
		myArray[i]->setPart(0);
	}
}


Wallet::~Wallet()
{

}

void Wallet::addMoney(std::string x, int w, int p) {
	//making searching string uniform for easier search
	if (x == "dollar") {
		x = "Dollar";
	}
	else if (x == "pound"){
		x = "Pound";
	}
	else if (x == "yen") {
		x = "Yen";
	}
	else if (x == "real") {
		x = "Real";
	}
	else if (x == "rupee") {
		x = "Rupee";
	}

	for (int i = 0; i < size; i++) {
		if (myArray[i]->getNoteName() == x) {
			currency* temp = new currency(w, p);
			*myArray[i] = *myArray[i] + *temp;
			delete temp;
		}
	}
}

void Wallet::removeMoney(std::string x, int w, int p) {
	//making searching string uniform for easier search
	if (x == "dollar") {
		x = "Dollar";
	}
	else if (x == "pound") {
		x = "Pound";
	}
	else if (x == "yen") {
		x = "Yen";
	}
	else if (x == "real") {
		x = "Real";
	}
	else if (x == "rupee") {
		x = "Rupee";
	}

	for (int i = 0; i < size; i++) {
		if (myArray[i]->getNoteName() == x) {
			currency* temp = new currency(w, p);
			*myArray[i] = *myArray[i] - *temp;
			delete temp;
		}
	}
}

void Wallet::listWallet() {
	std::cout << "Current Wallet Balances: " << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << *myArray[i];
	}
}

void Wallet::emptyWallet() {
	for (int i = 0; i < size; i++) {
		myArray[i]->setWhole(0);
		myArray[i]->setPart(0);
	}
	listWallet();
}

currency Wallet::operator[](int iter) {
	if (iter >= 0 && iter < size) {
		return *myArray[iter];
	}
	else {
		return *myArray[iter];
	}
}

currency* Wallet::getArrayElem(int iter) {
	return myArray[iter];
}

int Wallet::getSize() {
	return size;
}
