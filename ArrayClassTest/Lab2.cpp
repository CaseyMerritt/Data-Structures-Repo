/*
@Lab: 2
@Author: Casey Merritt
@Purpose: Demonstrate my ability to use templates as well as my understanding of the selection sort
*/

/*
PseudoCode:
	Main(){
		file.open
		initialize all other stuff

		While(somVar == true){
			cin >> size of array
			getine(preferred data type)

			if(preferred type is int){
				create template class of type int
				cin >> all elements the user wants
				recurselectionsort(int size, template class, file to print too)
				print array
				delete template class
			}else if(preferred tpye is string){
				create template class of type string
				cin >> all elements the user wants
				recurselectionsort(int size, template class, file to print too)
				print array
				delete template class
			}else if(preferred type is dollar){
				create template class of type dollar
				cin >> all elements the user wants
				recurselectionsort(int size, template class, file to print too)
				print array
				delete template class
			}

			cout << Continue?
			string x
			cin >> x
			if(x == no){
				somVar = false;			
			}else{
				do nothing lmao
			}
		
		}
		file.close
	}

	Template RecurSelectionSort(int size, Template object, file to print to){
	
	}

	DualWrite(file to print to, string to print, bool to determine endl or not){
	
	}
	
*/

#include "pch.h"
#include "ArrayTest.h"
#include "Currency.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
void RecurSelectionSort(int, ArrayTest<T>,ofstream&);
void DualWrite(ofstream&, string, bool);

int main()
{
	ofstream file;
	file.open("Output.txt");
	int SORT_MAX_SIZE = 16;
	int UserSize = 0;
	string UserInput;
	bool con = true; 
	
	while (con == true) {//continue loop
		DualWrite(file, "-----------------", false);
		DualWrite(file, "Welcome To Sorter", false);
		DualWrite(file, "-----------------", false);
		DualWrite(file, "", false);
		DualWrite(file, "Please enter number of elements you would like: ", true);

		cin >> UserSize;
		file << UserSize << endl;

		if (UserSize > SORT_MAX_SIZE) {//checking for max
			while (UserSize > SORT_MAX_SIZE) {
				DualWrite(file, "Sorry size excedes the max of 16 please try again", false);
				file << UserSize << endl;
				cin >> UserSize;//gotta get that input
			}
		}

		DualWrite(file, "Please enter your preferred data type: ", true);

		cin.ignore();//gotta get that input
		getline(cin, UserInput);
		file << UserInput << endl;

		DualWrite(file, "", false);
		DualWrite(file, "-----------------", false);
		DualWrite(file, "Building array", false);
		DualWrite(file, "-----------------", false);
		DualWrite(file, "", false);

		if (UserInput == "int" || UserInput == "Int") {//int type chosen

			ArrayTest<int> newArr(UserSize, file, UserInput);//creating template with int

			DualWrite(file, "", false);
			DualWrite(file, "Please enter your elements: ", false);

			for (int i = 0; i < UserSize; i++) {
				int x;
				cin >> x;//gotta get that input
				newArr.setArray(i, x);
				file << x << endl;
			}

			DualWrite(file, "", false);
			DualWrite(file, "Current Array: ", true);
			newArr.printArray(file);//before sort
			DualWrite(file, "", false);

			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Commencing sort", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "", false);

			RecurSelectionSort(UserSize, newArr, file);//sort start

			DualWrite(file, "", false);
			DualWrite(file, "Your final array is: ", true);
			newArr.printArray(file);//final array print
			DualWrite(file, "", false);

			delete[] newArr.getArrayLocal();//deleteing array

			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Successfully deleted array", false);
			DualWrite(file, "-----------------", false);
		}
		else if (UserInput == "String" || UserInput == "string") {//string type chosen

			ArrayTest<string> newArr(UserSize, file, UserInput);//creating template with string

			DualWrite(file, "", false);
			DualWrite(file, "Please enter your elements: ", false);

			for (int i = 0; i < UserSize; i++) {
				string x;
				getline(cin, x);//gotta get that input
				newArr.setArray(i, x);
				file << x << endl;
			}

			DualWrite(file, "", false);
			DualWrite(file, "Current Array: ", true);
			newArr.printArray(file);//before sort
			DualWrite(file, "", false);

			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Commencing sort", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "", false);

			RecurSelectionSort(UserSize, newArr, file);//start sort

			DualWrite(file, "", false);
			DualWrite(file, "Your final array is: ", true);
			newArr.printArray(file);//final print
			DualWrite(file, "", false);

			delete[] newArr.getArrayLocal();//deleting array

			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Successfully deleted array", false);
			DualWrite(file, "-----------------", false);
		}
		else if (UserInput == "Dollar" || UserInput == "dollar") {

			ArrayTest<Dollar> newArr(UserSize, file, UserInput);//creating template with dollar type
			
			DualWrite(file, "", false);
			DualWrite(file, "Use format: dollar (Whole) (Part) cent", false);
			DualWrite(file, "Please enter your elements: ", false);

			for (int i = 0; i < UserSize; i++) {
				Dollar x;
				cin >> x;//gotta get that input
				newArr.setArray(i, x);
				file << x << endl;
			}

			DualWrite(file, "", false);
			DualWrite(file, "Current Array: ", true);
			newArr.printArray(file);//before sort
			DualWrite(file, "", false);

			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Commencing sort", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "", false);

			RecurSelectionSort(UserSize, newArr, file);//starting sort

			DualWrite(file, "", false);
			DualWrite(file, "Your final array is: ", true);
			newArr.printArray(file);//final print
			DualWrite(file, "", false);

			delete[] newArr.getArrayLocal();//deleteing array

			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Successfully deleted array", false);
			DualWrite(file, "-----------------", false);
		}

		DualWrite(file, "", false);
		DualWrite(file, "", false);
		DualWrite(file, "Would you like to sort another array? (Yes or No)", false);

		string x;

		if (UserInput == "String" || UserInput == "string") {
			getline(cin, x);//last...gotta get that input
			file << x << endl;
		}
		else {
			cin.ignore();
			getline(cin, x);//last...gotta get that input
			file << x << endl;
		}

		if (x == "no" || x == "No") {//exit case

			DualWrite(file, "", false);
			DualWrite(file, "", false);
			DualWrite(file, "-----------------", false);
			DualWrite(file, "Exiting Program", false);
			DualWrite(file, "-----------------", false);

			con = false;//breaks while loops 
		}

		DualWrite(file, "", false);//just formatting here lol
		DualWrite(file, "", false);
	}

	file << endl;
	file << "@lab: 2 output.txt" << endl;
	file << "@Author: Casey Merritt" << endl;
	file << "@idk what else to write for my Identifying info haha" << endl;
	file.close();//end baby hopefully it worked :P

	system("pause");
	
}

