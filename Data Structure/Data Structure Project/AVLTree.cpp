#include "AVLTree.h"
#include <iostream>
using namespace std;

bool higher(int a, int b, int c) {
	return (a > c ? a : c) > (a > b ? a : b);
}

bool lower(int a, int b, int c) {
	return (a > c ? a : c) < (a > b ? a : b);
}

template<class T>
void AVLTree<T>::checkandbalance()
{
	int n = pathvec.n;
	AVLNode<T>* p,*q,*A,*B,*C;
	bool flag = true;
	for (int i = n - 2; i >= 0; i--) {//��p��ʼ������������㣬����ÿ����������Ⱥ������
		p = pathvec.path[i+1];
		q = pathvec.path[i];
		if (q->rchild == p) {//���p��q������
			if (flag) {
				flag = higher(q->ldepth, q->rdepth, q->rdepth+1);
				q->rdepth++;
			}else {
				break;
			}
		}else {//p��q������
			if (flag) {
				flag = higher(q->rdepth, q->ldepth, q->ldepth+1);
				q->ldepth++;
			}else {
				break;
			}
		}
	}
	int k = n - 1;
	for (; k >= 0; k--) {
		p = pathvec.path[k];
		if (p->ldepth > p->rdepth + 1 || p->rdepth > p->ldepth + 1) {
			break;//��ʱk����Сʧ�������ĸ������path�е��±�
		}
	}
	if (k >= 0) {
		A = pathvec.path[k];
		B = pathvec.path[k + 1];
		if (A->rchild == B) {
			if (pathvec.path[n - 1]->data > B->data)   {//RR��ʧ��
				A->rchild = B->lchild;
				B->lchild = A;
				if (k >= 1) {//���A�и����
					if (A == pathvec.path[k - 1]->lchild) {//A���丸������
						pathvec.path[k - 1]->lchild = B;//�丸�����ӻ���B
					}else {//A���丸������
						pathvec.path[k - 1]->rchild = B;//�丸�����ӻ���B
					}
				}else {
					root = B;//����㻻��B 
				}
				B->ldepth++; 
				A->rdepth -= 2;
				for (int m = k; m < n-1; m++) {//��A����Ƴ��²�����ĸ�·��,ͬʱ��·���ĳ��ȱ�Ϊn-1
					pathvec.path[m] = pathvec.path[m + 1];
				}
				pathvec.path[--pathvec.n]=NULL;
				flag = true;
				for (int i = k-1; i >= 0; i--) {
					p = pathvec.path[i + 1];
					q = pathvec.path[i];
					if (q->rchild == p) {
						if (flag) {
							flag = lower(q->ldepth, q->rdepth, q->rdepth-1);
							q->rdepth--;
						}else {
							break;
						}
					}else {
						if (flag) {
							flag = lower(q->rdepth, q->ldepth, q->ldepth-1);
							q->ldepth--;
						}else {
							break;
						}
					}
				}
			}else {//RL��ʧ��
				C = pathvec.path[k + 2];
				B->lchild = C->rchild;
				C->rchild = B;
				A->rchild = C->lchild;
				C->lchild = A;
				if (k >= 1) {//���A�и����
					if (A == pathvec.path[k - 1]->lchild) {
						pathvec.path[k - 1]->lchild = C;
					}else {
						pathvec.path[k - 1]->rchild = C;
					}
				}else {
					root = C;
				}
				if (pathvec.path[n - 1]->data < C->data) {//�½�����C����������
					A->rdepth -= 2;
					B->ldepth -= 2;
					C->ldepth += 1;
					C->rdepth += 2;
				}else if (pathvec.path[n - 1]->data > C->data) {//�½�����C����������
					A->rdepth -= 3;
					B->ldepth -= 1;
					C->ldepth += 2;
					C->rdepth += 1;
				}else {//�½�����C
					A->rdepth -= 2;
					B->ldepth -= 1;
					C->ldepth += 1;
					C->rdepth += 1;
				}
				for (int m = k; m < n - 2; m++) {//��A����Ƴ��²�����ĸ�·��,ͬʱ��·���ĳ��ȱ�Ϊn-1
					pathvec.path[m] = pathvec.path[m + 2];
				}
				pathvec.n -= 2;
				pathvec.path[pathvec.n] = pathvec.path[pathvec.n+1] = NULL;
				flag = true;
				for (int i = k - 1; i >= 0; i--) {
					p = pathvec.path[i + 1];
					q = pathvec.path[i];
					if (q->rchild == p) {
						if (flag) {
							flag = lower(q->ldepth, q->rdepth, q->rdepth - 1);
							q->rdepth--;
						}else {
							break;
						}
					}else {
						if (flag) {
							flag = lower(q->rdepth, q->ldepth, q->ldepth - 1);
							q->ldepth--;
						}else {
							break;
						}
					}
				}
			}
		}
		else {
			if (pathvec.path[n - 1]->data < B->data) {//LL��ʧ��"
				A->lchild = B->rchild;
				B->rchild = A;
				if (k >= 1) {//���A�и����
					if (A == pathvec.path[k - 1]->lchild) {//A���丸����
						pathvec.path[k - 1]->lchild = B;//B��Ϊ�丸����
					}else {
						pathvec.path[k - 1]->rchild = B;
					}
				}else {
					root = B;
				}
				B->rdepth++;
				A->ldepth -= 2;
				for (int m = k; m < n - 1; m++) {
					pathvec.path[m] = pathvec.path[m + 1];
				}
				pathvec.path[--pathvec.n] = NULL;
				flag = true;
				for (int i = k - 1; i >= 0; i--) {
					p = pathvec.path[i + 1];
					q = pathvec.path[i];
					if (q->rchild == p) {
						if (flag) {
							flag = lower(q->ldepth, q->rdepth, q->rdepth - 1);
							q->rdepth--;
						}else {
						  break;
						}
					}else {
						if (flag) {
							flag = lower(q->rdepth, q->ldepth, q->ldepth - 1);
							q->ldepth--;
						}else {
							break;
						}
					}
				}
			}
			else {//LR��ʧ��
				C = pathvec.path[k + 2];
				B->rchild = C->lchild;
				C->lchild = B;
				A->lchild = C->rchild;
				C->rchild = A;
				if (k >= 1) {//���A�и����
					if (A == pathvec.path[k - 1]->lchild) {
						pathvec.path[k - 1]->lchild = C;
					}else {
						pathvec.path[k - 1]->rchild = C;
					}
				}else {
					root = C;
				}
				if (pathvec.path[n - 1]->data < C->data) {//�½�����C����������
					A->ldepth -= 3;
					B->rdepth -= 1;
					C->ldepth += 1;
					C->rdepth += 2;
				}else if (pathvec.path[n - 1]->data > C->data) {//�½�����C����������
					A->ldepth -= 2;
					B->rdepth -= 2;
					C->ldepth += 2;
					C->rdepth += 1;
				}else {//�½�����C
					A->ldepth -= 2;
					B->rdepth -= 1;
					C->ldepth += 1;
					C->rdepth += 1;
				}
				for (int m = k; m < n - 2; m++) {//��A����Ƴ��²�����ĸ�·��,ͬʱ��·���ĳ��ȱ�Ϊn-1
					pathvec.path[m] = pathvec.path[m + 2];
				}
				pathvec.n -= 2;
				pathvec.path[pathvec.n] = pathvec.path[pathvec.n + 1] = NULL;
				flag = true;
				for (int i = k - 1; i >= 0; i--) {
					p = pathvec.path[i + 1];
					q = pathvec.path[i];
					if (q->rchild == p) {
						if (flag) {
							flag = lower(q->ldepth, q->rdepth, q->rdepth - 1);
							q->rdepth--;
						}else {
							break;
						}
					}else {
						if (flag) {
							flag = lower(q->rdepth, q->ldepth, q->ldepth - 1);
							q->ldepth--;
						}else {
							break;
						}
					}
				}
			}
		}
	}
	clearpath();
}

