#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3];
//house[n][i] : n층 i번째 집을 칠할 때 드는 최소 비용

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> house[i][j];
		}
	}
	//1층부터 시작하기 위해서 임의로 0층을 만든다.
	house[0][0] = house[0][1] = house[0][2] = 0;

	//1층부터 그 위층에 이웃하지 않은 2개의 집에서 가장 작은 집을 더해간다.
	for (int i = 1; i <= n; ++i) {
		house[i][0] += min(house[i - 1][1], house[i - 1][2]);
		house[i][1] += min(house[i - 1][0], house[i - 1][2]);
		house[i][2] += min(house[i - 1][0], house[i - 1][1]);
	}
	
	int ans = min(house[n][0], min(house[n][1], house[n][2]));
	cout << ans;
	return 0;
}