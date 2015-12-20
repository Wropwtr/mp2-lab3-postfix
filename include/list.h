#pragma once

#include<iostream>

using namespace std;

template <class ValType>
class Node{
public:
	ValType key;
	Node<ValType>* next;
};

template <class ValType>
class List{
	Node<ValType>* pFirst;
public:
	List();
	List(const List &l);
	~List();

	void show() const;
	Node<ValType>* search(ValType key) const;
	void insert(ValType key);
	void insert_b(ValType key, Node<ValType>* elem);
	void insert_a(ValType key, Node<ValType>* elem);
	void insert_a(ValType key, ValType insKey);
	void erase(ValType key);

	Node<ValType>* getFirst(); 
};

template <class ValType>
List<ValType>::List(){
	pFirst = 0;
}

template <class ValType>
List<ValType>::List(const List &l){
	if ( pFirst == l.pFirst ) 
		return;
	pFirst = 0;
	if ( &l == 0 || l.pFirst == 0 )
		return;

	Node<ValType> *buf2;
	Node<ValType> *iterator = l.pFirst;

	Node<ValType>* buf1 = new Node<ValType>;
	buf1->next = 0;
	buf1->key = iterator->key;
	pFirst = buf1;

	iterator =  iterator->next;	
	while ( iterator ){
		buf2 = buf1;
		buf1 = new Node<ValType>;
		buf1->key = iterator->key;
		buf1->next = 0;
		buf2->next = buf1;
		iterator =  iterator->next;	
	}
}

template <class ValType>
List<ValType>::~List(){
	Node<ValType>* buf;
	while ( pFirst ){
		buf = pFirst;
		pFirst = pFirst->next;
		delete buf;
	}
}

template <class ValType>
void List<ValType>::show() const {
	if ( !pFirst ){
		cout << "\tList is empty\n";
		return;
	} 
	Node<ValType>* buf = pFirst;
	while ( buf ){
		cout << "\t" << buf->key << endl;
		buf = buf->next;
	}
}

template <class ValType>
Node<ValType>* List<ValType>::search(ValType key) const {
	if ( !pFirst )
		return 0;

	Node<ValType>* buf = pFirst;
	while ( buf && (buf->key != key) ){
		buf = buf->next;
	}
	if ( buf == 0 ) return 0;
	return buf;
}

template <class ValType>
void List<ValType>::insert(ValType key){
	Node<ValType>* buf = new Node<ValType>;
	buf->key = key;
	buf->next = pFirst;
	pFirst = buf;
} // Insert before firsts

template <class ValType>
void List<ValType>::insert_b(ValType key, Node<ValType>* elem){
	Node<ValType>* item = search(key);
	if ( item == 0 ) return; // maybe throw

	if ( item == pFirst ){
		elem->next = pFirst;
		pFirst = elem;	
		return;
	}
	Node<ValType> *iterator = pFirst;
	while ( iterator->next && iterator->next != item ){
		iterator = iterator->next;
	}
	if ( iterator->next ){
		iterator->next = elem;
		elem->next = item;
		return;
	}
	throw ("No place to insert");
}

template <class ValType>
void List<ValType>::insert_a(ValType key, Node<ValType>* elem){
	Node<ValType>* item = search(key);
	if ( item == 0 )
		throw ("No place to insert");

	Node<ValType>* buf = item->next;
	item->next = elem;
	elem->next = buf;
}

template <class ValType>
void List<ValType>::insert_a(ValType key, ValType insKey){
	Node<ValType>* buf = new Node<ValType>;
	buf->key = insKey;
	try{
		insert_a(key, buf);
	} catch(...){
		delete buf;
		throw ("No place to insert");
	}
}

template <class ValType>
void List<ValType>::erase(ValType key){
	if ( !pFirst ){
		//throw "List is empty\n";
		return;
	} 
	Node<ValType> *buf = pFirst;
	if ( pFirst->key == key ){
		pFirst = pFirst->next;
		delete buf;
		return;
	} // Delete first element
	while ( buf->next ){
		if ( (buf->next)->key == key )
			break;
		buf = buf->next;
	} // Search element
	if ( !buf->next ) return;
	Node<ValType> *tmp = buf->next;
	buf->next = tmp->next;
	delete tmp;
	return;
}

template <class ValType>
Node<ValType>* List<ValType>::getFirst(){
	return pFirst;
}


