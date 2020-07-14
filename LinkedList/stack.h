/*
@Lab: Lab 4 lists, stacks and queues
@Authors: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of Stacks
*/

#ifndef stack_h
#define stack_h

#include "linkedlist.h"
#include <iostream>

template <typename T>
class stack : LinkedList<T> {
private:
	LinkedNode<T>* top;
	LinkedNode<T>* bottom;
	int count;

public:
	stack() {
		top = NULL;
		bottom = NULL;
		count = 0;
	}

	~stack() {
		if ((top == NULL) && (bottom == NULL)) {//stack is empty

		}
		else {
			std::cout << "Deleting stack\n";//deletes stack if not already empty
			emptyStack();
		}
	}
	/*
	 Pre:function gets passed data value of type T to add on top of stack
	 Post:calls SetNext and passes top value, calls SetData and passes data value
	 Return:
	 */
	void push(T data);
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void pop();
	/*
	 Pre:
	 Post:
	 Return:function returns top node in stack, of type LinkedNode<T>
	 */
	LinkedNode<T>* peek();
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void emptyStack();
	/*
	 Pre:
	 Post:
	 Return:
	 */
	void printStack();
};

/*
-- adds node to top of stack
*/
template <typename T>
void stack<T>::push(T data) {
	LinkedNode<T>* n = new LinkedNode<T>;
	n->SetData(data);

	if ((top == NULL) && (bottom == NULL)) {//stack is empty
		top = n;//setting the top and bottom values to node
		bottom = n;
	}

	else {
		n->SetNext(top);//makes top the next value to new node
		top = n;//new node becomes new top
	}
	count++;
}

/*
-- removes top node in stack
*/
template <typename T>
void stack<T>::pop() {

	if ((top == NULL) && (bottom = NULL)) {//stack is empty
		std::cout << "Nothing in stack to remove" << std::endl;
	}

	else if (top == bottom) {//stack only has one value
		delete top;
		top = NULL;
		bottom = NULL;
		count--;
	}

	else {
		LinkedNode<T>* temp = top->GetNext();//saving current top's next value
		delete top;//removing the top
		top = temp;//saved value becomes new top
		count--;
	}
}

/*
-- prints current top node in stack without removing/popping
*/
template <typename T>
LinkedNode<T>* stack<T>::peek() {
	if ((top == NULL) && (bottom == NULL)) {//stack is empty
		std::cout << "The stack is empty" << std::endl;
	}

	else if (top == NULL) {//accounts for not setting top node in stack error
		std::cout << "The top node is not set" << std::endl;
	}

	else {
		std::cout << std::endl << "Top value: " << top->GetData() << std::endl;//prints the current top in stack
		return top;
	}
	return NULL;
}

/*
-- empties the entire stack
*/
template <typename T>
void stack<T>::emptyStack() {
	LinkedNode<T>* n = top;
	if ((top == NULL) && (bottom == NULL)) {
		std::cout << "Stack is already empty" << std::endl;//stack is empty
	}
	else {
		for (int i = 0; i < count; i++) {//stepping through stack
			LinkedNode<T>* temp = n->GetNext();//save node next to top
			delete n;//delete top
			n = temp;//make the next node the new top
		}
		top = NULL;
		bottom = NULL;
		count = 0;
		std::cout << std::endl << "Stack cleared" << std::endl;
	}
}
/*
--prints the entire stack
*/
template <typename T>
void stack<T>::printStack() {
	LinkedNode<T>* n = top;
	if ((top == NULL) && (bottom == NULL)) {//stack is empty
		std::cout << "Stack is empty" << std::endl;
	}

	else {
		std::cout << std::endl;
		for (int i = 0; i < count; i++) {
			std::cout << n->GetData() << std::endl;
			n = n->GetNext();
		}
	}
}


#endif /* stack_h */
