#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int first = v[N - 1]; // 가장 큰 수
	int second = v[N - 2];// 두 번째로 큰 수

	// 가장 큰 수가 더해지는 횟수 계산
	int cnt = (M / (K + 1)) * K;
	cnt += M % (K + 1);

	int result = 0;
	result += cnt * first; // 가장 큰 수 더하기
	result += (M - cnt) * second; // 두 번째로 큰 수 더하기
	
	cout << result << '\n';
	return 0;
}