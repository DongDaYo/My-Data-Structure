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
	for (int h = 1; h < n; h++) {//һ��n-1��ѡ��
		minCost = 0;
		for (int i = 1; i < n; i++) {//�ȴ�lowCost[i]������ѡ����С�ģ���Сֵ����ڱ���minCost�У��±�����prechoose��
			if (!isJoin[i]) {  //����ö��㻹δ����������
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
				if (dis > 0 && (lowCost[i] == 0 || dis < lowCost[i])) {//���choose��i�ڵ���бߣ��򽫴˱�Ȩֵ��lowCost���Ƚ�
					lowCost[i] = dis;
					bestneighbor[i] = choose;
				}
			}
		}
	}
	cout << "MST�а����еı�Ϊ��" << endl;
	int cost = 0;
	for (int i = 1; i < n; i++) {
		cout << graph.getVexElem(i) << " " << graph.getVexElem(bestneighbor[i]) << endl;
		cost += lowCost[i];
	}
	cout << "���Ĵ�Ȩ·���ܳ�Ϊ" << cost << endl;
	return 0;
}
*/