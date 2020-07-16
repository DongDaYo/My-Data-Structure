#include "OLGraph.h"

template<typename T>
void OLGraph<T>::initialize(map<T,int>& mp) {
	T c, x, y;
	int vn, an;
	cout << "�����붥�����ͻ���" << endl;
	cin >> vn >> an;
	cout << "������ÿ��������ַ�����" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "�����뻡�Ļ�β�ַ��ͻ�ͷ�ַ�" << endl;
	for (int i = 0; i < an; i++) {
		cin >> x >> y;
		addEdge(mp[x], mp[y]);
	}
}

template<typename T>
bool OLGraph<T>::adjacent(int x, int y)
{
	ArcNode* p = vertices[x].firstout;
	while (p && p->headvex != y) {
		p = p->tlink;
	}
	if (p) return true;
	else return false;
}

template<typename T>
int OLGraph<T>::insertVertex(T x)
{
	vertices[vexnum].data = x;
	return vexnum++;
}

template<typename T>
void OLGraph<T>::addEdge(int x, int y, int info)
{
	ArcNode* p = new ArcNode;
	p->tailvex = x;
	p->headvex = y;
	p->info = info;
	p->tlink = vertices[x].firstout;
	p->hlink = vertices[y].firstin;
	vertices[x].firstout = p;
	vertices[y].firstin = p;
}

template<typename T>
void OLGraph<T>::removeEdge(int x, int y)
{
	ArcNode* p=NULL, * q = NULL, * r,* s ;
	r = vertices[x].firstout;
	if (r->headvex == y) {
		vertices[x].firstout = r->tlink;
	}else {
		while (r && r->headvex != y) {
			p = r;
			r = r->tlink;
		}
		if (r) p->tlink = r->tlink;
	}
	s = vertices[y].firstin;
	if (s->tailvex == x) {
		vertices[y].firstin = s->hlink;
	}
	else {
		while (s && s->tailvex != x) {
			q = s;
			s = s->hlink;
		}
		if (s) q->hlink = s->hlink;
	}
	if (r == s) delete r;
}

template<typename T>
int OLGraph<T>::firstneighbor(int x)
{
	ArcNode* p = vertices[x].firstout;
	if (p) return p->headvex;
	else return -1;
}

template<typename T>
int OLGraph<T>::firstInneighbor(int x)
{
	ArcNode* p = vertices[x].firstin;
	if (p) return p->tailvex;
	else return -1;
}

template<typename T>
int OLGraph<T>::nextneighbor(int x, int y)
{
	ArcNode* p = vertices[x].firstout;
	while (p && p->headvex != y) {
		p = p->tlink;
	}
	if (p && p->tlink) return p->tlink->headvex;
	else return -1;
}

template<typename T>
int OLGraph<T>::nextInneighbor(int x, int y)
{
	ArcNode* p = vertices[x].firstin;
	while (p && p->tailvex != y) {
		p = p->hlink;
	}
	if (p && p->hlink) return p->hlink->tailvex;
	return -1;
}

template<typename T>
int OLGraph<T>::getEdgeValue(int x, int y)
{
	ArcNode* p = vertices[x].firstout;
	while (p && p->headvex != y) {
		p = p->tlink;
	}
	if (p) return p->info;
	return -1;
}

template<typename T>
bool OLGraph<T>::setEdgeValue(int x, int y, int info)
{
	ArcNode* p = vertices[x].firstout;
	while (p && p->headvex != y) {
		p = p->tlink;
	}
	if (p) {
		p->info = info;
		return true;
	}
	else {
		return false;
	}
}
/*
int main() {
	OLGraph<char> graph;
	map<char, int> mp;
	char x, y;
	int s;
	graph.initialize(mp);
	cout << "��������Ҫ�ж��Ƿ��л���������㣬�����뻡β" << endl;
	for (int i = 0; i < 8; i++) {
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << x << "��" << y << "֮���л�" << endl;
		}else {
			cout << x << "��" << y << "֮��û�л�" << endl;
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "������x,��x�׸������Ļ�ͷ" << endl;
		cin >> x;
		s = graph.firstneighbor(mp[x]);
		if (s < 0) {
			cout << x << "û�г���" << endl;
		}else {
			cout << x << "���������Ļ�ͷ��" << graph.getVexElem(s) << endl;
			while (s >= 0) {
				s = graph.nextneighbor(mp[x], s);
				if (s>=0) cout << "���������Ļ�ͷ��" << graph.getVexElem(s) << endl;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "������x,��x�׸��뻡�Ļ�β" << endl;
		cin >> x;
		s = graph.firstInneighbor(mp[x]);
		if (s < 0) {
			cout << x << "û���뻡" << endl;
		}
		else {
			cout << x << "�����뻡�Ļ�β��" << graph.getVexElem(s) << endl;
			while (s >= 0) {
				s = graph.nextInneighbor(mp[x], s);
				if (s>=0) cout << "�����뻡�Ļ�β��" << graph.getVexElem(s) << endl;
			}
		}
	}
	return 0;
}
*/