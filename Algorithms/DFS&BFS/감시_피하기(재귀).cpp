#include <bits/stdc++.h>
using namespace std;

#define MAX 7

int n;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
char m[MAX][MAX];
vector<pair<int, int>> v, t;

bool found;

// 선생님들이 학생들을 감시할 수 있는지
// 감시할 수 있다면 true
// 감시하지 못 한다면 false
bool check(pair<int, int> pt) {
	for (int i = 0; i < 4; i++) {
		int x = pt.first;
		int y = pt.second;
		while (0 <= x + dx[i] && x + dx[i] < n && 0 <= y + dy[i] && y + dy[i] < n) {
			x = x + dx[i];
			y = y + dy[i];
			// 장애물이면 더 이상 진행 불가능
			if (m[x][y] == '0') break;
			// 학생을 발견했으면 바로 true(감시할 수 있다는 의미)
			else if (m[x][y] == 'S') return true;
		}
	}
	return false;
}

void simulate(int len, int idx) {
	if (len == 3) {
		for (auto i : t) {
			// 선생님들이 단 1명이라도 감시할 수 있다면 return
			if (check(i)) return;
		}

		// 선생님들이 1명이라도 감시하지 못 한다면 종료
		found = true;
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		m[v[i].first][v[i].second] = '0'; // 장애물 설치
		simulate(len + 1, i + 1);
		m[v[i].first][v[i].second] = 'X'; // 장애물 해제
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'X') v.push_back({ i,j });
			else if (m[i][j] == 'T') t.push_back({ i,j });
		}
	}

	simulate(0, 0);
	if (found) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}