#pragma once
#include <iostream>
#include <map>
#define MaxVertexNum 15
using namespace std;
typedef enum { DG, DN, UDG, UDN } GraphKind;
struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc = NULL;
	int info;
};

template <typename T>
struct VNode {
	T data;
	ArcNode* firstarc = NULL;
};

template <typename T>
class ALGraph
{
private:
	VNode<T>  vertices[MaxVertexNum];
	int vexnum, arcnum;
	GraphKind kind;

	int foundIndex(T data) {
		for (int i = 0; i < vexnum; i++) {
			if (vertices[i].data == data) return i;
		}
		return -1;
	}
public:
	ALGraph<T>(GraphKind k = DG) {
		kind = k;
		vexnum = arcnum = 0;
	}
	~ALGraph<T>() {
		ArcNode* p, *q;
		for (int i = 0; i < vexnum; i++) {
			p = vertices[i].firstarc;
			while (p) {
				q = p->nextarc;
				delete p;
				p = q;
			}
		}
	}
	int getVexnum() {
		return vexnum;
	}

	T getVexElem(int x) {
		return vertices[x].data;
	}

	void initialize(map<T,int>& mp);

	bool adjacent(int x, int y);
	int insertVertex(T x);
	void addEdge(int x, int y, int info = 1);
	void removeEdge(int x, int y);
	int firstneighbor(int x);
	int firstInneighbor(int x);
	int nextneighbor(int x, int y);
	int nextInneighbor(int x, int y);
	int getEdgeValue(int x, int y);
	bool setEdgeValue(int x, int y, int info);
};

