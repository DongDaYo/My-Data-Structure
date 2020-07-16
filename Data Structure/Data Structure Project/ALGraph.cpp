#include "ALGraph.h"
#include <map>
using namespace std;

template<typename T>
void ALGraph<T>::initialize() {
	ArcNode* p, * q;
	cout << "�����붥�����ͱ���" << endl;
	cin >> vexnum >> arcnum;
	char c;
	cout << "�Ƿ�Ҫ����������ݣ���ѡ������ߵ�����ʱ���0��ʼΪ�����š�y:��/n:��" << endl;
	cin >> c;
	if (c == 'y') {
		for (int i = 0; i < vexnum; i++) {
			cin >> vertices[i];
		}
	}
	T headdata, taildata;
	int head, tail, info = 1;
	if (kind == DG|| kind == DN) {
		cout << "�����뻡�Ļ�β�ͻ�ͷ(��������������Ȩֵ)" << endl;
		for (int i = 0; i < arcnum; i++) {
			cin >> taildata >> headdata;
			if (kind == DN) cin >> info;
			if (c == 'y') {
				tail = foundIndex(taildata);
				if (tail < 0) {
					cout << "����������������" << taildata << "�Ķ��㣬����������˱�����" << endl;
					i--;
					continue;
				}
				head = foundIndex(headdata);
				if (head < 0) {
					cout << "����������������" << headdata << "�Ķ��㣬����������˱�����" << endl;
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
		cout << "�����뻡�Ļ�β�ͻ�ͷ(��������������Ȩֵ)" << endl;
		for (int i = 0; i < arcnum; i++) {
			cin >> taildata >> headdata;
			if (kind == DN) cin >> info;
			if (c == 'y') {
				tail = foundIndex(taildata);
				if (tail < 0) {
					cout << "����������������" << taildata << "�Ķ��㣬����������˱�����" << endl;
					i--;
					continue;
				}
				head = foundIndex(headdata);
				if (head < 0) {
					cout << "����������������" << headdata << "�Ķ��㣬����������˱�����" << endl;
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
	cout << "�����붥�����ͻ���" << endl;
	cin >> vexnum >> arcnum;
	cout << "������ÿ��������ַ�����" << endl;
	for (int i = 0; i < vexnum; i++) {
		cin >> c;
		mp[c] = graph.insertVertex(c);
	}
	cout << "�����뻡�Ļ�β�ַ��ͻ�ͷ�ַ�" << endl;
	for (int i = 0; i < arcnum; i++) {
		cin >> x >> y;
		graph.addEdge(mp[x], mp[y]);
	}
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