#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	else return false;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// 간선의 비용을 기준으로 오름차순으로 정렬
	sort(v.begin(), v.end());

	// 각 정점이 포함된 그래프가 어디인지 저장
	// 사이클 테이블
	int parent[8];
	for (int i = 1; i <= 7; i++) {
		parent[i] = i;
	}

	int sum = 0; // 최소 비용 신장 트리를 만드는데 드는 비용의 총합
	for (int i = 0; i < v.size(); i++) {
		// 사이클이 발생하지 않는 경우 그래프에 포함한다.
		if (!findParent(parent, v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0], v[i].node[1]);
		}
	}
	cout << sum;
	return 0;
}