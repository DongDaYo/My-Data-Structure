/*
#include "AMLGraph.cpp";
#include <algorithm>
#define MaxEdgeNum 30
typedef struct Edge {
	int ivex, jvex;
	int weight;
	bool selected;
}Edge;

typedef struct DisjointSet {
	int parent;
	int rank;
}DisjointSet;

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

int main() {
	AMLGraph<char> graph(UDN);
	map<char, int> mp;
	graph.initialize(mp);
	Edge s[MaxEdgeNum];
	DisjointSet ds[MaxVertexNum];
	bool savable[MaxVertexNum];
	int n = graph.getVexnum();
	int edges = 0,i,j,p,q;
	for (i = 0; i < n; i++) {
		savable[i] = false;
		ds[i] = { -1,1 };
	}
	for (i = 0; i < n; i++) {
		savable[i] = true;
		for (j = graph.firstneighbor(i); j >= 0; j = graph.nextneighbor(i, j)) {
			if (savable[i] && savable[j]) {
				s[edges++] = { i,j,graph.getEdgeValue(i,j),false };
			}
		}
	}
	sort(s, s + edges, cmp);//将所有边按权值大小排列
	for (int e = 0; e < edges; e++) {//按权值从小到大遍历边的集合，两端不属同一集合的边应该被选中，再合并两端所属集合
		p = i = s[e].ivex;
		q = j = s[e].jvex;
		while (-1 != ds[p].parent) {
			p = ds[p].parent;
		}
		while (-1 != ds[q].parent) {
			q = ds[q].parent;
		}
		if (p != q) {//如果边的两端不属于同一集合，就把它们并入同一集合，即让其中一方的祖先成为另一方祖先的父亲
			s[e].selected = true;//选中此边加入生成树
			if (ds[q].rank > ds[p].rank) {
				ds[p].parent = q;
			}
			else if (ds[q].rank < ds[p].rank) {
				ds[q].parent = p;
			}
			else {
				ds[p].parent = q;
				ds[q].rank++;
			}
		}
	}
	cout << "MST中包含中的边为：" << endl;
	int cost = 0;
	for (int e = 0; e < edges; e++) {
		if (s[e].selected) {
			cout << graph.getVexElem(s[e].ivex) << " " << graph.getVexElem(s[e].jvex) << endl;
			cost += s[e].weight;
		}
	}
	cout << "树的带权路径总长为" << cost << endl;
	return 0;
}
*/