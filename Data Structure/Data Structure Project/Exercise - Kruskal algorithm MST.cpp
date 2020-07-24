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
	sort(s, s + edges, cmp);//�����б߰�Ȩֵ��С����
	for (int e = 0; e < edges; e++) {//��Ȩֵ��С��������ߵļ��ϣ����˲���ͬһ���ϵı�Ӧ�ñ�ѡ�У��ٺϲ�������������
		p = i = s[e].ivex;
		q = j = s[e].jvex;
		while (-1 != ds[p].parent) {
			p = ds[p].parent;
		}
		while (-1 != ds[q].parent) {
			q = ds[q].parent;
		}
		if (p != q) {//����ߵ����˲�����ͬһ���ϣ��Ͱ����ǲ���ͬһ���ϣ���������һ�������ȳ�Ϊ��һ�����ȵĸ���
			s[e].selected = true;//ѡ�д˱߼���������
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
	cout << "MST�а����еı�Ϊ��" << endl;
	int cost = 0;
	for (int e = 0; e < edges; e++) {
		if (s[e].selected) {
			cout << graph.getVexElem(s[e].ivex) << " " << graph.getVexElem(s[e].jvex) << endl;
			cost += s[e].weight;
		}
	}
	cout << "���Ĵ�Ȩ·���ܳ�Ϊ" << cost << endl;
	return 0;
}
*/