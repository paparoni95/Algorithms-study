#include <iostream>

#define MAX 105
#define INF 987654321

using namespace std;

int d[MAX][MAX];
int n;

void floydWarshall()
{
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			if (d[i][j] == 0) d[i][j] = INF;
		}
	}

	floydWarshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}