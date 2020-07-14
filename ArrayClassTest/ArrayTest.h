/*
@Lab: 2
@Author: Casey Merritt
@Purpose: Demonstrate our ability to use templates as well as our understanding of the selection sort
*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>


template <typename T> class ArrayTest
{
private:
	int size; 
	T *myArray;
public:
	ArrayTest(int s, std::ofstream& x, std::string i);

	~ArrayTest();

	/*method sets an element in the array based on input
	Pre: takes in iter for pos and x the value to add
	Post:
	Return:
	*/
	void setArray(int iter, T x);

	/*method gets an element in the array based on input
	Pre: takes in iter for pos
	Post:
	Return: returns template element in the array at position iter
	*/
	T getArrayElem(int iter);

	/*method prints the array to both txt file and screen
	Pre: takes x which is the file to print too
	Post:
	Return:
	*/
	void printArray(std::ofstream& x);

	/*method returns the pointer to the array
	Pre: 
	Post:
	Return: returns the pointer to the array
	*/
	T* getArrayLocal();

	/*method is an overloading operator for []
	Pre: takes in iter which is the position in the array we want
	Post:
	Return: returns the template object at position iter in the array
	*/
	virtual T& operator[](int iter);
};

template <typename T>
ArrayTest<T>::ArrayTest(int s, std::ofstream& x, std::string i) {
	size = s;
	myArray = new T[size];
	if (i == "string" || i == "String") {//typeid.name for string is stupid so i'm using this to fix output
		std::cout << "Successfully created a string array with " << size << " elements" << std::endl;
		x << "Successfully created a(n) string array with " << size << " elements" << std::endl;
	}
	else if (i == "dollar" || i == "Dollar") {//typeid.name for dollar class is also stupid so i'm using this to fix output
		std::cout << "Successfully created a dollar array with " << size << " elements" << std::endl;
		x << "Successfully created a(n) dollar array with " << size << " elements" << std::endl;
	}
	else {//typeid.name actually works for this one crazy
		std::cout << "Successfully created a(n) " << typeid(myArray[0]).name() << " array with " << size << " elements" << std::endl;
		x << "Successfully created a(n) " << typeid(myArray[0]).name() << " array with " << size << " elements" << std::endl;
	}
}

template <typename T>
ArrayTest<T>::~ArrayTest() {
}

//deprecated because of implementation of overloading operator
template <typename T>
void ArrayTest<T>::setArray(int iter, T x) {
	myArray[iter] = x;
}

//deprecated because of implementation of overloading operator
template <typename T>
T ArrayTest<T>::getArrayElem(int iter) {
	return myArray[iter];
}

//prints array to both txt doc and screen
template <typename T>
void ArrayTest<T>::printArray(std::ofstream& x) {
	for (int i = 0; i < size; i++) {
		std::cout << myArray[i] << " ";
		x << myArray[i] << " ";
	}
	std::cout << std::endl;
	x << std::endl;
}

//deprecated because of implementation of overloading operator
template <typename T>
T* ArrayTest<T>::getArrayLocal() {
	return  myArray;
}

//overloading operator[] for easier sorting
template <typename T>
T& ArrayTest<T>::operator[](int iter) {
	if (iter >= 0 && iter < size) {
		return myArray[iter];
	}
	else {
		return myArray[0];
	}
}

