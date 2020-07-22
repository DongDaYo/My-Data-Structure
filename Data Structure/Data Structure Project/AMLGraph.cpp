#include "AMLGraph.h"
#include "LinkQueue.cpp"


static LinkQueue<int> queue;

template<typename T>
void AMLGraph<T>::BFS(int i, bool* visited, void(*visit)(T c))
{
	int v = i;
	visit(this->getVexElem(i));
	visited[i] = true;
	queue.enqueue(i);
	while (!queue.isEmpty()) {
		queue.dequeue(v);
		for (int w = firstneighbor(v); w >= 0; w = nextneighbor(v, w)) {
			if (!visited[w]) {
				visit(this->getVexElem(w));
				visited[w] = true;
				queue.enqueue(w);
			}
		}
	}
}

template <typename T>
void AMLGraph<T>::initialize(map<T, int>& mp) {
	T c, x, y;
	int vn, an, info = 1;
	cout << "请输入顶点数和边数" << endl;
	cin >> vn >> an;
	cout << "请输入每个顶点的编号" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "请输入每边两端的字符，如果有权值还需输入权值" << endl;
	for (int i = 0; i < an; i++) {
		cin >> x >> y;
		if (kind == UDN) cin >> info;
		addEdge(mp[x], mp[y], info);
	}
}

template<typename T>
bool AMLGraph<T>::adjacent(int x, int y)
{
	ArcNode* p = vertices[x].firstedge;
	while (p && p->ivex != y && p->jvex != y) {
		if (p->ivex == x) {
			p = p->ilink;
		}
		else if (p->jvex == x) {
			p = p->jlink;
		}
	}
	if (p) return true;
	else return false;
}

template<typename T>
int AMLGraph<T>::insertVertex(T x)
{
	vertices[vexnum].data = x;
	return vexnum++;
}

template<typename T>
void AMLGraph<T>::addEdge(int x, int y, int info)
{
	ArcNode* p = new ArcNode;
	p->ivex = x;
	p->jvex = y;
	p->info = info;
	p->ilink = vertices[x].firstedge;
	p->jlink = vertices[y].firstedge;
	vertices[x].firstedge = p;
	vertices[y].firstedge = p;
	arcnum++;
}

template<typename T>
void AMLGraph<T>::removeEdge(int x, int y)
{
	ArcNode* p=NULL, * q=NULL, * r, * s;
	r = vertices[x].firstedge;
	if (r->ivex == y ) {//r所指的边结构体，ivex是y，jvex是x,就让vertices[x].firstedge重链接到r->jlink上
		vertices[x].firstedge = r->jlink;
	}else if (r->jvex == y) {
		vertices[x].firstedge = r->ilink;
	}else {
		while (r && r->ivex != y && r->jvex != y) {
			p = r;
			if (r->ivex == x) {
				r = r->ilink;
			}else if (r->jvex == x) {
				r = r->jlink;
			}
		}
		if (r) {
			if (r->ivex == y) {//r所指的边结构体，ivex是y，jvex是x
				if (p->ivex == x) {
					p->ilink = r->jlink;
				}else if (p->jvex == x) {
					p->jlink = r->jlink;
				}
			}else if (r->jvex == y) {
				if (p->ivex == x) {
					p->ilink = r->ilink;
				}else if (p->jvex == x) {
					p->jlink = r->ilink;
				}
			}
		}
	}

	s = vertices[y].firstedge;
	if (s->ivex == x) {//s所指的边结构体，ivex是x，jvex是y,就让vertices[y].firstedge重链接到s->jlink上
		vertices[y].firstedge = s->jlink;
	}else if (s->jvex == x) {
		vertices[y].firstedge = s->ilink;
	}else {
		while (s && s->ivex != x && s->jvex != x) {
			q = s;
			if (s->ivex == y) {
				s = s->ilink;
			}else if (s->jvex == y) {
				s = s->jlink;
			}
		}
		if (s) {
			if (s->ivex == x) {//s所指的边结构体，ivex是x，jvex是y
				if (q->ivex == y) {
					q->ilink = s->jlink;
				}else if (q->jvex == y) {
					q->jlink = s->jlink;
				}
			}
			else if (s->jvex == x) {//s所指的边结构体，jvex是x，ivex是y
				if (q->ivex == y) {
					q->ilink = s->ilink;
				}else if (q->jvex == y) {
					q->jlink = s->ilink;
				}
			}
		}
	}
	if (r == s) {
		delete r;
		arcnum--;
	}
}

