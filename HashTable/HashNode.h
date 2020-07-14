#pragma once
/*
@Lab: Lab 6 Hash Tables
@Author: Casey Merritt
@Purpose: Show my understanding of Hash Tables
*/

#include "currency.h"
#include <iostream>
#include <string>

class HashNode {
public:
	int key;
	currency* value;

	HashNode() {//constructor
		key = 0;
		value = NULL;
	}

	HashNode(int k, currency* v) {//constructor
		key = k;
		value = v;
	}

	~HashNode() {//destructor
		if (value != NULL) {
			delete value;
		}
	}

	/*method gets the value of key
	Pre:
	Post:
	Return: returns the variable key
	*/
	int getKey() {
		return key;
	}

	/*method gets the value of value
	Pre:
	Post:
	Return: returns the variable value
	*/
	currency* getValue() {
		return value;
	}
};