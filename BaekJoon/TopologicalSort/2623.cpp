#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M;
vector<int> mp[MAX];
vector<int> ans;
int in[MAX];
queue<int> q;

int topological()
{
	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			return -1;
		}
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (int j = 0; j < mp[cur].size(); j++) {
			int next = mp[cur][j];
			in[next]--;
			if (in[next] == 0) q.push(next);
		}
		
	}
	return 0;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int pd, prev; //pd의 수, 시작 정점
		cin >> pd;
		cin >> prev; 
		for (int j = 0; j < pd - 1; j++) {
			int node;
			cin >> node;
			mp[prev].push_back(node);
			in[node]++;
			prev = node;
		}
	}

	/* 진입 차수가 0이면 */
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	int result = topological();
	/* 사이클이 있다면 */
	if (result == -1) {
		cout << "0";
		return 0;
	}
	/* 위상 순서 출력 */
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}