#include "ThreadTree.h"
#include <iostream>
using namespace std;

template <class T>
void ThreadTree<T>::insertChild(ThreadNode<T>* parent, int type, ThreadNode<T>* child) {//��׼�Ĳ�����ķ���
	if (type == 0) {
		parent->ltag = 0;
		parent->lchild = child;
	}
	else if (type == 1) {
		parent->rtag = 0;
		parent->rchild = child;
	}
	num++;
}

template<class T>
void ThreadTree<T>::inorderThreading(ThreadNode<T>* root) {
	static ThreadNode<T>* pre = NULL;
	static int threads = 0;
	if (root) {
		inorderThreading(root->lchild);
		if (root->lchild == NULL) {
			root->lchild = pre; root->ltag = 1; threads++;
			cout << root->data;
			cout << "����ָ������������ǰ��";
			if (pre) {
				cout << pre->data;
			}
			else {
				cout << "NULL";
			}
			//cout << root << "����ָ������������ǰ��" << pre  << endl;
		}
		if (pre && pre->rchild == NULL) {
			pre->rchild = root; pre->rtag = 1; threads++;
			cout << pre->data;
			cout << "����ָ��������������";
			cout << root->data << endl;
			//cout << pre<< "����ָ��������������" << root<< endl;
		}
		pre = root;
		inorderThreading(root->rchild);
	}
	else if (threads == num) {
		pre->rchild = NULL; pre->rtag = 1; threads++;
		//cout << "���һ������������" << pre << "����ָ��������" <<NULL<< endl;
	}
}

template<class T>
void ThreadTree<T>::inorderTraverse(ThreadNode<T>* p, void (* visit)(T c)) {
	ThreadNode<T>* q = p;
	while (q) {
		visit(q->data);
		if (q->rtag == 0) {
			q = q->rchild;
			while (q && q->ltag == 0) q = q->lchild;
		}
		else {
			q = q->rchild;
		}
	}
}

template<class T>
void ThreadTree<T>::revinorderTraverse(ThreadNode<T>* p, void(*visit)(T c)){
	ThreadNode<T>* q = p;
	while (q) {
		visit(q->data);
		if (q->ltag == 0) {
			q = q->lchild;
			while (q && q->rtag == 0) q = q->rchild;
		}
		else {
			q = q->lchild;
		}
	}
		
}


void print(char c){
     cout << c <<endl;
}

int main() {
	ThreadTree<char> tree;
	ThreadNode<char>* A = new ThreadNode<char>;
	tree.setRoot(A);
	A->data = 'A';
	ThreadNode<char>* B = new ThreadNode<char>;
	tree.insertChild(A, 0, B);
	B->data = 'B';
	ThreadNode<char>* C = new ThreadNode<char>;
	tree.insertChild(A, 1, C);
	C->data = 'C';
	ThreadNode<char>* D = new ThreadNode<char>;
	tree.insertChild(B, 0, D);
	D->data = 'D';
	ThreadNode<char>* E = new ThreadNode<char>;
	tree.insertChild(B, 1, E);
	E->data = 'E';
	ThreadNode<char>* F = new ThreadNode<char>;
	tree.insertChild(C, 1, F);
	F->data = 'F';
	ThreadNode<char>* G = new ThreadNode<char>;
	tree.insertChild(E, 0, G);
	G->data = 'G';
	ThreadNode<char>* H = new ThreadNode<char>;
	tree.insertChild(E, 1, H);
	H->data = 'H';
	ThreadNode<char>* I = new ThreadNode<char>;
	tree.insertChild(F, 0, I);
	I->data = 'I';
	tree.inorderThreading(A);
	tree.inorderTraverse(G, print);
	cout <<"---------------"<< endl;
	tree.revinorderTraverse(I, print);
	return 0;
}

