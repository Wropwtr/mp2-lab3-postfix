#include "list.h"
#include <iostream>

void main(){
	cout << "\t\tList demonstration:\n1) Show empty list.\n";
	List<int> *l = new List<int>();

	l->show();

	cout << "2)Add -1, 0, 5 \n";
	l->insert(-1);
	l->insert(0);
	l->insert(5);

	cout << "3)Show list\n";
	l->show();
	// 5 0 -1

	cout << "4)Insert 3 after key 6\n";
	try{
		l->insert_a(6, 3);
	} catch(...){
		cout << "\tNo item with key 6\n";
	}

	cout << "5)Insert 3 after key 0\n";
	try{
		l->insert_a(0, 3);
	} catch(...){
		cout << "\tNo item with key 0\n";
	}
	l->show();

	cout << "6)Insert 7 before key 3\n";
	try{
		l->insert_a(3, 7);
	} catch(...){
		cout << "\tNo item with key 3\n";
	}
	l->show();

	cout << "7)Get first element key\n";
	cout << "\t" << l->getFirst()->key << endl;

	return;
}