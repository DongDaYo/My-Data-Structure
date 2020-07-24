/*
#include "MGraph.cpp";
#include "LinkQueue.cpp"
#include "LinkStack.cpp"
using namespace std;

int main() {
	MGraph<int> graph(DG);
	map<int, int> mp;
	graph.initialize(mp);
	LinkStack<int> stack;
	int* p = graph.indegrees();
	int n = graph.getVexnum();
	int counter = 0;
	int x,y;
	for (int i = 0; i < n; i++) {
		if (*(p + i) == 0) stack.push(i);
	}
	while (!stack.isEmpty()) {
		stack.pop(x);
		counter++;
		cout << graph.getVexElem(x) << " ";
		for (y = graph.firstneighbor(x); y >= 0; y = graph.nextneighbor(x, y)) {
			(*(p + y))--;
			if (*(p + y) == 0) {
				stack.push(y);
			}
		}
	}
	cout << endl;
	if (counter < n) {
		cout << "ÓÐ»·£¬ÍØÆËÅÅÐòÊ§°Ü" << endl;
	}
	else {
		cout << "ÍØÆËÅÅÐò³É¹¦£¡" << endl;
	}
	counter = 0;
	LinkQueue<int> queue;
	p = graph.indegrees();
	for (int i = 0; i < n; i++) {
		if (*(p + i) == 0) queue.enqueue(i);
	}
	while (!queue.isEmpty()) {
		queue.dequeue(x);
		counter++;
		cout << graph.getVexElem(x) << " ";
		for (y = graph.firstneighbor(x); y >= 0; y = graph.nextneighbor(x, y)) {
			(*(p + y))--;
			if (*(p + y) == 0) queue.enqueue(y);
		}
	}
	cout << endl;
	if (counter < n) {
		cout << "ÓÐ»·£¬ÍØÆËÅÅÐòÊ§°Ü" << endl;
	}
	else {
		cout << "ÍØÆËÅÅÐò³É¹¦£¡" << endl;
	}
	return 0;
}
*/