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
				
			}
			if (pre && pre->rchild == NULL) {
				pre->rchild = p; pre->rtag = 1; threads++;
				
			}
			pre = p;
			threading(p->rchild);
		}
		else if (threads == num) {
			pre->rchild = NULL; pre->rtag = 1; threads++;
			end = pre;
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