template<class T>
bool AVLTree<T>::insertNode(T data) {
	AVLNode<T>* p;
	if (root == NULL) {
		p = new AVLNode<T>;
		p->data = data;
		p->ldepth = p->rdepth = 0;
		root = p;
		num++;
	}
	else {
		AVLNode<T>* q = root;
		while (q) { 
			if (data > q->data) {
				pathvec.path[pathvec.n++] = q;
				if (q->rchild) {
					q = q->rchild;
				}
				else {
					p = new AVLNode<T>;
					p->data = data;
					p->ldepth = p->rdepth = 0;
					q->rchild = p;
					q->rtag = 0;
					num++;
					pathvec.path[pathvec.n++] = p;
					checkandbalance();
					break;
				}
			}
			else if(data < q->data){
				pathvec.path[pathvec.n++] = q;
				if (q->lchild) {
					q = q->lchild;
				}
				else {
					p = new AVLNode<T>;
					p->data = data;
					p->ldepth = p->rdepth = 0;
					q->lchild = p;
					q->ltag = 0;
					num++;
					pathvec.path[pathvec.n++] = p;
					checkandbalance();
					break;
				}
			}
			else {
				clearpath();
				return false; //��ȣ������룬Ҳ�����ƽ��
			}
		}
	}
	return true;
}

