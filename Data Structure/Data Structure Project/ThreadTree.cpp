#include "ThreadTree.h"
#include <iostream>
using namespace std;

template <class T>
void ThreadTree<T>::insertChild(ThreadNode<T>* parent, int type, ThreadNode<T>* child) {//标准的插入结点的方法
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
			cout << root << "的左指针已连至中序前驱" << pre  << endl;
		}
		if (pre && pre->rchild == NULL) {
			pre->rchild = root; pre->rtag = 1; threads++;
			cout << pre<< "的右指针已连至中序后继" << root<< endl;
		}
		pre = root;
		threading(root->rchild);
	}
	else if (threads == num) {
		pre->rchild = NULL; pre->rtag = 1; threads++;
		cout << "最后一个中序遍历结点" << pre << "的右指针已连至" <<NULL<< endl;
	}
}

/*

int main() {
	ThreadTree<char> tree;
	ThreadNode<char>* A = new ThreadNode<char>;
	tree.setRoot(A);
	A->data = 'A';
	cout << "结点A的地址为" << A << endl;
	ThreadNode<char>* B = new ThreadNode<char>;
	tree.insertChild(A, 0, B);
	B->data = 'B';
	cout << "结点B的地址为" << B << endl;
	ThreadNode<char>* C = new ThreadNode<char>;
	tree.insertChild(A, 1, C);
	C->data = 'C';
	cout << "结点C的地址为" << C << endl;
	ThreadNode<char>* D = new ThreadNode<char>;
	tree.insertChild(B, 0, D);
	D->data = 'D';
	cout << "结点D的地址为" << D << endl;
	ThreadNode<char>* E = new ThreadNode<char>;
	tree.insertChild(B, 1, E);
	E->data = 'E';
	cout << "结点E的地址为" << E << endl;
	ThreadNode<char>* F = new ThreadNode<char>;
	tree.insertChild(C, 1, F);
	F->data = 'F';
	cout << "结点F的地址为" << F << endl;
	ThreadNode<char>* G = new ThreadNode<char>;
	tree.insertChild(E, 0, G);
	G->data = 'G';
	cout << "结点G的地址为" << G << endl;
	ThreadNode<char>* H = new ThreadNode<char>;
	tree.insertChild(E, 1, H);
	H->data = 'H';
	cout << "结点H的地址为" << H << endl;
	ThreadNode<char>* I = new ThreadNode<char>;
	tree.insertChild(F, 0, I);
	I->data = 'I';
	cout << "结点I的地址为" << I << endl;
	tree.threading(A);
	return 0;
}

*/