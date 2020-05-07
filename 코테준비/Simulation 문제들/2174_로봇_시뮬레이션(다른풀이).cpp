// https://2youngjae.tistory.com/124
// 반복적인 부분을 함수로 취해서 간소화 작업
#include <iostream>
#include <vector>

#define E 1
#define S 2
#define W 3
#define N 4
using namespace std;

struct Node
{
	int x, y, dir;
};

int A, B, n, m;
int map[102][102];
int dx[] = { 0,0,-1,0,1 };
int dy[] = { 0,1,0,-1,0 };

// 1동 2남 3서 4북
int turn(int dir, int flag)
{
	if (flag == 1) // left
		return (dir == 1) ? 4 : dir - 1;
	else
		return (dir == 4) ? 1 : dir + 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d %d", &A, &B, &n, &m);

	// 로봇 초기 위치, 방향 저장
	vector<Node> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		char c;
		scanf("%d %d %c", &v[i].x, &v[i].y, &c);
		if (c == 'W') v[i].dir = W;
		else if (c == 'N') v[i].dir = N;
		else if (c == 'E') v[i].dir = E;
		else v[i].dir = S;
		map[v[i].x][v[i].y] = i;
	}

	// 명령 수행
	while (m--)
	{
		int x, y;
		char c;
		scanf("%d %c %d", &x, &c, &y); // [로봇의 번호, 명령어, 반복횟수]
		if (c == 'F')
		{
			for (int i = 0; i < y; i++)
			{
				int ax = v[x].x + dx[v[x].dir];
				int ay = v[x].y + dy[v[x].dir];

				// 경계 체크
				if (ax < 1 || ay < 1 || ax > A || ay > B)
				{
					printf("Robot %d crashes into the wall\n", x);
					return 0;
				}
				else if (map[ax][ay] != 0)
				{
					printf("Robot %d crashes into robot %d\n", x, map[ax][ay]);
					return 0;
				}

				// 타당하면 이동
				map[v[x].x][v[x].y] = 0;
				v[x].x = ax;
				v[x].y = ay;
				map[ax][ax] = x;
			}
		}
		else
		{
			if (y % 4 == 0) continue; // 한 방향으로 4번 돌면 제자리이므로
			y %= 4;
			while (y--)
			{
				if (c == 'L') v[x].dir = turn(v[x].dir, 1);
				else v[x].dir = turn(v[x].dir, 0);
			}
		}
	}
	printf("OK\n");
	return 0;
}