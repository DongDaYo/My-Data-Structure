#include "MGraph.cpp"
bool visited[MaxVertexNum];
int connect = 0;
int connectivity[MaxVertexNum] = { 0 };
MGraph<char> graph(DG);
map<char, int> mp;
int loop = 0;
bool back = false;

template<typename T>
void DFS(MGraph<T>& graph, int i) {
	visited[i] = true;
	connectivity[i] = connect;
	for (int j = graph.firstneighbor(i); j >= 0; j = graph.nextneighbor(i, j)) {
		if (visited[j] && !back && graph.adjacent(i,j) && connectivity[j]==connectivity[i]) {
		     loop++;
		}
		if (!visited[j]) {
			back = false;
			DFS(graph, j);
		}
		
	}
	back = true;
}

template<typename T>
void DFSTraverse(MGraph<T>& graph,int start) {
	int n = graph.getVexnum();
	int i, j;
	for (i = start, j = 0; j < n; i = (i+1)%n, j++) {
		if (!visited[i]) {
			connect++;
			back = false;
			DFS(graph, i);
		}
	}

}

int main() {
	graph.initialize(mp);
	int n = graph.getVexnum();
	int i;
	for (i = 0; i < n; i++) {
		visited[i] = false;
		connectivity[i] = 0;
	}
    DFSTraverse(graph, 0);
	
	if (loop == 0) {
		cout << "该有向图无环" << endl;
	}
	else {
		cout << "该有向图有环" << endl;
	}
	return 0;
}