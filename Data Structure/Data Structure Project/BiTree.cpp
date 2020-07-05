


#include <iostream>
#include "BiTree.h"

template <class T>
void BiTree<T>::preorder(void(*visit)(T a), BiTNode<T>* c)
{
	if (c) {
		visit(c->data);
		preorder(visit, c->lchild);
		preorder(visit, c->rchild);
	}
}

template<class T>
void BiTree<T>::inorder(void(*visit)(T a), BiTNode<T>* c)
{
	if (c) {
		inorder(visit, c->lchild);
		visit(c->data);
		inorder(visit, c->rchild);
	}
}

template<class T>
void BiTree<T>::postorder(void(*visit)(T a), BiTNode<T>* c)
{
	if (c) {
		postorder(visit, c->lchild);
		postorder(visit, c->rchild);
		visit(c->data);
	}
}

/*

void print(char data);


int main() {
	BiTree<char> tree;
	BiTNode<char>* root = new BiTNode<char>;
	tree.setRoot(root);
	root->data ='A';
	BiTNode<char>* r2 = new BiTNode<char>;
	r2->data = 'B';
	root->lchild = r2;
	BiTNode<char>* r3 = new BiTNode<char>;
	r3->data = 'C';
	root->rchild = r3;
	BiTNode<char>* r4 = new BiTNode<char>;
	r4->data = 'D';
	r2->lchild = r4;
	BiTNode<char>* r5 = new BiTNode<char>;
	r5->data = 'E';
	r2->rchild = r5;
	BiTNode<char>* r6 = new BiTNode<char>;
	r6->data = 'F';
	r3->lchild = r6;
	BiTNode<char>* r9 = new BiTNode<char>;
	r9->data = 'G';
	r4->rchild = r9;
	cout << "先根遍历序列：";
	tree.preorder(print,root);
	cout << endl;
	cout << "中根遍历序列：";
	tree.inorder(print, root);
	cout << endl;
	cout << "后根遍历序列：";
	tree.postorder(print, root);
	cout << endl;
	return 0;
}

void print(char data) {
	cout << data ;
}

*/