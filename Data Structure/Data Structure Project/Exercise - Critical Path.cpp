/*
#include "MGraph.cpp"
#include "LinkStack.cpp"
//#include <fstream>
#define MaxEdgeNum 30
using namespace std;

typedef struct edgedata {
	int e;
	int l;
	int d;
	int headvex;
	int tailvex;
	int time;
}edgedata;

int main() {//关键活动，求非关键活动的时间余量
	cout << "请把源点放在首位，汇点放在末位" << endl;
	MGraph<int> graph(DN);
	map<int, int> mp;
    int ve[MaxVertexNum];
	int vl[MaxVertexNum];

	//ifstream in;
	//in.open("data.txt");
	//if (!in) {
		//cout << "读取失败\n";
		//return 0;
	}
	int c, x, y, time;;
	int vn, an, info = 1;
	cout << "请输入顶点数和弧数" << endl;
	cin >> vn >> an;
	cout << "请输入每个顶点的编号数据" << endl;
	for (int i = 0; i < vn; i++) {
		cin >> c;
		mp[c] = graph.insertVertex(c);
	}
	edgedata s[MaxEdgeNum];
	cout << "请输入弧的弧头编号和弧尾编号以及权值" << endl;
	for (int i = 0; i < an; i++) {
		cin >> x >> y >> info;
		graph.addEdge(mp[x], mp[y], info);
		s[i].headvex = mp[y];
		s[i].tailvex = mp[x];
		s[i].time = info;
	}

	LinkStack<int> stack;
	ve[0] = 0;
	stack.push(0);
	int* p = graph.indegrees();
	while (!stack.isEmpty()) {
		stack.pop(x);
		for (y = graph.firstneighbor(x); y >= 0; y = graph.nextneighbor(x, y)) {
			(*(p + y))--;
			time = graph.getEdgeValue(x, y);
			if (ve[y] < ve[x] + time) ve[y] = ve[x] + time;
			if (*(p + y) == 0) stack.push(y);
		}
	}
	for (int i = 0; i < vn; i++) {
		vl[i] = ve[vn - 1];
	}
	stack.push(vn - 1);
	p = graph.outdegrees();
	while (!stack.isEmpty()) {
		stack.pop(x);
		for (y = graph.firstInneighbor(x); y >= 0; y = graph.nextInneighbor(x, y)) {
			(*(p + y))--;
			time = graph.getEdgeValue(y, x);
			if (vl[y] > vl[x] - time) vl[y] = vl[x] - time;
			if (*(p + y) == 0) stack.push(y);
		}
	}

	for (int i = 0; i < an; i++) {
		s[i].e = ve[s[i].tailvex];
		s[i].l = vl[s[i].headvex] - s[i].time;
		s[i].d = s[i].l - s[i].e;
		cout << "活动" << i + 1 << "的最早开始时间是" << s[i].e << ",最晚开始时间是" << s[i].l;
		if (s[i].d > 0) {
			cout << ",不是关键活动，其时间余量为" << s[i].d << endl;
		}else {
			cout << ",是关键活动" << endl;
		}
	}
	return 0;
}
*/