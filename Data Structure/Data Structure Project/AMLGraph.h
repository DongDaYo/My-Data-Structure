#pragma once
#define MaxVertexNum 15
#include<iostream>
#include<map>
using namespace std;
typedef enum {UDG,UDN} Graphkind;
typedef struct ArcNode {
	int ivex, jvex;
	struct ArcNode* ilink = NULL, * jlink = NULL;
	int info;
}ArcNode;
template<typename T>
struct VNode {
	T data;
	ArcNode* firstedge = NULL;
};

template<typename T>
class AMLGraph
{
private:
	VNode<T> vertices[MaxVertexNum];
	int vexnum, arcnum;
	Graphkind kind;
	void BFS(int i, bool* visited, void(*visit)(T c));
public:
	AMLGraph<T>(Graphkind k = UDG) {
		vexnum = arcnum = 0;
		kind = k;
	}

	~AMLGraph<T>() {
		bool disposable[MaxVertexNum];
		ArcNode* p, * q = NULL;
		//int counter = 0;
		for (int k = 0; k < vexnum; k++) disposable[k] = false;
		for (int k = 0; k < vexnum; k++) {
			disposable[k] = true;
			p = vertices[k].firstedge;
			while (p) {
				if (p->ivex == k) {
					q = p->ilink;
				}
				else if (p->jvex == k) {
					q = p->jlink;
				}
				if (disposable[p->ivex] && disposable[p->jvex]) {
					//cout << "已释放"<<p->ivex<<"和"<<p->jvex<<"之间的边" << endl;
					delete p;
					//counter++;
				}
				p = q;
			}
		}
	//	cout << "共释放边结构体" << counter << "条" << endl;
	}


	int getVexnum() {
		return vexnum;
	}

	T getVexElem(int x) {
		return vertices[x].data;
	}

	void initialize(map<T, int>& mp);

	bool adjacent(int x, int y);
	int insertVertex(T x);
	void addEdge(int x, int y, int info = 1);
	void removeEdge(int x, int y);
	int firstneighbor(int x);
	int nextneighbor(int x, int y);//找y之后x的下一个相关联的点
	int getEdgeValue(int x, int y);
	bool setEdgeValue(int x, int y, int info);

	//void BFSTraverse(void(*visit)(T c), int start = 0);
};

