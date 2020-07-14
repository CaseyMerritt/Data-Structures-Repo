#pragma once
/*
@Lab: Lab 6 Hash Tables
@Author: Casey Merritt
@Purpose: Show my understanding of Hash Tables
*/


#include "HashNode.h"
#include "currency.h"
#include <iostream>
#include <string>

class HashTable {
private:
	HashNode** arr;
	int tableSize;
	int count;
	int collisions;
	double lf;
public:
	HashTable(int size) {//constructor
		tableSize = size;
		arr = new HashNode*[tableSize];
		for (int i = 0; i < tableSize; i++) {
			arr[i] = NULL;
		}

		count = 0;
		collisions = 0;
		lf = 0;
	}

	~HashTable() {//destructor
		for (int i = 0; i < tableSize; i++) {
			delete arr[i];
		}
		delete[] arr;
		std::cout << "Deleted Table" << std::endl;
	}

	/*method gets the value of count
	Pre:
	Post:
	Return: returns the variable count
	*/
	int getCount();

	/*method gets the value of collisions
	Pre:
	Post:
	Return: returns the variable collisions
	*/
	int getCollisions();

	/*method gets the value of lf
	Pre:
	Post:
	Return: returns the variable lf
	*/
	double loadFactor();

	/*method returns the index of the key given
	Pre:takes in ptr to a currency object
	Post:
	Return: returns the index
	*/
	int hashFunc(currency* v);

	/*method does quadratic probe resolutions
	Pre: takes in a key of type int
	Post:
	Return: returns the variable key
	*/
	int QuadProbeResolution(int k);

	/*method inserts data into the hash table
	Pre: takes in a ptr to a currency object
	Post:
	Return:
	*/
	void insert(currency* v);

	/*method searches for value given
	Pre: takes in a ptr to a currency object and a bool for printing
	Post:
	Return: returns a bool t/f
	*/
	bool search(currency* v, bool x);

	/*method searches with specified key
	Pre: takes in an int key
	Post:
	Return: returns a bool t/f
	*/
	bool searchKey(int key);

	/*method removes a value
	Pre: takes in ptr to a currency object
	Post:
	Return:
	*/
	void remove(currency* v);

	/*method prints the hash table
	Pre:
	Post:
	Return:
	*/
	void printTable();

};

/*
-- returns count
*/
int HashTable::getCount() {
	return count;
}

/*
-- returns collisions
*/
int HashTable::getCollisions() {
	std::cout << "We Had " << collisions << " Collisions!" << std::endl;
	return collisions;
}

/*
-- returns load factor
*/
double HashTable::loadFactor() {
	double loaded = 0;
	for (int i = 0; i < tableSize; i++) {
		if (arr[i] != NULL) {
			loaded++;
		}
	}
	lf = (loaded / tableSize) * 100;
	std::cout << "Current Load Factor Is: %" << lf << std::endl;
	return lf;
}

/*
-- does hash func shit
*/
int HashTable::hashFunc(currency* v) {
	return(((2 * v->getWhole()) + (3 * v->getPart())) % tableSize);
}

/*
-- quadratic probe resolution
*/
int HashTable::QuadProbeResolution(int key) {
	int k = key;
	for (int i = 0; i < tableSize; i++) {
		k = ((k + (i * i)) % tableSize);
		if (searchKey(k) == true) {
			collisions++;
		}
		else {
			break;
		}
		k = ((k - (i * i)) % tableSize);
		if (k < 0) {
			k = (tableSize + k);
			if (searchKey(k) == true) {
				collisions++;
			}
			else {
				break;
			}
		}else{
			if (searchKey(k) == true) {
				collisions++;
			}
			else {
				break;
			}
		}
	}

	return k;
}

/*
-- Inserts data into hash table
*/
void HashTable::insert(currency* v) {
	int key = hashFunc(v);
	if (arr[key] == NULL) {
		arr[key] = new HashNode(key, v);
		count++;
	}
	else {
		key = (2 * v->getWhole()) + (3 * v->getPart());
		key = QuadProbeResolution(key);
		if (arr[key] == NULL) {
			arr[key] = new HashNode(key, v);
			count++;
		}
		else {
			std::cout << std::endl;
			std::cout << "Hash Table Full!" << std::endl;
			std::cout << "Unable To Insert: ";
			std::cout << *v << std::endl;
		}
	}
}

/*
-- searches hash table for value
*/
bool HashTable::search(currency* v, bool x) {
	int index = 0;
	bool temp = false;
	for (int i = 0; i < tableSize; i++) {
		if (arr[i] != NULL) {
			currency* y = arr[i]->value;
			y->getWhole();
			double t = y->getPart();
			double x = v->getPart();
			t = (t / 100);
			x = (x / 100);
			t = t + y->getWhole();
			x = x + v->getWhole();
			if (x == t) {
				temp = true;
				index = i;
				break;
			}
		}
	}
	std::cout << std::endl;

	if (x == true && temp == true) {
		std::cout << "Value Found @ Index: " << index << std::endl;
		return temp;
	}
	else if(x == true && temp == false){
		std::cout << "Invalid Data" << std::endl;
		return temp;
	}
	else {
		return temp;
	}
}

/*
-- searches hash table for key
*/
bool HashTable::searchKey(int key) {
	if (arr[key] != NULL) {
		return true;
	}
	else {
		return false;
	}
}

/*
-- removes value from hash table
*/
void HashTable::remove(currency* v) {//doesn't work with probing
	if (search(v, false) == true) {
		int key = hashFunc(v);
		delete arr[key];
		arr[key] = NULL;
	}
}

/*
-- prints hash table with NULLs
*/
void HashTable::printTable() {
	std::cout << "Values Loaded In The Hash: " << std::endl;
	for (int i = 0; i < tableSize; i++) {
		if (arr[i] != NULL) {
			currency* yeet = arr[i]->value;
			std::cout << *yeet << " ";
		}
		else {
			std::cout << "NULL ";
		}
	}
	std::cout << std::endl;
}