/*
@Lab: 1B
@Author: Casey Merritt
@Purpose: Utilize contents from lab 1A to create a Wallet that can be used to track all currencies
*/

#pragma once
#include "currency.h"
#include <string>
#include <iostream>

class Wallet
{
private:
	const static int size = 5;
	currency* myArray[size] = { new Dollar, new Pound, new Yen, new Real, new Rupee };
public:
	Wallet();
	~Wallet();

	/*method adds money to balance based on input
	Pre: passes string x, int w and int p
	Post:
	Return:
	*/
	void addMoney(std::string x, int w, int p);

	/*method removes money from balance based on input
	Pre: passes string x, int w and int p
	Post:
	Return:
	*/
	void removeMoney(std::string x, int w, int p);

	/*method displays all the values of Wallet to the screen
	Pre: 
	Post:
	Return:
	*/
	void listWallet();

	/*method empties the values of Wallet
	Pre:
	Post:
	Return:
	*/
	void emptyWallet();

	/*method is an overloading operator allowing for easy access to the array saved in memory
	Pre: passes int iterator
	Post:
	Return: Returns a currency object
	*/
	virtual currency operator[](int iter);

	/*method returns currency objects at a specific point in the array
	Pre: passes int iterator
	Post:
	Return: Returns a pointer to a currency object
	*/
	currency* getArrayElem(int iter);

	/*method returns the size of the array
	Pre: 
	Post:
	Return: Returns the size of the array
	*/
	int getSize();
};

