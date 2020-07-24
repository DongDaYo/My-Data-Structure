#pragma once
#include<limits.h>
#include <string.h>
#include <map>
#define MaxVertexNum 15
using namespace std;
typedef enum {DG,DN,UDG,UDN} GraphKind;

template <typename T>
class MGraph
{
private:
	T vertices[MaxVertexNum]; //结点数据表
	int edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
	GraphKind kind;

	//void BFS(int i, bool* visited, void(*visit)(T c));
	void DFS(int i, bool* visited, void(*visit)(T c));
public:

	MGraph<T>(GraphKind k = DG) {
		kind = k;
		vexnum = arcnum = 0;
		for (int i = 0; i < MaxVertexNum; i++) {
			memset(edge[i],0, sizeof(edge[i]));
		}
	}
	int getVexnum() {
		return vexnum;
	}

	T getVexElem(int x) {
		return vertices[x];
	}

	void initialize(map<T, int>& mp);
	bool adjacent(int x, int y);
	int insertVertex(T x);//插入一个新的顶点，返回其在结点数组的下标
	void addEdge(int x, int y,int info = 1);//增加一条边或弧，为弧时x是弧尾，y是弧头
	void removeEdge(int x, int y);
	int firstneighbor(int x);//找到图中下标为x的顶点的第一个邻接点，没有则返回-1
	int firstInneighbor(int x);
	int nextneighbor(int x, int y);//假设y是x的邻接点，找x的邻接点中除y之外的下一个邻接点，如果y是最后一个，则返回0;
	                                  //对于有向图，如果从x到y有弧，则返回x的下一条出弧的弧头
	int nextInneighbor(int x, int y);
	int getEdgeValue(int x, int y);
	void setEdgeValue(int x, int y, int info);

	//void BFSTraverse(void(*visit)(T c), int start = 0);
	void DFSTraverse(void(*visit)(T c), int start = 0);
	int* indegrees();
	int* outdegrees();
};

