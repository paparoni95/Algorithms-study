#include <bits/stdc++.h>
using namespace std;

int L, R, C;
char board[31][31][31];
bool visited[31][31][31];

const int dx[] = { 0,0,-1,1,0,0 };
const int dy[] = { 1,-1,0,0,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

tuple<int,int,int> s, e;

void BFS() {
	queue<tuple<int, int, int, int>> q; // (z,x,y,cnt)
	q.push({ get<0>(s), get<1>(s), get<2>(s), 0 });
	visited[get<0>(s)][get<1>(s)][get<2>(s)] = true;
	while (!q.empty()) {
		int z = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		int cnt = get<3>(q.front());
		q.pop();

		if (z == get<0>(e) && x == get<1>(e) && y == get<2>(e)) {
			cout << "Escaped in " << cnt << " minute(s).\n";
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nz < 0 || nx < 0 || nz < 0 || nz >= L || nx >= R || ny >= C) continue;
			if (visited[nz][nx][ny] || board[nz][nx][ny] == '#') continue;
			visited[nz][nx][ny] = true;
			q.push({ nz,nx,ny, cnt + 1 });
		}
	}

	cout << "Trapped!\n";
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin>>L>>R>>C) {
		//cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				for (int k = 0; k < 31; k++) {
					visited[i][j][k] = false;
				}
			}
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string str;
				cin >> str;
				for (int k = 0; k < str.length(); k++) {
					board[i][j][k] = str[k];
					if (str[k] == 'S') s = { i,j,k };
					else if (str[k] == 'E') e = { i,j,k };
				}
			}
		}

		BFS();
	}
	return 0;
}