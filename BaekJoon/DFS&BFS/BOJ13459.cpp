// https://deliorange.tistory.com/98, 나중에 다시 풀어보기
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pos {
	int redR, redC, blueR, blueC;
	Pos() {}
	Pos(int rr, int rc, int br, int bc)
		:redR(rr), redC(rc), blueR(br), blueC(bc) {}
};

int n, m, cnt;
char board[12][12];
bool vis[12][12][12][12];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<Pos> q;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			board[i][j] = str[j];
			if (board[i][j] == 'R') {
				a = i, b = j;
			}

			if (board[i][j] == 'B') {
				c = i, d = j;
			}
		}
	}

	vis[a][b][c][d] = true;
	q.push(Pos(a, b, c, d));
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int rr = q.front().redR, rc = q.front().redC;
			int br = q.front().blueR, bc = q.front().blueC;
			q.pop();

			if (board[rr][rc] == 'O') {
				cout << 1 << '\n';
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				int nbr = br, nbc = bc, nrr = rr, nrc = rc;
				bool bf = false;
				// move red
				while (board[nrr + dx[i]][nrc + dy[i]] != '#' && board[nrr][nrc] != 'O') {
					nrr += dx[i];
					nrc += dy[i];
				}
				// move blue
				while (board[nbr + dx[i]][nbc + dy[i]] != '#' && board[nbr][nbc] != 'O') {
					nbr += dx[i];
					nbc += dy[i];
					// 파란 구슬이 빠져나오면, 빨간 구슬이 먼저나와도 0이기 때문에
					if (board[nbr][nbc] == 'O') bf = true;
				}

				// 공이 서로 겹치게 되면, 나중에 온 공이 뒤로 물러난다.
				if ((nrr == nbr && nrc == nbc)) {
					switch (i) {
					case 0:
						if (bc > rc) nrc -= 1;
						else nbc -= 1;
						break;
					case 1:
						if (bc < rc) nrc += 1;
						else nbc += 1;
						break;
					case 2:
						if (br > rr) nrr -= 1;
						else nbr -= 1;
						break;
					case 3:
						if (br > rr) nbr += 1;
						else nrr += 1;
						break;
					}
				}
				// 파란공이 빠져나올 경우 패스
				if (bf) continue;
				// 이미 방문했더라면 패스
				if (vis[nrr][nrc][nbr][nbc]) continue;
				q.push(Pos(nrr, nrc, nbr, nbc));
				vis[nrr][nrc][nbr][nbc] = true;
			}
		}
		// 10번 이하로 움직여서 빠져나오지 못한다면 정답은 0
		cnt++;
		if (cnt > 10) break;
	}
	cout << 0 << '\n';
	return 0;
}