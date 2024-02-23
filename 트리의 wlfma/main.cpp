#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

struct Edge {     //����ü�� ����� �޸� ȿ�������� ���
	int to;     
	int weight;
	Edge(int t, int w) {
		to = t;
		weight = w;
	}
};
int n;
vector<int> d;     //������ �迭�� ����� �޸��ʰ����� �ѹ� ����ϰ� ����
vector<Edge> tree[10001];   //�޸𸮸� �Ƴ��� ���� ��������Ʈ 
//vector<int> tree[10001];  �� ��������ϸ� �̸� �ʱ�ȭ�� �ؾ��ؼ� �޸� ���� ��(���� ����� ��)
vector<int> start_node;  //������ ������ ��
vector<int> visit(10001, false);   

void bfs(int start) {
	int i, j;
	fill(visit.begin(), visit.end(), false);
	d.assign(10001, 0);
	queue<int>q;
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (i = 0; i < tree[x].size(); i++) {
			int y = tree[x][i].to;
			if (!visit[y]) {
				q.push(y);
				visit[y] = true;
				d[y] = d[x] + tree[x][i].weight;    //dp�� ������ ������� �Ÿ��� ������ ���´�
			}
		}
	}

}
int main() {
	int node1, node2, w, i, j, maxD=0;
	cin >> n;
	for (i = 0; i < n - 1; i++) {  //Ʈ���̹Ƿ� ����� ���Ḯ��Ʈ
		cin >> node1 >> node2 >> w;
		tree[node1].push_back(Edge(node2, w));
		tree[node2].push_back(Edge(node1, w));
	}
	for (i = 0; i <= n; i++) {
		if (tree[i].size() == 1)
			start_node.push_back(i);
	}

	for (i = 0; i < start_node.size(); i++) {
		bfs(start_node[i]);    //���� ��忡���� ���
	
		for(j=0; j<=n; j++)
		    maxD = max(d[j], maxD);
	}

	cout << maxD;


}