template<typename T>
int AMLGraph<T>::firstneighbor(int x)
{
	ArcNode* p = vertices[x].firstedge;
	if (p) {
		if (p->ivex == x) return p->jvex;
		else return p->ivex;
	}
	else {
		return -1;
	}
}

template<typename T>
int AMLGraph<T>::nextneighbor(int x, int y)
{
	ArcNode* p = vertices[x].firstedge;
	while (p && p->ivex != y && p->jvex != y) {
		if (p->ivex == x) p = p->ilink;
		else p = p->jlink;
	}
	if (p) {
		if (p->ivex == y) {
			p = p->jlink;
		}else if (p->jvex == y) {
			p = p->ilink;
		}
		if (p && p->ivex == x) {
			return p->jvex;
		}else if (p && p->jvex == x) {
			return p->ivex;
		}else {
			return -1;
		}
	}else {
		return -1;
	}
}

template<typename T>
int AMLGraph<T>::getEdgeValue(int x, int y)
{
	ArcNode* p = vertices[x].firstedge;
	while (p && p->ivex != y && p->jvex != y) {
		if (p->ivex == x) p = p->ilink;
		else p = p->jlink;
	}
	if (p && (p->ivex == y || p->jvex == y)) {
		return p->info;
	}
	else {
		return -1;
	}
}

template<typename T>
bool AMLGraph<T>::setEdgeValue(int x, int y, int info)
{
	ArcNode* p = vertices[x].firstedge;
	while (p && p->ivex != y && p->jvex != y) {
		if (p->ivex == x) p = p->ilink;
		else p = p->jlink;
	}
	if (p && (p->ivex == y || p->jvex == y)) {
		p->info = info;
		return true;
	}
	else {
		return false;
	}
}



template<typename T>
void AMLGraph<T>::BFSTraverse(void(*visit)(T c), int start)
{
	bool visited[MaxVertexNum];
	int i, j;
	for (i = 0; i < vexnum; i++) {
		visited[i] = false;
	}
	for (i = start, j = 0; j < vexnum; i = (i+1)%vexnum, j++) {
		if (!visited[i]) {
			BFS(i, visited, visit);
		}
	}

}

/*
void print(char c) {
	cout << c << " ";
}

int main() {
	AMLGraph<char> graph;
	map<char, int> mp;
	char x, y;
	int s;
	graph.initialize(mp);
	for (s = 0; s < 5; s++) {
		cout << "请输入想要广度优先遍历的起点" << endl;
		cin >> x;
		graph.BFSTraverse(print, mp[x]);
		cout << endl;
	}
	cout << "请输入需要判断是否有边的两个结点" << endl;
	for (int i = 0; i < 6; i++) {
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << x << "和" << y << "之间有边" << endl;
		}
		else {
			cout << x << "和" << y << "之间没有边" << endl;
		}
	}
	for (int i = 0; i < 6; i++) {
		cout << "请输入x,求x首边" << endl;
		cin >> x;
		s = graph.firstneighbor(mp[x]);
		if (s < 0) {
			cout << x << "没有边" << endl;
		}
		else {
			cout << x << "首条边的另一端是" << graph.getVexElem(s) << endl;
			while (s >= 0) {
				s = graph.nextneighbor(mp[x], s);
				if (s >= 0) cout << "下条边的另一端是" << graph.getVexElem(s) << endl;
			}
		}
	}
	
	return 0;
}
*/