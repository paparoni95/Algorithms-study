#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool vis[101][101];

int bfs(vector<vector<int> >& maps) {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    vis[0][0] = true;
    maps[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maps[nx][ny] && vis[nx][ny] == false) {
                vis[nx][ny] = true;
                maps[nx][ny] = maps[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }

    if (vis[n - 1][m - 1]) return maps[n - 1][m - 1];
    else return -1;
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    return bfs(maps);
}