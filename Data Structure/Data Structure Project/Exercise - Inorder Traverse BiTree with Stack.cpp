/*
#include <iostream>
#include "LinkStack.cpp"
#include "BiTree.cpp"
typedef BiTNode<int> intp;
using namespace std;

int main() {
	BiTree<int> tree; 
	LinkStack<intp*> stack;
	intp* r1 = new intp;
	r1->data = 5;
	tree.setRoot(r1); 
	intp* r2 = new intp;
	r2->data = 9;
	r1->rchild = r2;
	intp* r3 = new intp;
	r3->data = 7;
	r2->lchild = r3;
	intp* r4 = new intp;
	r4->data = 8;
	r3->rchild = r4;
	intp* r5 = new intp;
	r5->data = 6;
	r3->lchild = r5;

	intp* p = r1;
	while (p || !stack.isEmpty()) {
		if (p) {
			stack.push(p);
			p = p->lchild;
			
		}
		else {
			stack.pop(p);
			cout << p->data << " ";
			p = p->rchild;
		}
	}
	return 0;
}

*/
