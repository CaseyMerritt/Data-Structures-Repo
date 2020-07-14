/*
@Lab: Lab 3 Iteration Vs Recursion
@Author: Casey Merritt
@Purpose: Show our understanding of the differences between iteration and recursion

@PseudoCode:
	while(true){
		while(true){
			cin >> sizeInput

			if(size < 1 or size > max){
				print(try again!)
			}else{
				break
			}
		}

		int* arr = new int[size]

		for(i < size){
			while(true){
				cin >> arr[i]

				if(arr[i] >= 1 and arr[i] <= 99){
					break
				}else{
					print(try again!)
				}
			}
		}

		IsPrimeIter(some shit)
		IsPrimeRecur(some shit)

		delete[] arr

		while(true){
			getline(cin, x)

			if(x is Yes or yes){
				break
			}else if(x is No or no){
				break//this looop
				break//main while loop
			}else{
				print(try again!)
			}
		}
		system.pause
	}
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <memory> 

using namespace std;

bool IsArrayPrimeIter(int, int[]);
bool IsArrayPrimeRecur(int, int[], bool);
void IsPrimeRecurHelper(int, int, int, bool&);

int main()
{
	int SORT_MAX_SIZE = 16;
	int UserSize;

	bool con = true;//main loop exit case

	while (con == true) {

		bool validation = true;

		while (validation == true) {//validating correct size

			cout << "How Many elements do you want: ";
			cin >> UserSize;

			if (UserSize < 1 || UserSize > SORT_MAX_SIZE) {
				cout << "Invalid Input Values Must Be Between 1 And 16" << endl;
				cout << "Try Again!" << endl;
			}
			else{
				validation = false;//break this loop
			}
		}

		int* arr;
		arr = new int[UserSize];//dynamic array allocation

		for (int i = 0; i < UserSize; i++) {

			bool testForInvalid = true;//probably should start using breaks instead :P

			while (testForInvalid == true) {//loop for checking input values between 1 and 99

				cout << "Enter Element " << i + 1 << " : ";
				cin >> arr[i];

				if (arr[i] >= 1 && arr[i] <= 99) {
					testForInvalid = false;//break this loop
				}
				else {
					cout << "Wrong Input Value Must Be Between 1 And 99" << endl;
					cout << "Try Again!" << endl;
				}
			}
		}

		cout << endl;
		cout << "---------------------------------" << endl;
		IsArrayPrimeIter(UserSize, arr);
		cout << "---------------------------------" << endl;
		IsArrayPrimeRecur(UserSize, arr, true);
		cout << "---------------------------------" << endl;
		cout << endl;

		delete[] arr;//gotta save dat memory

		cin.ignore();

		string endCase;

		bool testHere = false;

		while (testHere == false) {//loop for continuation
			cout << "Do You Want To Continue?(Yes or No): ";
			getline(cin, endCase);

			if (endCase == "Yes" || endCase == "yes") {
				cout << endl;
				cout << "Restarting Program..." << endl;
				cout << endl;
				testHere = true;//break this loop
			}
			else if(endCase == "No" || endCase == "no"){
				cout << endl;
				cout << "Exiting Program..." << endl;
				cout << endl;
				con = false;//break main loop for exit case
				testHere = true;//break this loop
			}
			else {
				cout << endl;
				cout << "Wrong Input Try Again" << endl;
				cout << endl;
			}
		}
	}

	system("pause");//not gonna forget my pause like the midterm D:
}

/*
	@Psuedocode:
	IsArrayPrimeIter(int size, int arr[]){
		print(entering)

		bool var = true

		for(i = 0; i < size; i++){
			int someVar = arr[i] / 2
			for(j = 2; j <= someVar; j++){
				if(arr[i] % j is 0){
					var = false
					break inner loop
				}
			}
			if(var is false){
				break outer loop
			}
		}

		if(var is true){
			print(prime array)
		}else{
			print(not prime array)
		}

		print(leaving)
	}

	Pre:Takes in int for array size, the integer array itself
	Post: none
	Return: none
*/
bool IsArrayPrimeIter(int size, int arr[]) {
	cout << "~ Entering IsArrayPrimeIter ~" << endl;
	cout << endl;

	bool isPrime = true;

	for (int i = 0; i < size; i++) {
		int test = arr[i] / 2;
		for (int j = 2; j <= test; j++) {
			if (arr[i] % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime == false) {
			break;
		}
	}


	if (isPrime == true) {
		cout << "Prime array using iteration" << endl;
	}
	else {
		cout << "Not a prime array using iteration" << endl;
	}

	cout << endl;
	cout << "~ Leaving IsArrayPrimeIter ~" << endl;
	cout << endl;

	return isPrime;
}

/*
	@Note to self:Recur for this use case is like 50x harder finished the iteration function in 5 mins
	this one took me like an hour D:

	@Psuedocode:
	IsArrayPrimeRecur(int size, int arr[], bool var){
		print(entering)

		if(var is false){
			break recursive call
		}else{
			inner loop recursive call
			size--
		}

		if(size is 0){
			if(var is true){
				print(prime array)
			}else{
				print(not prime array)
			}
		}else{
			outer loop recursive call
		}
	}
	print(leaving)

	Pre:Takes in int for array size, the integer array itself, and a boolean for checking array between calls
	Post: none
	Return: none
*/
bool IsArrayPrimeRecur(int size, int arr[], bool holder) {
	cout << endl;
	cout << "~ Entering IsArrayPrimeRecur ~" << endl;
	cout << endl;

	int newSize = size;
	bool isPrime = holder;

	if (isPrime == false) {//initial array check for early break so we don't have to keep going
		newSize = 0;
	}
	else {
		IsPrimeRecurHelper(2, arr[size - 1] / 2, arr[size - 1], isPrime);//initializing inner recursive loop call
		newSize--;
	}

	if (newSize == 0) {//main prime checker
		if (isPrime == true) {
			cout << "Prime array using recursion" << endl;
			cout << endl;
			cout << "~ Leaving IsArrayPrimeRecur ~" << endl;
			cout << endl;
			return isPrime;
		}
		else {
			cout << "Not a prime array using recursion" << endl;
			cout << endl;
			cout << "~ Leaving IsArrayPrimeRecur ~" << endl;
			cout << endl;
			return isPrime;
		}
	}
	else {
		cout << endl;
		cout << "~ Leaving IsArrayPrimeRecur ~" << endl;
		cout << endl;

		IsArrayPrimeRecur(newSize, arr, isPrime);//recursive call outer loop
	}
}

/*
	@Note: Inner loop used to recursively check every integer as a divisor
	if none of the integers checked results in 0 number is prime
*/
void IsPrimeRecurHelper(int j, int x, int num, bool& isPrime) {
	if (j <= x) {
		if (num % j == 0) {
			isPrime = false;
		}
		else {
			j++;
			IsPrimeRecurHelper(j, x, num, isPrime);//inner loop recur call
		}
	}
}