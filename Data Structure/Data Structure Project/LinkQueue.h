#pragma once
#include<iostream> //Ϊ��ʹ��NULL������
template<class T>
struct LinkNode {
	T data;
	struct LinkNode* next;
};

template<class T>
class LinkQueue
{
private:
	LinkNode<T>* front;
	LinkNode<T>* rear;
public:
	LinkQueue<T>() {
		front = new LinkNode<T>;
		rear = front;
		front->next = NULL;
	}
	~LinkQueue<T>()
	{
		LinkNode<T>* p = front;
		LinkNode<T>* q;
		while (p) {
			q = p->next;
			delete p;
			p = q;
		}
	}

	void enqueue(T c);
	bool dequeue(T& c);
	bool getfront(T& c);
	bool isEmpty();
};

