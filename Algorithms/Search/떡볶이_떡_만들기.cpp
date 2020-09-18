#include <bits/stdc++.h>
using namespace std;

// 파라메트릭 서치(Parametric Search)기법

// 떡의 개수, 요청한 떡의 길이
int n, m;
// 각 떡의 개별 높이 정보
vector<int> arr;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	// 이진 탐색을 위한 시작점과 끝점 설정
	int start = 0;
	int end = 1e9; // 10억을 뜻함, 보통 2e9는 int 범위내에서 무한대 값을 나타내기 위해 사용하는 경우가 많다고 함.
	// 이진 탐색 수행 (반복문)
	int result = 0;
	while (start <= end) {	
		long long total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			// 잘랐을 때의 떡의 양 계산
			if (arr[i] > mid) total += arr[i] - mid;
		}
		if (total < m) { // 떡의 양이 부족한 경우 더 많이 자르기(왼쪽 부분 탐색)
			end = mid - 1;
		}
		else { // 떡의 양이 충분한 경우 덜 자르기(오른쪽 부분 탐색)
			result = mid; // 최대한 덜 잘랐을 때가 정답이므로, 여기에서 result에 기록
			start = mid + 1;
		}
	}
	
	cout << result << '\n';
	return 0;
}