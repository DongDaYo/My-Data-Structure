
#pragma once
#include<iostream> //为了使用NULL而引入
template <class T>
struct LinkNode {
	T data;
	struct LinkNode* next;
};

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

