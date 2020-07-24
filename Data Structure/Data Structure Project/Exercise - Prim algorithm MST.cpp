/*
#include "MGraph.cpp"
using namespace std;

int main() {
	MGraph<char> graph(UDN);
	map<char, int> mp;
	graph.initialize(mp);
	bool isJoin[MaxVertexNum];
	int bestneighbor[MaxVertexNum] = { 0 };
	int lowCost[MaxVertexNum];
	int n = graph.getVexnum();
	for (int i = 0; i < n; i++) {
		isJoin[i] = false;
	}
	int choose = 0;
	isJoin[choose] = true;
	lowCost[choose] = 0;
	for (int i = 1; i < n; i++) {
		lowCost[i] = graph.getEdgeValue(0, i);
	}
	int minCost,prechoose,dis;
	for (int h = 1; h < n; h++) {//一共n-1轮选择
		minCost = 0;
		for (int i = 1; i < n; i++) {//先从lowCost[i]数组中选出最小的，最小值存放在变量minCost中，下标存放在prechoose中
			if (!isJoin[i]) {  //如果该顶点还未加入生成树
				dis = lowCost[i];
				if (dis > 0 && (minCost == 0 || dis < minCost)){
					minCost = dis;
					prechoose = i;
				}
			}
		}
		choose = prechoose;
		isJoin[choose] = true;
		for (int i = 1; i < n; i++) {
			if (!isJoin[i]) {
				dis = graph.getEdgeValue(choose, i);
				if (dis > 0 && (lowCost[i] == 0 || dis < lowCost[i])) {//如果choose和i节点间有边，则将此边权值与lowCost作比较
					lowCost[i] = dis;
					bestneighbor[i] = choose;
				}
			}
		}
	}
	cout << "MST中包含中的边为：" << endl;
	int cost = 0;
	for (int i = 1; i < n; i++) {
		cout << graph.getVexElem(i) << " " << graph.getVexElem(bestneighbor[i]) << endl;
		cost += lowCost[i];
	}
	cout << "树的带权路径总长为" << cost << endl;
	return 0;
}
*/