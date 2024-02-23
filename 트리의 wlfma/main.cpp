#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

struct Edge {     //구조체를 만들어 메모리 효율적으로 사용
	int to;     
	int weight;
	Edge(int t, int w) {
		to = t;
		weight = w;
	}
};
int n;
vector<int> d;     //이차원 배열로 만들면 메모리초과나옴 한번 사용하고 재사용
vector<Edge> tree[10001];   //메모리를 아끼기 위한 인접리스트 
//vector<int> tree[10001];  이 방식으로하면 미리 초기화를 해야해서 메모리 낭비가 남(인접 행렬이 됨)
vector<int> start_node;  //시작점 저장할 곳
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
				d[y] = d[x] + tree[x][i].weight;    //dp와 유사한 방식으로 거리를 저장해 놓는다
			}
		}
	}

}
int main() {
	int node1, node2, w, i, j, maxD=0;
	cin >> n;
	for (i = 0; i < n - 1; i++) {  //트리이므로 양방향 연결리스트
		cin >> node1 >> node2 >> w;
		tree[node1].push_back(Edge(node2, w));
		tree[node2].push_back(Edge(node1, w));
	}
	for (i = 0; i <= n; i++) {
		if (tree[i].size() == 1)
			start_node.push_back(i);
	}

	for (i = 0; i < start_node.size(); i++) {
		bfs(start_node[i]);    //리프 노드에서만 출발
	
		for(j=0; j<=n; j++)
		    maxD = max(d[j], maxD);
	}

	cout << maxD;


}