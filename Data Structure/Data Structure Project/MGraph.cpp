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
	cout << "请输入顶点数和边(弧)数" << endl;
	cin >> vn >> an;
	cout << "请输入每个顶点的编号数据" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = insertVertex(c);
	}
	cout << "请输入每边两端的编号（或弧的弧头编号和弧尾编号）,有权值的还需输入权值" << endl;
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
int MGraph<T>::nextneighbor(int x, int y)//x是弧尾，y是弧头，求下一条x邻接到的结点
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
	cout << "请输入顶点数和边数" << endl;
	cin >> vexnum >> arcnum;
	cout << "请依次输入每个结点对应的字符：" << endl;
	for (int i = 0; i < vexnum; i++) {
		cin >> c;
		idx= graph.insertVertex(c);
		mp[c] = idx;
	}
	cout << "请输入边的两端的字符" << endl;
	for (int i = 0; i < arcnum; i++) {
		cin >> x >> y;
		graph.addEdge(mp[x], mp[y]);
	}
	
	for (int j = 0; j < 3; j++) {
		cout << "请输入需要判断是否相邻的顶点的字符" << endl;
		cin >> x >> y;
		if (graph.adjacent(mp[x], mp[y])) {
			cout << "相邻接" << endl;
		}
		else {
			cout << "不相邻接" << endl;
		}
	}
	cout << "请输入想要查找关联的点的顶点的字符" << endl;
	cin >> c;
	edges r = graph.neighbors(mp[c]);
	cout << "与" << c << "相关联的点处的字符有:";
	for (int i = 0; i < r.num; i++) {
		cout <<graph.getVexElem(r.pt[i]) << " ";
	}
	for (int k = 0; k < 5; k++) {
		cout << "请输入想要查找首个关联的点的顶点的字符" << endl;
		cin >> x;
		int s = graph.firstneighbor(mp[x]);
		if (s >= 0) cout << "第一个" << x << "关联的顶点为" << graph.getVexElem(s) << endl;
		else cout << x << "没有相关联的顶点"<<endl;
		cout << "请输入想要查找某个顶点y后下一个x关联的点的顶点的字符" << endl;
		cin >> x >> y;
		int t = graph.nextneighbor(mp[x], mp[y]);
		if (t >= 0) cout << "下一个" << x << "关联的顶点为" << graph.getVexElem(t) << endl;
		else cout << y << "之后" << x << "没有相关联的顶点"<<endl;
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
		cout << "输入BFS的起点字符" << endl;
		cin >> c;
		graph.BFSTraverse(print, mp[c]);
		cout << endl;
	}
	for (int i = 0; i < 2; i++) {
		cout << "输入DFS的起点字符" << endl;
		cin >> c;
		graph.DFSTraverse(print, mp[c]);
		cout << endl;
	}
	/*
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

	for (int j = 0; j < 3; j++) {
		cout << "请输入想要查找关联的点的顶点的字符" << endl;
		cin >> c;
		edges r = graph.neighbors(mp[c]);
		if (r.num > 0) {
			cout << c << "的出弧弧头结点的字符有:";
			for (int i = 0; i < r.num; i++) {
				cout << graph.getVexElem(r.pt[i]) << " ";
			}
			cout << endl;
		}
		else {
			cout << c << "没有出弧" << endl;
		}
		if (r.inum > 0) {
			cout << c << "的入弧弧尾结点的字符有:";
			for (int i = 0; i < r.inum; i++) {
				cout << graph.getVexElem(r.inpt[i]) << " ";
			}
			cout << endl;
		}
		else {
			cout << c << "没有入弧" << endl;
		}
	}
	for (int k = 0; k < 3; k++) {
		cout << "请输入想要查找首个关联的点的顶点的字符" << endl;
		cin >> x;
		int s = graph.firstneighbor(mp[x]);
		if (s >= 0) cout << "第一个" << x << "邻接到的顶点为" << graph.getVexElem(s) << endl;
		else cout << x << "没有邻接到的顶点"<<endl;
		s = graph.firstInneighbor(mp[x]);
		if (s >= 0) cout << "第一个邻接到"<< x << "的顶点为" << graph.getVexElem(s) << endl;
		else cout << "没有邻接到" << x << "的顶点"<<endl;
	}
	for (int k = 0; k < 3; k++) {
		cout << "请输入想要查找某个顶点y后下一个x关联的点的顶点的字符" << endl;
		cin >> x >> y;
		int t = graph.nextneighbor(mp[x], mp[y]);
		if (t >= 0) cout << "下一个" << x << "邻接到的顶点为" << graph.getVexElem(t) << endl;
		else cout << y << "之后" << x << "没有邻接到的顶点" << endl;
		cout << endl;
	}
	
	return 0;
}
*/


