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
void ThreadTree<T>::threading(ThreadNode<T>* root) {
	static ThreadNode<T>* pre = NULL;
	static int threads = 0;
	if (root) {
		threading(root->lchild);
		if (root->lchild == NULL) {
			root->lchild = pre; root->ltag = 1; threads++;
			cout << root << "����ָ������������ǰ��" << pre  << endl;
		}
		if (pre && pre->rchild == NULL) {
			pre->rchild = root; pre->rtag = 1; threads++;
			cout << pre<< "����ָ��������������" << root<< endl;
		}
		pre = root;
		threading(root->rchild);
	}
	else if (threads == num) {
		pre->rchild = NULL; pre->rtag = 1; threads++;
		cout << "���һ������������" << pre << "����ָ��������" <<NULL<< endl;
	}
}

/*

int main() {
	ThreadTree<char> tree;
	ThreadNode<char>* A = new ThreadNode<char>;
	tree.setRoot(A);
	A->data = 'A';
	cout << "���A�ĵ�ַΪ" << A << endl;
	ThreadNode<char>* B = new ThreadNode<char>;
	tree.insertChild(A, 0, B);
	B->data = 'B';
	cout << "���B�ĵ�ַΪ" << B << endl;
	ThreadNode<char>* C = new ThreadNode<char>;
	tree.insertChild(A, 1, C);
	C->data = 'C';
	cout << "���C�ĵ�ַΪ" << C << endl;
	ThreadNode<char>* D = new ThreadNode<char>;
	tree.insertChild(B, 0, D);
	D->data = 'D';
	cout << "���D�ĵ�ַΪ" << D << endl;
	ThreadNode<char>* E = new ThreadNode<char>;
	tree.insertChild(B, 1, E);
	E->data = 'E';
	cout << "���E�ĵ�ַΪ" << E << endl;
	ThreadNode<char>* F = new ThreadNode<char>;
	tree.insertChild(C, 1, F);
	F->data = 'F';
	cout << "���F�ĵ�ַΪ" << F << endl;
	ThreadNode<char>* G = new ThreadNode<char>;
	tree.insertChild(E, 0, G);
	G->data = 'G';
	cout << "���G�ĵ�ַΪ" << G << endl;
	ThreadNode<char>* H = new ThreadNode<char>;
	tree.insertChild(E, 1, H);
	H->data = 'H';
	cout << "���H�ĵ�ַΪ" << H << endl;
	ThreadNode<char>* I = new ThreadNode<char>;
	tree.insertChild(F, 0, I);
	I->data = 'I';
	cout << "���I�ĵ�ַΪ" << I << endl;
	tree.threading(A);
	return 0;
}

*/