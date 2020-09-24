#include <bits/stdc++.h>
using namespace std;

int n;
string plans;
int x = 1, y = 1;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char moveTypes[] = { 'L','R','U','D' };

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin.ignore(); // 버퍼 비우기 (여기서는 Enter)
	getline(cin, plans);
	// 이동 계획을 하나씩 확인
	for (int i = 0; i < plans.size(); i++) {
		char plan = plans[i];
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; j++) {
			if (plan == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}

		// 공간을 벗어나는 경우 무시
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		// 이동 수행
		x = nx;
		y = ny;
	}

	cout << x << ' ' << y << '\n';
	return 0;
}