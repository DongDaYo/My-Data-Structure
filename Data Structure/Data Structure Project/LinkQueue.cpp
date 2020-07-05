#include "LinkQueue.h"
#include <iostream>
using namespace std;

template <class T>
void LinkQueue<T>::enqueue(T c) {
	LinkNode<T>* p = new LinkNode<T>;
	p->data = c;
	p->next = NULL;
	rear->next = p;
	rear = p;
}

template <class T>
bool LinkQueue<T>::dequeue(T& c) {
	if (isEmpty()) {
		//cout << "队列空，无法取出元素！" << endl;
		return false;
	}
	else {
		LinkNode<T>* p = front->next;
		c = p->data;
		front->next = p->next;
		if (rear == p) rear = front;
		delete p;
		return true;
	}
}

template <class T>
bool LinkQueue<T>::getfront(T& c) {
	if (isEmpty()) {
		//cout << "队列空，无元素！" << endl;
		return false;
	}
	else {
		c = front->next->data;
		return true;
	}
}

template <class T>
bool LinkQueue<T>::isEmpty() {
	return front == rear;
}