#include "MGraph.h"
//#include "LinkQueue.cpp"
#include <iostream>
using namespace std;

/*
static LinkQueue<int> queue;

template<typename T>
void MGraph<T>::BFS(int i, bool* visited, void(*visit)(T c))
{
	int v = i;
	queue.enqueue(i);
	while (!queue.isEmpty()) {
		queue.dequeue(v);
		if (!visited[v]) {
			visit(getVexElem(v));
			visited[v] = true;
		}
		for (int w = firstneighbor(v); w >= 0; w = nextneighbor(v, w)) {
			if (!visited[w]) {
				queue.enqueue(w);
			}
		}
	}
	
}

template<typename T>
void MGraph<T>::BFSTraverse(void(*visit)(T c), int start)
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
void MGraph<T>::DFS(int i, bool* visited, void(*visit)(T c))
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
void MGraph<T>::initialize(map<T, int>& mp){
	T c, x, y;
	int vn, an ,info=1;
	cout << "�����붥�����ͱ�(��)��" << endl;
	cin >> vn >> an;
	cout << "������ÿ������ı������" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "������ÿ�����˵ı�ţ��򻡵Ļ�ͷ��źͻ�β��ţ�,��Ȩֵ�Ļ�������Ȩֵ" << endl;
	for (int i = 0; i < an; i++) {
		cin >> x >> y;
		if (kind == UDN || kind == DN) cin >> info;
		addEdge(mp[x], mp[y], info);
	}

}

template <typename T>
bool MGraph<T>::adjacent(int x, int y)
{
	return edge[x][y]>0;
}

template <typename T>
int MGraph<T>::insertVertex(T x)
{
	vertices[vexnum] = x;
	return vexnum++;	 
}

template <typename T>
void MGraph<T>::addEdge(int x, int y, int info)
{
	if (kind == DG || kind == DN) {
		edge[x][y] = info;
	}
	else if (kind == UDG || kind == UDN) {
		edge[x][y] = info;
		edge[y][x] = info;
	}
	if (info > 0) {
		arcnum++;
	}
	else {
		arcnum--;
	}
}

template <typename T>
void MGraph<T>::removeEdge(int x, int y)
{
	addEdge(x, y, 0);
}

template<typename T>
int MGraph<T>::firstneighbor(int x)
{
	for (int i = 0; i < vexnum; i++) {
		if (x!= i && edge[x][i] > 0) return i;
	}
	return -1;
}

template<typename T>
int MGraph<T>::firstInneighbor(int x)
{
	for (int i = 0; i < vexnum; i++) {
		if (x != i && edge[i][x] > 0) return i;
	}
	return -1;
}


template<typename T>
int MGraph<T>::nextneighbor(int x, int y)//x�ǻ�β��y�ǻ�ͷ������һ��x�ڽӵ��Ľ��
{
	for (int i = y + 1; i < vexnum; i++) {
		if (x != i && edge[x][i] > 0) {
			return i;
		}
	}
	return -1;
}

template<typename T>
int MGraph<T>::nextInneighbor(int x, int y)
{
	for (int i = y + 1; i < vexnum; i++) {
		if (x != i && edge[i][x] > 0) return i;
	}
	return -1;
}

template<typename T>
int MGraph<T>::getEdgeValue(int x, int y)
{
	return edge[x][y];
}

template<typename T>
void MGraph<T>::setEdgeValue(int x, int y, int info)
{
	if (kind == UDN || kind == UDG) {
		edge[x][y] = info;
		edge[y][x] = info;
	}
	else if(kind == DG||kind == DN) {
		edge[x][y] = info;
	}
}



template<typename T>
void MGraph<T>::DFSTraverse(void(*visit)(T c), int start)
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

template<typename T>
int* MGraph<T>::indegrees()
{
	static int r[MaxVertexNum];
	for (int i = 0; i < vexnum; i++) {
		r[i] = 0;
		for (int j = 0; j < vexnum; j++) {
			if (edge[j][i] > 0) r[i]++;
		}
	}
	return r;
}

template<typename T>
int* MGraph<T>::outdegrees()
{
	static int r[MaxVertexNum];
	for (int i = 0; i < vexnum; i++) {
		r[i] = 0;
		for (int j = 0; j < vexnum; j++) {
			if (edge[i][j] > 0) r[i]++;
		}
	}
	return r;
}

/*
int main() {
	MGraph<char> graph(UDG);
	map<char, int> mp;
	int vexnum, arcnum,idx;
	char c,x,y;
	cout << "�����붥�����ͱ���" << endl;
	cin >> vexnum >> arcnum;
	cout << "����������ÿ������Ӧ���ַ���" << endl;
	for (int i = 0; i < vexnum; i++) {
		cin >> c;
		idx= graph.insertVertex(c);
		mp[c] = idx;
	}
	cout << "������ߵ����˵��ַ�" << endl;
	for (int i = 0; i < arcnum; i++) {
		cin >> x >> y;
		graph.addEdge(mp[x], mp[y]);
	}
	
	for (int j = 0; j < 3; j++) {
		cout << "��������Ҫ�ж��Ƿ����ڵĶ�����ַ�" << endl;
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << "���ڽ�" << endl;
		}
		else {
			cout << "�����ڽ�" << endl;
		}
	}
	cout << "��������Ҫ���ҹ����ĵ�Ķ�����ַ�" << endl;
	cin >> c;
	edges r = graph.neighbors(mp[c]);
	cout << "��" << c << "������ĵ㴦���ַ���:";
	for (int i = 0; i < r.num; i++) {
		cout <<graph.getVexElem(r.pt[i]) << " ";
	}
	for (int k = 0; k < 5; k++) {
		cout << "��������Ҫ�����׸������ĵ�Ķ�����ַ�" << endl;
		cin >> x;
		int s = graph.firstneighbor(mp[x]);
		if (s >= 0) cout << "��һ��" << x << "�����Ķ���Ϊ" << graph.getVexElem(s) << endl;
		else cout << x << "û��������Ķ���"<<endl;
		cout << "��������Ҫ����ĳ������y����һ��x�����ĵ�Ķ�����ַ�" << endl;
		cin >> x >> y;
		int t = graph.nextneighbor(mp[x], mp[y]);
		if (t >= 0) cout << "��һ��" << x << "�����Ķ���Ϊ" << graph.getVexElem(t) << endl;
		else cout << y << "֮��" << x << "û��������Ķ���"<<endl;
		cout << endl;
	}
	return 0;
}

*/
/*
void print(char c) {
	cout << c << " ";
}
int main() {
	MGraph<char> graph(DG);
	map<char, int> mp;
	int vexnum, arcnum, idx;
	char c, x, y;
	graph.initialize(mp);
	for (int i = 0; i < 0; i++) {
		cout << "����BFS������ַ�" << endl;
		cin >> c;
		graph.BFSTraverse(print, mp[c]);
		cout << endl;
	}
	for (int i = 0; i < 2; i++) {
		cout << "����DFS������ַ�" << endl;
		cin >> c;
		graph.DFSTraverse(print, mp[c]);
		cout << endl;
	}
	/*
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

	for (int j = 0; j < 3; j++) {
		cout << "��������Ҫ���ҹ����ĵ�Ķ�����ַ�" << endl;
		cin >> c;
		edges r = graph.neighbors(mp[c]);
		if (r.num > 0) {
			cout << c << "�ĳ�����ͷ�����ַ���:";
			for (int i = 0; i < r.num; i++) {
				cout << graph.getVexElem(r.pt[i]) << " ";
			}
			cout << endl;
		}
		else {
			cout << c << "û�г���" << endl;
		}
		if (r.inum > 0) {
			cout << c << "���뻡��β�����ַ���:";
			for (int i = 0; i < r.inum; i++) {
				cout << graph.getVexElem(r.inpt[i]) << " ";
			}
			cout << endl;
		}
		else {
			cout << c << "û���뻡" << endl;
		}
	}
	for (int k = 0; k < 3; k++) {
		cout << "��������Ҫ�����׸������ĵ�Ķ�����ַ�" << endl;
		cin >> x;
		int s = graph.firstneighbor(mp[x]);
		if (s >= 0) cout << "��һ��" << x << "�ڽӵ��Ķ���Ϊ" << graph.getVexElem(s) << endl;
		else cout << x << "û���ڽӵ��Ķ���"<<endl;
		s = graph.firstInneighbor(mp[x]);
		if (s >= 0) cout << "��һ���ڽӵ�"<< x << "�Ķ���Ϊ" << graph.getVexElem(s) << endl;
		else cout << "û���ڽӵ�" << x << "�Ķ���"<<endl;
	}
	for (int k = 0; k < 3; k++) {
		cout << "��������Ҫ����ĳ������y����һ��x�����ĵ�Ķ�����ַ�" << endl;
		cin >> x >> y;
		int t = graph.nextneighbor(mp[x], mp[y]);
		if (t >= 0) cout << "��һ��" << x << "�ڽӵ��Ķ���Ϊ" << graph.getVexElem(t) << endl;
		else cout << y << "֮��" << x << "û���ڽӵ��Ķ���" << endl;
		cout << endl;
	}
	
	return 0;
}
*/


