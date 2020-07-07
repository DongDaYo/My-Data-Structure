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
	//��׼�Ĳ�����ķ���
	void inorderThreading(ThreadNode<T>* root);//���������������������Ѿ������õĶ���������������,��������ı�ṹҪȥ����������������������,���鷳
									   //���õ�ʱ��Ҫдtree.threading(tree.getRoot());
	void inorderTraverse(ThreadNode<T>* p, void(*visit)(T c));//��������ɴ�����λ��p�������������������½�������������;
	void revinorderTraverse(ThreadNode<T>* p, void(*visit)(T c));//�������������������
};

