/*
#include "MGraph.cpp"
#include "LinkStack.cpp"


int main() {
	MGraph<char> graph(UDN);
	map<char, int> mp;
	graph.initialize(mp);
	char c;
	cout << "请输入源点处的编号" << endl;
	cin >> c;
	int start = mp[c];
	bool final[MaxVertexNum];
	int dist[MaxVertexNum];
	int path[MaxVertexNum];
	int n = graph.getVexnum();
	for (int i = 0; i < n; i++) {
		final[i] = false;
		dist[i] = graph.getEdgeValue(start, i);
		path[i] = dist[i]>0? start : -1;
	}
	final[start] = true;
	path[start] = -1;
	int minlength,temp,dis,choice = start;
	for (int i = 0; i < n-1; i++) {
		minlength = 0;
		temp = -1;
	    for (int j = 0; j < n; j++) {//遍历dist数组从其中选择一个最小的
			if (!final[j]) {
				if (dist[j] > 0 && (minlength == 0 || minlength > dist[j])) {
					minlength = dist[j];
					temp = j;
				}
			}
		}
		if (temp < 0) break;//所有可达结点都已处理完毕
		else {
			choice = temp;
			final[choice] = true;
		}
		for (int j = 0; j < n; j++) {
			if (!final[j]) {
				dis = graph.getEdgeValue(choice, j);
				if (dis > 0 && (dist[j] == 0 || dist[j] > dist[choice] + dis)) {
					dist[j] = dist[choice] + dis;
					path[j] = choice;
				}
			}
		}
	}
	LinkStack<int> stack;
	for (int i = 0; i < n; i++) {
		if (final[i] && i != start) {
			cout << "从源点" << graph.getVexElem(start) << "到";
		    cout << graph.getVexElem(i) << "的最短距离是" << dist[i] << ",";
			cout << "最短路径是：";
			int j = i;
			while (j >= 0 && final[j]) {
				stack.push(j);
				j = path[j];
			}
			while (!stack.isEmpty()) {
				stack.pop(j);
				cout << graph.getVexElem(j);
				if (j != i) cout << "->";
			}
			cout << endl;
		}else if (i!= start) {
			cout << "从源点" << graph.getVexElem(start) << "到" << graph.getVexElem(i) << "不可达\n";
		}
	}
	
	return 0;
}
*/