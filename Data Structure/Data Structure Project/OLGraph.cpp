#include "OLGraph.h"

template<typename T>
void OLGraph<T>::initialize(map<T,int>& mp) {
	T c, x, y;
	int vn, an;
	cout << "请输入顶点数和弧数" << endl;
	cin >> vn >> an;
	cout << "请输入每个顶点的字符数据" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "请输入弧的弧尾字符和弧头字符" << endl;
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
	cout << "请输入需要判断是否有弧的两个结点，先输入弧尾" << endl;
	for (int i = 0; i < 8; i++) {
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << x << "和" << y << "之间有弧" << endl;
		}else {
			cout << x << "和" << y << "之间没有弧" << endl;
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "请输入x,求x首个出弧的弧头" << endl;
		cin >> x;
		s = graph.firstneighbor(mp[x]);
		if (s < 0) {
			cout << x << "没有出弧" << endl;
		}else {
			cout << x << "首条出弧的弧头是" << graph.getVexElem(s) << endl;
			while (s >= 0) {
				s = graph.nextneighbor(mp[x], s);
				if (s>=0) cout << "下条出弧的弧头是" << graph.getVexElem(s) << endl;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "请输入x,求x首个入弧的弧尾" << endl;
		cin >> x;
		s = graph.firstInneighbor(mp[x]);
		if (s < 0) {
			cout << x << "没有入弧" << endl;
		}
		else {
			cout << x << "首条入弧的弧尾是" << graph.getVexElem(s) << endl;
			while (s >= 0) {
				s = graph.nextInneighbor(mp[x], s);
				if (s>=0) cout << "下条入弧的弧尾是" << graph.getVexElem(s) << endl;
			}
		}
	}
	return 0;
}
*/