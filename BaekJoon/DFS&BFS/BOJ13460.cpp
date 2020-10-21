#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pos {
	int redR, redC, blueR, blueC;
	Pos() {}
	Pos(int rr, int rc, int br, int bc)
		:redR(rr),redC(rc), blueR(br),blueC(bc){}
};

int n, m, cnt;
char board[12][12];
bool vis[12][12][12][12];

queue<Pos> q;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

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
			else if (board[i][j] == 'B') {
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
				cout << cnt << '\n';
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nrr = rr, nrc = rc;
				int nbr = br, nbc = bc;
				bool bf = false;
				// red move
				while (board[nrr + dx[i]][nrc + dy[i]] != '#' && board[nrr][nrc] != 'O') {
					nrr += dx[i];
					nrc += dy[i];
				}

				// blue move
				while (board[nbr + dx[i]][nbc + dy[i]] != '#' && board[nbr][nbc] != 'O') {
					nbr += dx[i];
					nbc += dy[i];
					if (board[nbr][nbc] == 'O') bf = true;
				}

				// °ãÄ¡´Â °æ¿ì
				if ((nrr == nbr) && (nrc == nbc)) {
					switch (i) {
					case 0:
						if (bc > rc) nrc -= 1;
						else nbc -= 1;
						break;
					case 1:
						if (bc > rc) nbc += 1;
						else nrc += 1;
						break;
					case 2:
						if (br > rr) nbr += 1;
						else nrr += 1;
						break;
					case 3:
						if (br > rr) nrr -= 1;
						else nbr -= 1;
						break;
					}
				}

				if (bf) continue;
				if (vis[nrr][nrc][nbr][nbc]) continue;
				vis[nrr][nrc][nbr][nbc] = true;
				q.push(Pos(nrr, nrc, nbr, nbc));
			}
		}
		cnt++;
		if (cnt > 10) break;
	}
	cout << -1 << '\n';
	return 0;
}