//selection sort op. Had to send extra file parameter here so I can keep using my sick function dualwrite
template <typename T>
void RecurSelectionSort(int size, ArrayTest<T> printVar, ofstream& file) {

	/*
	//using functions I set up for easy troubleshooting of the
	//sort itself before trying the operator you can ignore this
	int posSave = 0;
	T biggest = printVar.getArrayElem(0);
	for (int i = 0; i < size; i++) {
		if (printVar.getArrayElem(i) > biggest) {
			biggest = printVar.getArrayElem(i);
			posSave = i;
		}
	}

	T temp = printVar.getArrayElem(size - 1);
	printVar.setArray((size - 1), biggest);
	printVar.setArray(posSave, temp);
	*/

	//using overloaded [] operator
	int posSave = 0;
	T biggest = printVar[0];
	for (int i = 0; i < size; i++) {
		if (printVar[i] > biggest) {
			biggest = printVar[i];
			posSave = i;
		}
	}

	T temp = printVar[size - 1];
	printVar[size - 1] = biggest;
	printVar[posSave] = temp;

	//printing
	DualWrite(file, "", false);
	DualWrite(file, "Current Array: ", true);
	printVar.printArray(file);
	DualWrite(file, "", false);

	//iterating down one
	size--;

	if (size > 1) {
		RecurSelectionSort(size, printVar, file);
	}

}

//im too lazy to write multiple outputs so this streamlines it
void DualWrite(ofstream& out, string s, bool x) {
	if (x == false) {//false if I want endl for screen
		out << s << endl;
		cout << s << endl;
	}
	else {//true if I dont want endl for screen
		out << s << endl;
		cout << s;
	}
}
