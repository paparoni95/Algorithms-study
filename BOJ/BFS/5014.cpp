#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000001
using namespace std;

int F, S, G, U, D;
vector<int> mv;
int visit[MAX];
int path[MAX];
int bfs(int start)
{
	queue<int> q;
	visit[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cx = q.front();
		q.pop();
		if (cx == G) return path[G];
		for (int k = 0; k < 2; k++) {
			int nx = cx + mv[k];
			/* 범위 안에 있고, 해당 층에 방문하지 않았다면*/
			if ((1 <= nx && nx <= F) && visit[nx] == 0) {
				q.push(nx); visit[nx] = 1;
				path[nx] = path[cx] + 1;
			}
		}
	}
	/* 실패 */
	return -1;
}
int main()
{
	cin >> F >> S >> G >> U >> D;
	mv.push_back(U); //up
	mv.push_back(-D);//down
	int result = bfs(S);
	if (result == -1) {
		cout << "use the stairs";
		return 0;
	}
	cout << result;
	return 0;
}