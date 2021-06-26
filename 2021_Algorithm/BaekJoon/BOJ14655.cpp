#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// greedy
// 처음에는 어떻게 최대와 최소로 동전을 뒤집을 수 있을까 생각을 하다가,,
// 결국 못 풀어서 다른 사람이 푼 해답을 확인해보니 허무했다..
// 문제에서 "욱제는 최고의 베팅꾼이기 때문에 
// 항상 게임에서 획득할 수 있는 최고의 점수를 얻는다는 사실은 자명하다."
// 라는 문구가 있기 때문에 결국 1라운드의 절대값과 2라운드의 절대값의 합이 정답이다.
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> r1(n);
	vector<int> r2(n);
	for (int i = 0; i < n; i++) cin >> r1[i];
	for (int i = 0; i < n; i++) cin >> r2[i];

	int ans = 0;
	for (int i = 0; i < n; i++) ans += abs(r1[i]) + abs(r2[i]);
	cout << ans << '\n';
	return 0;
}