#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int s;
int cnt[1001][1001];

void bfs(int screen, int board) {
	queue<pair<int, int>> q;
	q.push(make_pair(screen, board));
	memset(cnt, -1, sizeof(cnt));
	cnt[screen][board] = 0;
	while (!q.empty()) {
		int cur_screen = q.front().first;
		int cur_board = q.front().second;
		q.pop();

		// 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
		if (cnt[cur_screen][cur_screen] == -1) {
			cnt[cur_screen][cur_screen] = cnt[cur_screen][cur_board] + 1;
			q.push(make_pair(cur_screen, cur_screen));
		}

		// 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		if (cur_screen + cur_board <= s) {
			if (cnt[cur_screen + cur_board][cur_board] == -1) {
				cnt[cur_screen + cur_board][cur_board] = cnt[cur_screen][cur_board] + 1;
				q.push(make_pair(cur_screen + cur_board, cur_board));
			}
		}

		// 화면에 있는 이모티콘 중 하나를 삭제한다.
		if (cur_screen - 1 >= 0) {
			if (cnt[cur_screen - 1][cur_board] == -1) {
				cnt[cur_screen - 1][cur_board] = cnt[cur_screen][cur_board] + 1;
				q.push(make_pair(cur_screen - 1, cur_board));
			}
		}
	}
}

int main() {
	cin >> s;
	bfs(1, 0); // 영선이가 이미 화면에 이모티콘 1개를 입력했으므로 1부터 시작
	
	// 구하려고 하는 것은 이모티콘 S개를 만들 때, 클립보드에 몇개가 저장되어 있는지는 모르므로
	// 그 중에서 최솟값을 찾아준다.
	int ans = 987654321;
	for (int i = 0; i <= s; i++) {
		if (cnt[s][i] != -1) {
			ans = ans > cnt[s][i] ? cnt[s][i] : ans;
		}
	}

	cout << ans;
	return 0;
}