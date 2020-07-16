#include "MGraph.h"
#include <map>
#include <iostream>
using namespace std;

template<typename T>
void MGraph<T>::initialize()
{
	cout << "请输入顶点数和边数" << endl;
	cin >> vexnum >> arcnum;
	char c;
	cout << "是否要输入结点的数据？若选否，输入边的数据时须从0开始为顶点编号。y:是/n:否" << endl;
	cin >> c;
	if (c == 'y') {
		for (int i = 0; i < vexnum; i++) {
			cin >> vex[i];
		}
	}
	T headdata, taildata;
	int head, tail, info = 1;
	if (kind == DG || kind == DN) {
		cout << "请输入弧的弧尾和弧头(有向网还需输入权值）" << endl;
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
			edge[tail][head] = info;
		}
	}
	
	if (kind == UDG|| kind == UDN) {
		cout << "请输入边的两端(无向网还需输入权值）" << endl;
		for (int i = 0; i < arcnum; i++) {
			cin >> taildata >> headdata;
			if (kind == UDN) cin >> info;
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
			edge[tail][head] = info;
			edge[head][tail] = info;
		}
	}
}

template <typename T>
bool MGraph<T>::adjacent(int x, int y)
{
	return edge[x][y]>0;
}

template <typename T>
edges MGraph<T>::neighbors(int x)
{
	edges result;
	if (kind == DG || kind == DN) {
		int num = 0;
		for (int i = 0; i < vexnum; i++) {
			if (edge[x][i] > 0) {
				result.pt[num++] = i;
			}
		}
		int inum = 0;
		for (int i = 0; i < vexnum; i++) {
			if (edge[i][x] > 0) {
				result.inpt[inum++] = i;
			}
		}
		result.num = num; result.inum = inum;
	}
	else if (kind == UDG || kind == UDN) {
		int num = 0;
		for (int i = 0; i < vexnum; i++) {
			if (edge[x][i] > 0) {
				result.pt[num++] = i;
			}
		}
		result.num = num; result.inum = 0;
	}
	return result;
}


template <typename T>
int MGraph<T>::insertVertex(T x)
{
	vex[vexnum] = x;
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
		if (edge[x][i] > 0) return i;
	}
	return -1;
}

template<typename T>
int MGraph<T>::firstInneighbor(int x)
{
	for (int i = 0; i < vexnum; i++) {
		if (edge[i][x] > 0) return i;
	}
	return -1;
}


template<typename T>
int MGraph<T>::nextneighbor(int x, int y)//x是弧尾，y是弧头，求下一条x邻接到的结点
{
	for (int i = y + 1; i < vexnum; i++) {
		if (edge[x][i] > 0) {
			return i;
		}
	}
	return -1;
}

template<typename T>
int MGraph<T>::nextInneighbor(int x, int y)
{
	for (int i = y + 1; i < vexnum; i++) {
		if (edge[i][x] > 0) return i;
	}
	return -1;
}

template<typename T>
int MGraph<T>::getEdgeValue(int x, int y)
{
	return edges[x][y];
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

*//*
int main() {
	MGraph<char> graph(DG);
	map<char, int> mp;
	int vexnum, arcnum, idx;
	char c, x, y;
	cout << "请输入顶点数和边数" << endl;
	cin >> vexnum >> arcnum;
	cout << "请依次输入每个结点对应的字符：" << endl;
	for (int i = 0; i < vexnum; i++) {
		cin >> c;
		idx = graph.insertVertex(c);
		mp[c] = idx;
	}
	cout << "请输入弧尾的字符和弧头的字符" << endl;
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