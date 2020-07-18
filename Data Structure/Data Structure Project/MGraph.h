#pragma once
#include<limits.h>
#include <string.h>
#include <map>
#define MaxVertexNum 12
using namespace std;
typedef enum {DG,DN,UDG,UDN} GraphKind;
struct edges {
	int pt[MaxVertexNum];//ָ�������ָ�룬���ڴ��һϵ�н��ı�ţ�
	int inpt[MaxVertexNum];//��������ͼ������뻡��β�������ָ��
	int num;//���ĸ���
	int inum;//inpt�ĸ�����
};

template <typename T>
class MGraph
{
private:
	T vertices[MaxVertexNum]; //������ݱ�
	int edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
	GraphKind kind;

	void BFS(int i, bool* visited, void(*visit)(T c));
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
	edges neighbors(int x);//����һ��edges�ṹ�pt����x������Ķ�������飬numΪ����Ԫ�صĸ���
	                       //��������ͼ��pt���������x������Ķ�������飬numΪ��x������Ķ���ĸ�����inptΪ�գ�inumΪ0
	                       //��������ͼ��pt�������x�ڽӵ��Ķ��㣨������ͷ�������飬numΪx�ĳ���������
	                       //            inpt��������ڽ���x�Ķ��㣨�뻡��β�������飬inumΪx���뻡��������
	int insertVertex(T x);//����һ���µĶ��㣬�������ڽ��������±�
	void addEdge(int x, int y,int info = 1);//����һ���߻򻡣�Ϊ��ʱx�ǻ�β��y�ǻ�ͷ
	void removeEdge(int x, int y);
	int firstneighbor(int x);//�ҵ�ͼ���±�Ϊx�Ķ���ĵ�һ���ڽӵ㣬û���򷵻�-1
	int firstInneighbor(int x);
	int nextneighbor(int x, int y);//����y��x���ڽӵ㣬��x���ڽӵ��г�y֮�����һ���ڽӵ㣬���y�����һ�����򷵻�0;
	                                  //��������ͼ�������x��y�л����򷵻�x����һ�������Ļ�ͷ
	int nextInneighbor(int x, int y);
	int getEdgeValue(int x, int y);
	void setEdgeValue(int x, int y, int info);

	void BFSTraverse(void(*visit)(T c), int start = 0);
	void DFSTraverse(void(*visit)(T c), int start = 0);
};

