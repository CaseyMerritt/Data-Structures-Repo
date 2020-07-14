/*
@Lab: Lab 4 lists, stacks and queues
@Authors: Casey Merritt, Revanth Cherukuri
@Purpose: Show our Knowledge of Queues,stacks and linked lists

@Contribution: Partner is Revanth Cherukuri, His contribution was HIGH

@PseudoCode:
	int main(){
		LinkedList* l = new LinkedList of type int
		stack* s = new stack of type currency
		queue* q = new queue of type string

		int input = 0
		cin >> input

		for(i < input){
			int x = 0
			cin >> x
			l.insert(x)
		}

		l.print()
		l.insert(something)
		l.print()
		l.remove(something)
		l.print()
		l.findData(something)
		l.isListEmpty()
		l.emptyList()
		l.isListEmpty()
		l.print()

		cin >> input

		for(i < input){
			currency x
			cin >> x
			s.push(x)
		}

		s.print()
		s.push(something)
		s.print()
		s.pop()
		s.print()
		s.peek()
		s.emptyStack()
		s.print()

		cin >> input

		for(i < input){
			string x
			cin >> x
			q.enqueue(x)
		}

		q.print()
		q.enqueue(something)
		q.print()
		q.dequeue()
		q.print()
		q.peekFront()
		q.peekRear()
		q.emptyQueue()
		q.print()

		delete l
		delete q
		delete s

		system pause
	}
*/

