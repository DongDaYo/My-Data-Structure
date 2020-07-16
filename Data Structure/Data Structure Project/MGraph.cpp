#include "MGraph.h"
#include <map>
#include <iostream>
using namespace std;

template<typename T>
void MGraph<T>::initialize()
{
	cout << "�����붥�����ͱ���" << endl;
	cin >> vexnum >> arcnum;
	char c;
	cout << "�Ƿ�Ҫ����������ݣ���ѡ������ߵ�����ʱ���0��ʼΪ�����š�y:��/n:��" << endl;
	cin >> c;
	if (c == 'y') {
		for (int i = 0; i < vexnum; i++) {
			cin >> vex[i];
		}
	}
	T headdata, taildata;
	int head, tail, info = 1;
	if (kind == DG || kind == DN) {
		cout << "�����뻡�Ļ�β�ͻ�ͷ(��������������Ȩֵ��" << endl;
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
			edge[tail][head] = info;
		}
	}
	
	if (kind == UDG|| kind == UDN) {
		cout << "������ߵ�����(��������������Ȩֵ��" << endl;
		for (int i = 0; i < arcnum; i++) {
			cin >> taildata >> headdata;
			if (kind == UDN) cin >> info;
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
int MGraph<T>::nextneighbor(int x, int y)//x�ǻ�β��y�ǻ�ͷ������һ��x�ڽӵ��Ľ��
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

*//*
int main() {
	MGraph<char> graph(DG);
	map<char, int> mp;
	int vexnum, arcnum, idx;
	char c, x, y;
	cout << "�����붥�����ͱ���" << endl;
	cin >> vexnum >> arcnum;
	cout << "����������ÿ������Ӧ���ַ���" << endl;
	for (int i = 0; i < vexnum; i++) {
		cin >> c;
		idx = graph.insertVertex(c);
		mp[c] = idx;
	}
	cout << "�����뻡β���ַ��ͻ�ͷ���ַ�" << endl;
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