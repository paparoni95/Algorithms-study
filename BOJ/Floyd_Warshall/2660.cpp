#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 52
#define INF 210000000;

using namespace std;

int d[MAX][MAX];
int ans[MAX];
int n;

void setInf() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			d[i][j] = INF;
		}
	}
}

void floydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}

int main()
{
	cin >> n;
	setInf();
	while (1) {
		int u, v;
		cin >> u >> v;

		if (u == -1 && v == -1) break;

		d[u][v] = d[v][u] = 1; //양방향
	}

	floydWarshall();

	int mx = 0, point = INF;
	for (int i = 1; i <= n; i++) {
		mx = 0;
		for (int j = 1; j <= n; j++) {
			if (mx < d[i][j]) mx = d[i][j];
		}
		ans[i] = mx;                //해당 정점의 가장 큰 점수로 저장
		point = min(point, ans[i]); //가장 작은 점수 갱신
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == point) //회장 후보의 수
			cnt++;
	}
	cout << point << ' ' << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == point) {
			cout << i << ' '; //회장 후보의 정점 출력
		}
	}

	return 0;
}