#include "pch.h"
#include "linkedlist.h"
#include "queue.h"
#include "Currency.h"
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "------ Welcome To List Showcaser ------" << endl;
	cout << endl;
	cout << "Building lists..." << endl;

	LinkedList<int>* l = new LinkedList<int>;
	stack<currency>* s = new stack<currency>;
	queue<string>* q = new queue<string>;

	cout << "Build successful" << endl;

	cout << endl;
	int userInput = 0;
	cout << "How many nodes would you like to start your linked list with: ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++) {
		int x = 0;
		cout << "Enter value " << i + 1 << ": ";
		cin >> x;
		l->insert_end(x);
	}

	cout << endl;
	cout << "Current Linked List: " << endl;
	l->printList();

	cout << endl;
	cout << "---Start of Linked List tests---\n\n";

	cout << "Inserting 40 and 61..." << endl;
	l->insert_end(40);//testing end insert---------------------- currently working
	l->insert_end(61);//^^^^^----------------------------------- currently working

	l->printList();
	cout << endl;

	cout << "Inserting 10 at beginning of List" << endl;
	l->insert_start(10);//testing start insert------------------ currently working
	l->printList();
	cout << endl;

	cout << "Inserting 45 @ position 3" << endl;
	l->insert_pos(45, 2);//testing positional insert------------ currently working
	l->printList();
	cout << endl;

	cout << "Inserting 99 @ position 5" << endl;
	l->insert_pos(99, 4);//^^^^^-------------------------------- currently working
	l->printList();
	cout << endl;

	cout << "Inserting 100 @ position 3" << endl;
	l->insert_pos(100, 2);//testing pos re-insert--------------- currently working

	l->printList();//testing print------------------------------ currently working

	cout << endl;
	cout << endl;

	cout << "Removing 1st postion from list" << endl;
	l->remove(0);//testing remove with first element------------ currently working
	l->printList();
	cout << endl;

	cout << "Removing 4th position from list" << endl;
	l->remove(3);//testing remove with middle elements---------- currently working
	l->printList();
	cout << endl;

	cout << "Removing 4th position from list" << endl;
	l->remove(3);//testing remove with last element------------- currently working
	l->printList();
	cout << endl;

	cout << "Removing Out of range position from list" << endl;
	l->remove(10);//testing remove with element out of range---- currently working
	l->printList();
	cout << endl;

	cout << "Removing new 1st position from list" << endl;
	l->remove(0);//testing remove with new first element-------- currently working
	l->printList();

	cout << endl;
	cout << endl;

	cout << "Checking for value of 9 in data" << endl;
	l->findData(9);//not in list test -------------------------- currently working
	cout << endl;

	cout << "Checking for value of 65 in data" << endl;
	l->findData(100);//in list test ----------------------------- currently working
	cout << endl;

	cout << "Checking whether list is empty or not" << endl;
	l->isListEmpty();//testing for true case ------------------- currently working
	cout << endl;

	cout << "Emptying List..." << endl;
	l->emptyList();//empty list test --------------------------- currently working
	cout << endl;

	cout << "Checking for value in empty list" << endl;
	l->findData(10);//testing for empty list indicator here ---- currently working
	cout << endl;

	cout << "Checking if list is empty" << endl;
	l->isListEmpty();//testing for false case here ------------- currently working
	cout << endl;

	cout << "---End of Linked List tests---\n\n";


	cout << endl;
	cout << "How many nodes would you like in your Stack: ";
	cin >> userInput;

	for (int i = 0; i < userInput; i++) {
		currency* x = new currency();
		cout << "Enter Values In Format (Dollar *whole* *Part* Cents)" << endl;
		cout << "Enter value " << i + 1 << ": ";
		cin >> x;
		s->push(*x);
	}

	cout << endl;
	cout << "Current Stack: " << endl;
	s->printStack();
	cout << endl;
	cout << "---Start of Stack tests---\n\n";
	currency x;
	x.setWhole(1);
	x.setPart(25);
	cout << "Pushing $1.25 onto stack" << endl;
	s->push(x);//testing push----------------------------------- currently working
	s->printStack();
	cout << endl;

	x.setWhole(2);
	x.setPart(40);
	cout << "Pushing $2.40 onto stack" << endl;
	s->push(x);//^^^-------------------------------------------- currently working
	s->printStack();
	cout << endl;

	x.setWhole(4);
	x.setPart(10);
	cout << "Pushing $4.10 onto stack" << endl;
	s->push(x);//^^^-------------------------------------------- currently working
	s->printStack();//testing print----------------------------- currently working
	cout << endl;

	cout << "Popping the stack" << endl;
	s->pop();//testing pop-------------------------------------- currently working
	s->printStack();

	cout << endl;
	cout << "Peeking onto the stack" << endl;
	s->peek();//testing peek------------------------------------ currently working
	cout << endl;

	x.setWhole(5);
	x.setPart(99);
	cout << "Pushing $5.99 onto stack" << endl;
	s->push(x);//pushing again---------------------------------- currently working
	s->printStack();

	s->emptyStack();//clear/empty test-------------------------- currently working
	cout << endl;

	cout << "Printing..." << endl;
	s->printStack();//testing print after clearing stack-------- currently working

	cout << endl;
	cout << "---End of Stack tests---\n\n";




	cout << endl;
	cout << "How many nodes would you start your Queue with: ";
	cin >> userInput;
	cin.ignore();

	for (int i = 0; i < userInput; i++) {
		string x;
		cout << "Enter value " << i + 1 << ": ";
		getline(cin, x);
		q->enqueue(x);

	}

	cout << endl;
	cout << "Current Queue: " << endl;
	q->printQueue();
	cout << endl;

	cout << "---Start of Queue tests---\n\n";

	cout << "Enqueueing Casey" << endl;
	q->enqueue("Casey");//enqueue test ---------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Enqueueing Stanley" << endl;
	q->enqueue("Stanley");//^^ ------------------------------ currently working
	q->printQueue();
	cout << endl;

	cout << "Enqueueing Tony" << endl;
	q->enqueue("Tony");//^^ --------------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Enqueueing Revanth" << endl;
	q->enqueue("Revanth");//^^ ------------------------------ currently working
	q->printQueue();
	cout << endl;

	cout << "Enqueueing Randy" << endl;
	q->enqueue("Randy");//^^ -------------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Peeking @ front node" << endl;
	q->peekFront();//front peek test ------------------------ currently working
	cout << endl;

	cout << "Peeking @ rear node" << endl;
	q->peekRear();//rear peek test -------------------------- currently working
	cout << endl;

	cout << "Looking for Bob in Queue" << endl;
	q->findValInQueue("Bob");//find val false test case ----- currently working
	cout << endl;

	cout << "Looking for Casey in Queue" << endl;
	q->findValInQueue("Casey");//find val true test case ---- currently working
	cout << endl;

	cout << "Dequeueing" << endl;
	q->dequeue();//dequeue test ----------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Dequeueing" << endl;
	q->dequeue();//^^ --------------------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Dequeueing" << endl;
	q->dequeue();//^^ --------------------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Dequeueing" << endl;
	q->dequeue();//^^ --------------------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Dequeueing" << endl;
	q->dequeue();//^^ --------------------------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Peeking @ front node" << endl;
	q->peekFront();//front peek empty test case ------------- currently working
	cout << endl;

	cout << "Enqueueing Bob, Randy and Jeremy" << endl;
	q->enqueue("Bob");//enqueue test ------------------------ currently working
	q->enqueue("Randy");//enqueue test ---------------------- currently working
	q->enqueue("Jeremy");//enqueue test --------------------- currently working
	q->printQueue();
	cout << endl;

	cout << "Clearing Queue..." << endl;
	q->clearQueue();//clear queue test ---------------------- currently working

	cout << "Printing Queue..." << endl;
	q->printQueue();//print queue empty test case ----------- currently working
	cout << endl;

	cout << "---End of Queue tests---\n\n";

	cout << endl;
	cout << endl;

	cout << "Deleting Lists..." << endl;

	delete l;
	delete s;
	delete q;

	cout << "Deletion Successful" << endl;
	cout << endl;
	cout << "Exiting program..." << endl;
	cout << endl;

	system("pause");

	return 0;
}