#pragma once
#define MaxVertexNum 15
#include<iostream>
#include<map>
using namespace std;
typedef struct ArcNode {
	int tailvex, headvex;
	struct ArcNode* hlink=NULL, * tlink=NULL;
	int info;
}ArcNode;
template<typename T>
struct VNode {
	T data;
	ArcNode* firstin=NULL, * firstout=NULL;
};
template<typename T>
class OLGraph
{
private:
	VNode<T> vertices[MaxVertexNum];
	int vexnum, arcnum;

	void BFS(int i, bool* visited, void(*visit)(T c));
public:
	OLGraph<T>() {
		vexnum = arcnum = 0;
	}

	~OLGraph<T>() {
		int counter = 0;
		ArcNode* p, * q;
		for (int i = 0; i < vexnum; i++) {
			p = vertices[i].firstout;
			while (p) {
				q = p->tlink;
				delete p;
				counter++;
				p = q;
			}
		}
		//cout << "共释放边结构体" << counter << "个"<< endl;
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

	void BFSTraverse(void(*visit)(T c), int start = 0);
};

