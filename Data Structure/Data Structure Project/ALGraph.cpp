#include "ALGraph.h"

/*
#include"LinkQueue.h"

static LinkQueue<int> queue;

template<typename T>
void ALGraph<T>::BFS(int i, bool* visited, void(*visit)(T c))
{
	int v = i;
	visit(getVexElem(i));
	visited[i] = true;
	queue.enqueue(i);
	while (!queue.isEmpty()) {
		queue.dequeue(v);
		for (int w = firstneighbor(v); w >= 0; w = nextneighbor(v, w)) {
			if (!visited[w]) {
				visited(getVexElem(w));
				visited[w] = true;
				queue.enqueue(w);
			}
		}
	}
}

template<typename T>
void ALGraph<T>::BFSTraverse(void(*visit)(T c), int start)
{
	bool visited[MaxVertexNum];
	int i, j;
	for (i = 0; i < vexnum; i++) visited[i] = false;
	for (i = start, j = 0; j < vexnum; i = (i + 1) % vexnum, j++) {
		if (!visited[i]) {
			BFS(i, visited, visit);
		}
	}
}
*/

template<typename T>
void ALGraph<T>::DFS(int i, bool* visited, void(*visit)(T c))
{
	visit(getVexElem(i));
	visited[i] = true;
	for (int w = firstneighbor(i); w >= 0; w = nextneighbor(i, w)) {
		if (!visited[w]) {
			DFS(w, visited, visit);
		}
	}
}

template<typename T>
void ALGraph<T>::initialize(map<T,int>& mp) {
	T c, x, y;
	int vn, an,info = 1;
	cout << "请输入顶点数和边/弧数" << endl;
	cin >> vn >> an;
	cout << "请输入每个顶点的字符数据" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "请输入边的两端（或弧的弧尾字符和弧头字符）,有权值的还需输入权值" << endl;
	for (int i = 0; i < an; i++) {
		cin >> x >> y;
		if (kind == UDN || kind == DN) cin >> info;
		addEdge(mp[x], mp[y], info);
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



template<typename T>
void ALGraph<T>::DFSTraverse(void(*visit)(T c), int start)
{
	bool visited[MaxVertexNum];
	int i, j;
	for (i = 0; i < vexnum; i++) visited[i] = false;
	for (i = start, j = 0; j < vexnum; i = (i + 1) % vexnum, j++) {
		if (!visited[i]) {
			DFS(i, visited, visit);
		}
	}
}

/*
int main() {
	ALGraph<char> graph(DG);
	map<char, int> mp;
	char c,x,y;
	int s,t;
	
	graph.initialize(mp);

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
	if (graph.adjacent(mp[x],mp[y])) graph.removeEdge(mp[x],mp[y]);
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