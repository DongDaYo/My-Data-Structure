#include "MGraph.cpp"

/*
static MGraph<char> graph(DN);
static int A[MaxVertexNum][MaxVertexNum];
static int path[MaxVertexNum][MaxVertexNum];

void printpath(int i, int j) {
	int k = path[i][j];
	if (k == -1) {
		cout << graph.getVexElem(i) << "->" << graph.getVexElem(j);
	}
	else {
		printpath(i, k);
		cout << ",";
		printpath(k, j);
	}
}

int main() {
	map<char, int> mp;
	graph.initialize(mp);
	int n = graph.getVexnum();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = graph.getEdgeValue(i, j);
			path[i][j] = -1;
		}
	}
	int dis1,dis2;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis1 = A[i][k];
				dis2 = A[k][j];
				if (dis1 > 0 && dis2 > 0 && (A[i][j] == 0 || A[i][j] > dis1 + dis2)) {
					A[i][j] = dis1 + dis2;
					path[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (A[i][j] > 0) {
					cout << "从" << graph.getVexElem(i) << "到" << graph.getVexElem(j) << "的最短距离是" << A[i][j];
					cout << ",最短路径是:";
					printpath(i, j);
				}
				else {
					cout << "从" << graph.getVexElem(i) << "到" << graph.getVexElem(j) << "不可达";
				}
				cout << endl;
			}
		}
	}
	return 0;
}
*/