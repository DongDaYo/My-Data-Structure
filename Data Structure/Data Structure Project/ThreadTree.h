#pragma once
#include<iostream>
template <class T>
struct ThreadNode {
	T data;
	struct ThreadNode* lchild = NULL, * rchild = NULL;
	int ltag, rtag;
};

template <class T>
class ThreadTree
{
private:
	ThreadNode<T>* root;
	int num;
	void destroy(ThreadNode<T>* root) {
		if (root) {
			if (root->ltag == 0 && root->lchild) destroy(root->lchild);
			if (root->rtag == 0 && root->rchild) destroy(root->rchild);
			delete root;
		}
	}
public:
	ThreadTree<T>() { root = NULL; num = 0; }
	~ThreadTree<T>() { destroy(root); num = 0; }
	ThreadNode<T>* getRoot() { return root; }
	void setRoot(ThreadNode<T>* r) { root = r; num++; }
	void insertChild(ThreadNode<T>* parent, int type, ThreadNode<T>* child);
	//标准的插入结点的方法
	void inorderThreading(ThreadNode<T>* root);//线索化二叉树，必须是已经构建好的二叉树才能线索化,线索化后改变结构要去掉已连线索再重新线索化,很麻烦
									   //调用的时候要写tree.threading(tree.getRoot());
	void inorderTraverse(ThreadNode<T>* p, void(*visit)(T c));//线索化后可从任意位置p沿线索或右子树最左下结点依次中序遍历;
	void revinorderTraverse(ThreadNode<T>* p, void(*visit)(T c));//线索化后按中序反向遍历；
};

