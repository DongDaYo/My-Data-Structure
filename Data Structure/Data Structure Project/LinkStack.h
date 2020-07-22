
#pragma once
#include<iostream> //Ϊ��ʹ��NULL������
#include "common.h"

template <class T>
class LinkStack
{
private:
	LinkNode<T>* head;
public:

	LinkStack<T>() {
		head = NULL;
	}
	~LinkStack<T>()
	{
		LinkNode<T>* p = head;
		LinkNode<T>* q;
		while (p) {
			q = p->next;
			delete p;
			p = q;
		}
	}

	void push(T c);
	bool pop(T& c);
	bool gettop(T& c) const;
	bool isEmpty() const;
};

