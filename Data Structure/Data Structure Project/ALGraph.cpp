#include "ALGraph.h"
#include <map>
using namespace std;

template<typename T>
void ALGraph<T>::initialize() {
	ArcNode* p, * q;
	cout << "请输入顶点数和边数" << endl;
	cin >> vexnum >> arcnum;
	char c;
	cout << "是否要输入结点的数据？若选否，输入边的数据时须从0开始为顶点编号。y:是/n:否" << endl;
	cin >> c;
	if (c == 'y') {
		for (int i = 0; i < vexnum; i++) {
			cin >> vertices[i];
		}
	}
	T headdata, taildata;
	int head, tail, info = 1;
	if (kind == DG|| kind == DN) {
		cout << "请输入弧的弧尾和弧头(有向网还需输入权值)" << endl;
		for (int i = 0; i < arcnum; i++) {
			cin >> taildata >> headdata;
			if (kind == DN) cin >> info;
			if (c == 'y') {
				tail = foundIndex(taildata);
				if (tail < 0) {
					cout << "出错，不存在数据是" << taildata << "的顶点，请重新输入此边数据" << endl;
					i--;
					continue;
				}
				head = foundIndex(headdata);
				if (head < 0) {
					cout << "出错，不存在数据是" << headdata << "的顶点，请重新输入此边数据" << endl;
					i--;
					continue;
				}
			}
			else if (c == 'n') {
				tail = taildata;
				head = headdata;
			}
			p = new ArcNode;
			p->adjvex = head;
			p->nextarc = vertices[tail].firstarc->nextarc;
			vertices[tail].firstarc = p;
			p->info = info;
		}
	}
	else if (kind == UDG || kind == UDN) {
		cout << "请输入弧的弧尾和弧头(有向网还需输入权值)" << endl;
		for (int i = 0; i < arcnum; i++) {
			cin >> taildata >> headdata;
			if (kind == DN) cin >> info;
			if (c == 'y') {
				tail = foundIndex(taildata);
				if (tail < 0) {
					cout << "出错，不存在数据是" << taildata << "的顶点，请重新输入此边数据" << endl;
					i--;
					continue;
				}
				head = foundIndex(headdata);
				if (head < 0) {
					cout << "出错，不存在数据是" << headdata << "的顶点，请重新输入此边数据" << endl;
					i--;
					continue;
				}
			}
			else if (c == 'n') {
				tail = taildata;
				head = headdata;
			}
			p = new ArcNode;
			p->adjvex = head;
			p->nextarc = vertices[tail].firstarc->nextarc;
			vertices[tail].firstarc = p;
			p->info = info;

			q = new ArcNode;
			q->adjvex = tail;
			q->nextarc = vertices[head].firstarc->nextarc;
			vertices[head].firstarc = q;
			q->info = info;
		}
	}
}

template<typename T>
bool ALGraph<T>::adjacent(int x, int y)
{
	ArcNode *p = vertices[x].firstarc;
	while (p) {
		if (p->adjvex == y) return true;
		p = p->nextarc;
	}
	return false;
}

template<typename T>
int ALGraph<T>::insertVertex(T x)
{
	vertices[vexnum].data = x;
	return vexnum++;
}

template<typename T>
void ALGraph<T>::addEdge(int x, int y, int info)
{
	ArcNode* p;
	p = new ArcNode;
	p->adjvex = y;
	p->info = info;
	p->nextarc = vertices[x].firstarc;
	vertices[x].firstarc = p;
	if (kind == UDG || kind == UDN) {
		p = new ArcNode;
		p->adjvex = x;
		p->info = info;
		p->nextarc = vertices[y].firstarc;
		vertices[y].firstarc = p;
	}
	arcnum++;
}

template<typename T>
void ALGraph<T>::removeEdge(int x, int y)
{
	ArcNode* p,*q;
	p = vertices[x].firstarc;
	if (p->adjvex == y) {
		q = p->nextarc;
		delete p;
		vertices[x].firstarc = q;
	}
	else {
		q = p->nextarc;
		while (q && q->adjvex != y) {
			p = q;
			q = q->nextarc;
		}
		if (q) {
			p->nextarc = q->nextarc;
			delete q;
		}
	}
	if (kind == UDG || kind == UDN) {
		p = vertices[y].firstarc;
		if (p->adjvex == x) {
			q = p->nextarc;
			delete p;
			vertices[y].firstarc = q;
		}
		else {
			q = p->nextarc;
			while (q && q->adjvex != x) {
				p = q;
				q = q->nextarc;
			}
			if (q) {
				p->nextarc = q->nextarc;
				delete q;
			}
		}
	}
	arcnum--;
}

