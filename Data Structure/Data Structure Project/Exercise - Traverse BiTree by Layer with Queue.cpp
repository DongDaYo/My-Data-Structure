/*

#include <iostream>
#include "LinkQueue.cpp"
#include "BiTree.cpp"
using namespace std;

void buildTree(BiTree<int>& tree) {
	BiTNode<int>* root = new BiTNode<int>;
	tree.setRoot(root);
	root->data = 1;
	BiTNode<int>* r2 = new BiTNode<int>;
	r2->data = 2;
	root->lchild = r2;
	BiTNode<int>* r3 = new BiTNode<int>;
	r3->data = 3;
	root->rchild = r3;
	BiTNode<int>* r5 = new BiTNode<int>;
	r5->data = 5;
	r2->rchild = r5;
	BiTNode<int>* r7 = new BiTNode<int>;
	r7->data = 7;
	r3->rchild = r7;
}
int main()
{
	BiTree<int> tree;
	buildTree(tree);
	LinkQueue<BiTNode<int>*> queue;
	queue.enqueue(tree.getRoot());
	BiTNode<int>* node;
	while (queue.dequeue(node)) {
		cout << node->data << endl;
		if (node->lchild) queue.enqueue(node->lchild);
		if (node->rchild) queue.enqueue(node->rchild);
	}
	return 0;
}

*/