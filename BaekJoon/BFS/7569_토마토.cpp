#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int a[101][101][101];         // 토마토 상자
bool visited[101][101][101];  // 방문 배열
int r, c, h;                  // 행, 열, 높이

typedef struct pos
{
	int z;
	int x;
	int y;
}Pos;

/* 확인하는 용도 */
void show()
{
	cout << '\n';
	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < r; j++) 
		{
			for (int k = 0; k < c; k++)
				cout << a[i][j][k] << ' ';
			cout << '\n';
		}
	}
}


/* BFS 탐색 */
void bfs(queue<Pos> &q)
{
	while (!q.empty())
	{
		int z = q.front().z;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			// 경계 체크
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && nz >= 0 && nz < h)
			{
				// 방문하지 않았으면서 동시에 그 구역이 익지 않은 토마토라면
				if (visited[nz][nx][ny] == false && a[nz][nx][ny] == 0)
				{
					visited[nz][nx][ny] = true;
					a[nz][nx][ny] = a[z][x][y] + 1;
					q.push({ nz,nx,ny });
				}
			}
		}
	}
}

int check()
{
	/* 토마토가 아예 익지 않은 곳이 있다면 */
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				if (a[i][j][k] == 0) return -1;

	/* 아니라면 마지막 토마토가 익은 시점의 날짜 계산 */
	int day = 1;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
				if (day < a[i][j][k])
					day = a[i][j][k];
	
	if (day == 1) // 토마토가 처음부터 모두 익어있다는 뜻
		return 0;
	else
		return day - 1;
}


int main()
{
	queue<Pos> q;

	/* 입력 */
	cin >> c >> r >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < c; k++)
			{
				cin >> a[i][j][k];
				if (a[i][j][k] == 1) 
				{
					visited[i][j][k] = true;
					q.push({ i,j,k }); // 토마토의 위치 저장
				}
					
			}
	/* 탐색 */
	bfs(q);
	int ret = check();

	/* 출력 */
	cout << ret;
	return 0;
}