/*
#include "MGraph.cpp"
#include "LinkStack.cpp"


int main() {
	MGraph<char> graph(UDN);
	map<char, int> mp;
	graph.initialize(mp);
	char c;
	cout << "������Դ�㴦�ı��" << endl;
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
	    for (int j = 0; j < n; j++) {//����dist���������ѡ��һ����С��
			if (!final[j]) {
				if (dist[j] > 0 && (minlength == 0 || minlength > dist[j])) {
					minlength = dist[j];
					temp = j;
				}
			}
		}
		if (temp < 0) break;//���пɴ��㶼�Ѵ������
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
			cout << "��Դ��" << graph.getVexElem(start) << "��";
		    cout << graph.getVexElem(i) << "����̾�����" << dist[i] << ",";
			cout << "���·���ǣ�";
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
			cout << "��Դ��" << graph.getVexElem(start) << "��" << graph.getVexElem(i) << "���ɴ�\n";
		}
	}
	
	return 0;
}
*/