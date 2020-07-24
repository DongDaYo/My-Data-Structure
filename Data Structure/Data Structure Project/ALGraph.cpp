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
	cout << "�����붥�����ͱ�/����" << endl;
	cin >> vn >> an;
	cout << "������ÿ��������ַ�����" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "������ߵ����ˣ��򻡵Ļ�β�ַ��ͻ�ͷ�ַ���,��Ȩֵ�Ļ�������Ȩֵ" << endl;
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
		cout << "��������Ҫ�ж�����������Ƿ��л��Ļ�β�ַ��ͻ�ͷ�ַ�" << endl;
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << x << "��" << y << "�л�" << endl;
		}
		else {
			cout << x << "��" << y << "û�л�" << endl;
		}
	}
	if (graph.adjacent(mp[x],mp[y])) graph.removeEdge(mp[x],mp[y]);
	for (int k = 0; k < 2; k++) {
		cout << "��������Ҫ�����׸������ĵ�Ķ�����ַ�" << endl;
		cin >> x;
		s = graph.firstneighbor(mp[x]);
		if (s >= 0) cout << "��һ��" << x << "�ڽӵ��Ķ���Ϊ" << graph.getVexElem(s) << endl;
		else cout << x << "û���ڽӵ��Ķ���" << endl;
		s = graph.firstInneighbor(mp[x]);
		if (s >= 0) cout << "��һ���ڽӵ�" << x << "�Ķ���Ϊ" << graph.getVexElem(s) << endl;
		else cout << "û���ڽӵ�" << x << "�Ķ���" << endl;
	}
	for (int k = 0; k < 6; k++) {
		cout << "��������Ҫ����ĳ������y����һ��x�����ĵ�Ķ�����ַ�" << endl;
		cin >> x >> y;
		t = graph.nextneighbor(mp[x], mp[y]);
		if (t >= 0) cout << "��һ��" << x << "�ڽӵ��Ķ���Ϊ" << graph.getVexElem(t) << endl;
		else cout << y << "֮��" << x << "û���ڽӵ��Ķ���" << endl;
		t = graph.nextInneighbor(mp[y], mp[x]);
		if (t >= 0) cout << "��һ���ڽӵ�" << y << "�Ķ���Ϊ" << graph.getVexElem(t) << endl;
		else cout << x << "֮��û���ڽӵ�" << y << "�Ķ���" << endl;
		cout << endl;
	}
	return 0;
}
*/