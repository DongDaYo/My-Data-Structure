

#include "LinkStack.h"
#include <iostream>
using namespace std;

template<class T>
void LinkStack<T>::push(T c) {
	LinkNode<T>* p = new LinkNode<T>;
	p->data = c;
	p->next = head;
	head = p;
}

template<class T>
bool LinkStack<T>::pop(T& c) {
	if (isEmpty()) {
		cout << "栈空，无法弹出元素！" << endl;
		return false;
	}
	else {
		LinkNode<T>* p = head;
		c = p->data;
		head = p->next;
		delete p;
		return true;
	}
}

template<class T>
bool LinkStack<T>::gettop(T& c) const {
	if (isEmpty()) {
		//	cout << "栈空，无元素！" << endl;
		return false;
	}
	else {
		c = head->data;
		return true;
	}
}

template<class T>
bool LinkStack<T>::isEmpty() const {
	return head == NULL;
}