template<typename T>
int ALGraph<T>::firstneighbor(int x)
{
	ArcNode* p = vertices[x].firstarc;
	if (p == NULL) return -1;
	return p->adjvex;
}

template<typename T>
int ALGraph<T>::firstInneighbor(int x)
{ 
	ArcNode* p;
	for (int i = 0; i < vexnum; i++) {
		p = vertices[i].firstarc;
		while (p && p->adjvex != x) {
			p = p->nextarc;
		}
		if (p) return i;
	}
	return -1;
}

template<typename T>
int ALGraph<T>::nextneighbor(int x, int y)
{
	ArcNode* p = vertices[x].firstarc;
	while (p && p->adjvex != y) {
		p = p->nextarc;
	}
	if (p && p->nextarc) {
		return p->nextarc->adjvex;
	}
	else {
		return -1;
	}
}

template<typename T>
int ALGraph<T>::nextInneighbor(int x, int y)
{
	ArcNode* p;
	for (int i = y + 1; i < vexnum; i++) {
		p = vertices[i].firstarc;
		while (p && p->adjvex != x) {
			p = p->nextarc;
		}
		if (p) 	return i;
	}
	return -1;
}

template<typename T>
int ALGraph<T>::getEdgeValue(int x, int y)
{
	ArcNode* p = vertices[x].firstarc;
	while (p && p->adjvex != y) {
		p = p->nextarc;
	}
	if (p) return p->info;
	return -1;
}

template<typename T>
bool ALGraph<T>::setEdgeValue(int x, int y, int info)
{
	ArcNode* p = vertices[x].firstarc;
	while (p && p->adjvex != y) {
		p = p->nextarc;
	}
	if (p) {
		p->info = info;
		return true;
	}
	else return false;
}

/*
int main() {
	ALGraph<char> graph(DG);
	map<char, int> mp;
	char c,x,y;
	int vexnum, arcnum,s,t;
	cout << "请输入顶点数和弧数" << endl;
	cin >> vexnum >> arcnum;
	cout << "请输入每个顶点的字符数据" << endl;
	for (int i = 0; i < vexnum; i++) {
		cin >> c;
		mp[c] = graph.insertVertex(c);
	}
	cout << "请输入弧的弧尾字符和弧头字符" << endl;
	for (int i = 0; i < arcnum; i++) {
		cin >> x >> y;
		graph.addEdge(mp[x], mp[y]);
	}
	for (int j = 0; j < 3; j++) {
		cout << "请输入需要判断两个顶点间是否有弧的弧尾字符和弧头字符" << endl;
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << x << "到" << y << "有弧" << endl;
		}
		else {
			cout << x << "到" << y << "没有弧" << endl;
		}
	}
	for (int k = 0; k < 2; k++) {
		cout << "请输入想要查找首个关联的点的顶点的字符" << endl;
		cin >> x;
		s = graph.firstneighbor(mp[x]);
		if (s >= 0) cout << "第一个" << x << "邻接到的顶点为" << graph.getVexElem(s) << endl;
		else cout << x << "没有邻接到的顶点" << endl;
		s = graph.firstInneighbor(mp[x]);
		if (s >= 0) cout << "第一个邻接到" << x << "的顶点为" << graph.getVexElem(s) << endl;
		else cout << "没有邻接到" << x << "的顶点" << endl;
	}
	for (int k = 0; k < 6; k++) {
		cout << "请输入想要查找某个顶点y后下一个x关联的点的顶点的字符" << endl;
		cin >> x >> y;
		t = graph.nextneighbor(mp[x], mp[y]);
		if (t >= 0) cout << "下一个" << x << "邻接到的顶点为" << graph.getVexElem(t) << endl;
		else cout << y << "之后" << x << "没有邻接到的顶点" << endl;
		t = graph.nextInneighbor(mp[y], mp[x]);
		if (t >= 0) cout << "下一个邻接到" << y << "的顶点为" << graph.getVexElem(t) << endl;
		else cout << x << "之后没有邻接到" << y << "的顶点" << endl;
		cout << endl;
	}
	return 0;
}
*/