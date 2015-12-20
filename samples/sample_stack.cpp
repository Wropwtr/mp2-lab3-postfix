#include "stack.h"
#include <iostream>

void main(){
	cout << "\t\tStack demonstration:\n1) Show top of empty stack.\n";
	Stack<int> *s = new Stack<int>();
	try{
		s->top();
	} catch(...){
		cout << "\t Stack is empty!\n";
	}

	cout << "2)Add -1, 0, 5 \n";
	s->push(-1);
	s->push(0);
	s->push(5);
		// 5 0 -1

	cout << "3)Show top\n\t" << s->top() << endl;
	 //5

	cout << "4)Pop all\n";
	cout << "\t" << s->pop() << endl;
	cout << "\t" << s->pop() << endl;
	cout << "\t" << s->pop() << endl;
	try{
		s->pop();
	} catch(...){
		cout << "\tStack is empty.\n";
	}

	//delete s;

	return;
}