template<class T>
void AVLTree<T>::inorderThreading()
{
	threading(root);
}

template<class T>
void AVLTree<T>::ascendingTraverse(void(*visit)(T data))
{
	AVLNode<T>* q = begin;
	while (q!=NULL) {
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
void AVLTree<T>::descendingTraverse(void(*visit)(T data))
{
	AVLNode<T>* q = end;
	while (q!=NULL) {
		visit(q->data);
		if (q->ltag == 0) {
			q = q->lchild;
			while (q && q->rtag==0) q = q->rchild;
		}
		else {
			q = q->lchild;
		}
	}
}

template<class T>
bool AVLTree<T>::search(T data)
{
	AVLNode<T>* p = root;
	while (p) {
		if (p->data == data) {
			return true;
		}else if(p->data<data){
			if (p->rtag == 0) {
				p = p->rchild;
			}else {
				return false;
			}
		}
		else {
			if (p->ltag == 0) {
				p = p->lchild;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

template<class T>
int AVLTree<T>::findPosition(T data)
{
	if (!search(data)) return -1;
	int pos = 1;
	AVLNode<T>* p = begin;
	while (p && p->data < data) {
	    pos++;
		if (p->rtag == 0) {
			p = p->rchild;
			while (p && p->ltag == 0) p = p->lchild;
		}else {
			p = p->rchild;
		}

	}
    return pos;
}
/*

void print(int data) {
	cout << data << " ";
}

int main() {
	AVLTree<int> tree;
	tree.insertNode(50);
	tree.insertNode(19);
	tree.insertNode(13);
	tree.insertNode(32);
	tree.insertNode(47);
	tree.insertNode(13);
	tree.insertNode(26);
	tree.insertNode(60);
	tree.insertNode(11);
	tree.insertNode(66);
	tree.insertNode(70);
	tree.insertNode(30);
	tree.insertNode(21);
	tree.insertNode(27);
	tree.inorderThreading();
	tree.ascendingTraverse(print);
	cout << endl;
	tree.descendingTraverse(print);
	cout << endl;
	if (tree.search(30)) {
		cout << "Ԫ��30��λ����" << tree.findPosition(30) << endl;
	}
	else {
		cout << "Ԫ��30������" << endl;
	}
	if (tree.search(35)) {
		cout << "Ԫ��35��λ����" << tree.findPosition(35) << endl;
	}
	else {
		cout << "Ԫ��35������" << endl;
	}
	return 0;
}
*/