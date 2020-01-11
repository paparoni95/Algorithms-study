#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& ans, vector<int>& v, int i, int count) {
	// 종료조건
	// 로또 번호 6개를 다 골랐으면
	if (count == 6) {
		for (int num : ans) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}
	// 불가능한 경우
	// 범위를 벗어난 인덱싱이면 (종료조건을 정답으로 처리했으니, i를 더하는 경우가 다음의 경우이므로
	// i의 범위가 로또 범위를 벗어나지 않는지만 체크해주면 된다.
	if (v.size() == i) return;
	// 다음의 경우
	// 현재 인덱스의 로또 번호를 선택o
	ans.push_back(v[i]);
	solve(ans, v, i + 1, count + 1);
	// 내가 이 로또 번호를 선택하지 않을 때에는 로또 배열에 있으면 안되기 떄문에
	ans.pop_back(); 
	// 현재 인덱스의 로또 번호를 선택x
	solve(ans, v, i + 1, count);
}

int main() {
	int number_size = 0;

	while (true) {
		cin >> number_size;
		if (number_size == 0)
			break;

		vector<int> number(number_size); // 주어지는 로또 번호
		vector<int> ans;                 // 주어지는 로또 번호 중 6개를 뽑은 번호들
		for (int i = 0; i < number_size; i++) {
			cin >> number[i];
		}
		solve(ans, number, 0, 0);
		cout << '\n';
	}
	return 0;
}