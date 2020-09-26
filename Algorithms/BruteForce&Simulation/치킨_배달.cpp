#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

// 치킨 거리의 합을 구하는 함수
int GetSum(vector<pair<int, int>>& candidates) {
	int result = 0;
	// 모든 집에 대하여
	for (int i = 0; i < house.size(); i++) {
		int hx = house[i].first;
		int hy = house[i].second;
		// 가장 가까운 치킨 집을 찾기
		int temp = 1e9;
		for (int j = 0; j < candidates.size(); j++) {
			int cx = candidates[j].first;
			int cy = candidates[j].second;
			temp = min(temp, abs(hx - cx) + abs(hy - cy));
		}
		// 가장 가까운 치킨 집까지의 거리를 더하기
		result += temp;
	}
	// 치킨 거리의 합 반환
	return result;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back({ i,j });
			else if (arr[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	// 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
	vector<int> order(chicken.size());
	fill(order.end() - m, order.end(), 1);

	// 치킨 거리의 합의 최소를 찾아 출력
	int result = 1e9;

	do {
		vector<pair<int, int>> now;
		for (int i = 0; i < chicken.size(); i++) {
			if (order[i]) {
				int cx = chicken[i].first;
				int cy = chicken[i].second;
				now.push_back({ cx,cy });
			}
		}
		result = min(result, GetSum(now));
	} while (next_permutation(order.begin(), order.end()));
	cout << result << '\n';
	return 0;
}