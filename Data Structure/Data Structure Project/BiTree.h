#pragma once
#include <iostream>
using namespace std;
template<class T>
struct BiTNode {
	T data;
	BiTNode* lchild = NULL, * rchild = NULL;
};

template<class T>
class BiTree
{
private:
	BiTNode<T>* root;
	void destroy(BiTNode<T>* root) {
		if (root) {
			if (root->lchild) destroy(root->lchild);
			if (root->rchild) destroy(root->rchild);
			delete root;
		}
	}
public:
	BiTree<T>() {
		root = NULL;
	}
	~BiTree<T>()
	{
		destroy(root);
	}
	BiTNode<T>* getRoot() const {
		return root;
	}
	void setRoot(BiTNode<T>* c) {
		root = c;
	}

	void preorder(void (*visit)(T a), BiTNode<T>* c);
	void inorder(void (*visit)(T a), BiTNode<T>* c);
	void postorder(void (*visit)(T a), BiTNode<T>* c);

};

