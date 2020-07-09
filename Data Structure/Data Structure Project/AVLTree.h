#pragma once
#define MAX_DEPTH 10
#include<iostream>
using namespace std;

template<class T>
struct AVLNode {
	T data;
	int ldepth=0,rdepth=0;
	struct AVLNode* lchild=NULL, * rchild=NULL;
	int ltag=0, rtag=0;
};
template<class T>
struct AVLPath {
	AVLNode<T>* path[MAX_DEPTH];
	int n;
};
template <class T>
class AVLTree
{
private:
	AVLNode<T>* root;
	AVLNode<T>* begin, * end;
	int num;
	AVLPath<T> pathvec; 
	void clearpath() {
		/*for (int i = 0; i < pathvec.n; i++) {
			pathvec.path[i] = NULL;
		}*/
		pathvec.n = 0;
	}
	void destroy(AVLNode<T>* root) {
		if (root) {
			if (root->ltag == 0 && root->lchild) destroy(root->lchild);
			if (root->rtag == 0 && root->rchild) destroy(root->rchild);
			delete root;
		}
	}
	void checkandbalance();
	void threading(AVLNode<T>* p) {
		static AVLNode<T>* pre = NULL;
		static int threads = 0;
		if (p) {
			threading(p->lchild);
			if (p->lchild == NULL) {
				p->lchild = pre; p->ltag = 1; threads++;
				if (pre == NULL) { 
					begin = p; 
				}
				cout << p->data;
				cout << "的左指针已连至中序前驱";
				if (pre) {
					cout << pre->data;
				}
				else {
					cout << "NULL";
				}
				cout << endl;
			}
			if (pre && pre->rchild == NULL) {
				pre->rchild = p; pre->rtag = 1; threads++;
				cout << pre->data;
				cout << "的右指针已连至中序后继";
				cout << p->data;
				cout << endl;
				//cout << pre<< "的右指针已连至中序后继" << root<< endl;
			}
			pre = p;
			threading(p->rchild);
		}
		else if (threads == num) {
			pre->rchild = NULL; pre->rtag = 1; threads++;
			end = pre;
			cout << "最后一个中序遍历结点";
			cout << pre->data;
			cout << "的右指针已连至NULL" << endl;
		}
	}
public:
	AVLTree<T>() {
		root = NULL; num = 0; pathvec.n = 0;
	}
	~AVLTree<T>() {
		destroy(root); clearpath(); num = 0;
	}

	bool insertNode(T data);
	void inorderThreading();
	void ascendingTraverse(void(* visit)(T data));
	void descendingTraverse(void(* visit)(T data));
	bool search(T data);
	int findPosition(T data);
};

