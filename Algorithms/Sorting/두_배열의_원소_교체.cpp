#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, b;

int main() {
	cin >> n >> k;
	// 배열 a의 모든 원소를 입력받기
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	// 배열 b의 모든 원소를 입력받기
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	// 배열 a의 오름차순 정렬 수행
	sort(a.begin(), a.end());
	// 배열 b는 내림차순 정렬 수행
	sort(b.begin(), b.end(), greater<int>());;

	// 첫 번째 인덱스부터 확인하며, 두 배열의 원소를 최대 k번 비교
	for (int i = 0; i < k; i++) {
		// a의 원소가 b의 원소보다 작은 경우
		if (a[i] < b[i]) swap(a[i], b[i]);
		// a의 원소가 b의 원소보다 크거나 같을 때, 탈출
		else break;
	}

	// 배열 a의 모든 원소의 합을 출력
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		result += a[i];
	}

	cout << result << '\n';
	return 0;
}