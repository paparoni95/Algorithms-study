#include <bits/stdc++.h>
using namespace std;

class Virus {
public:
	int index;
	int second;
	int x;
	int y;
	Virus(int index, int second, int x, int y)
		:index(index), second(second), x(x),y(y) { }
	// 정렬 기준은 '번호가 낮은 순서'
	bool operator<(Virus& other) {
		return this->index < other.index;
	}
};

int n, k;
int graph[200][200];
vector<Virus> viruses;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] != 0) {
				// {바이러스 종류, 시간, x, y}
				viruses.push_back(Virus(graph[i][j], 0, i, j));
			}
		}
	}

	// 정렬 이후에 큐로 옮기기 (낮은 번호의 바이러스가 먼저 증식하므로)
	sort(viruses.begin(), viruses.end());
	queue<Virus> q;
	for (int i = 0; i < viruses.size(); i++) {
		q.push(viruses[i]);
	}

	int target_s, target_x, target_y;
	cin >> target_s >> target_x >> target_y;

	// BFS 진행
	while (!q.empty()) {
		Virus virus = q.front();
		q.pop();
		// 정확히 second만큼 초가 지나거나, 큐가 빌 때까지 반복
		if (virus.second == target_s) break;
		// 현재 노드에서 주변 4가지 위치를 각각 확인
		for (int i = 0; i < 4; i++) {
			int nx = virus.x + dx[i];
			int ny = virus.y + dy[i];
			// 해당 위치로 이동할 수 있는 경우
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// 아직 방문하지 않은 위치라면, 그 위치에 바이러스 넣기
				if (graph[nx][ny] == 0) {
					graph[nx][ny] = virus.index;
					q.push(Virus(virus.index, virus.second + 1, nx, ny));
				}
			}
		}
	}

	cout << graph[target_x - 1][target_y - 1] << '\n';
	return 0;
}