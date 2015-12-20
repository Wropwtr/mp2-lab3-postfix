#pragma once
#include "list.h"

template <class ValType>
class Stack{
	List<ValType>* list;
public:
	Stack();
	Stack(const Stack &s);
	~Stack();

	int isEmpty() const;
	int isFull() const;
	void push(ValType key);
	ValType pop();

	ValType top();
};

template <class ValType>
Stack<ValType>::Stack(){
	list = new List<ValType>();
}

template <class ValType>
Stack<ValType>::Stack(const Stack &s){
	list = new List<ValType>(*s.list);
}

template <class ValType>
Stack<ValType>::~Stack(){
	delete list;
}

template <class ValType>
int Stack<ValType>::isEmpty() const{
	return list->getFirst() == 0;
}

template <class ValType>
int Stack<ValType>::isFull() const{
	Node<ValType>* tmp;
	try{
		tmp = new Node<ValType>;
	}
	catch(...){
		return 1;
	}
	delete tmp;
	return 0;
}

template <class ValType>
void Stack<ValType>::push(ValType key){
	if ( isFull() ){ 
		throw "Stack is full";
	}
	list->insert(key);
}

template <class ValType>
ValType Stack<ValType>::pop(){
	if ( isEmpty() ) 
		throw "Stack is empty";
	ValType result = ( list->getFirst() )->key;
	list->erase( result );
	return result;
}

template <class ValType>
ValType Stack<ValType>::top(){
	if ( isEmpty() )
		throw "Stack is empty";
	return (list->getFirst())->key;
}