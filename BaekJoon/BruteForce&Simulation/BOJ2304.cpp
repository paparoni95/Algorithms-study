#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer;
vector<pair<int, int>> pos;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}

	// 좌표 순으로 정렬
	sort(pos.begin(), pos.end());

	// 좌표 순서대로 높이 배치를 다시하여 배열을 만든다.
	int start = pos.front().first;
	int end = pos.back().first;
	vector<int> result(end + 1, 0);
	for (int i = start; i <= end; i++) {
		for (int j = 0; j < pos.size(); j++) {
			if (pos[j].first == i) {
				result[i] = pos[j].second;
				break;
			}
		}
	}

	// 기존의 기둥들을 다 더해주고
	for (int i = start; i < result.size(); i++) {
		answer += result[i];
	}

	// 추가적으로 지어야 하는 면적을 더한다.
	for (int i = start + 1; i < result.size() - 1; i++) {
		int left = 0;
		int right = 0;
		// 왼쪽에서 가장 큰 기둥 탐색
		for (int j = start; j < i; j++) 
			left = max(left, result[j]);
		// 오른쪽에서 가장 큰 기둥 탐색
		for (int j = i + 1; j < result.size(); j++) 
			right = max(right, result[j]);
		if (result[i] < left && result[i] < right) 
			answer += min(left, right) - result[i];
	}

	cout << answer << '\n';
	return 0;
}