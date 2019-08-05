#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	int k;
	//K개의 숫자 중에서 6개만 선택하는 것은
	//골랐으면 1, 총 6개
	//고르지 않았으면 0, 총 k - 6개
	while (true) {
		cin >> k;
		if (k == 0) break;
		vector<int> s(k);    //집합 S
		vector<int> select;  //선택할려는 집합

		//집합 S를 입력받는다.
		for (int i = 0; i < s.size(); ++i) {
			cin >> s[i];
		}

		//골랐으면 1을 select에 추가
		for (int i = 0; i < 6; ++i) {
			select.push_back(1);
		}

		//고르지 않았다면 0을 select에 추가
		for (int i = 0; i < k - 6; ++i) {
			select.push_back(0);
		}

		//순열을 할 때는 사전순으로 정렬하고 시작.
		sort(select.begin(), select.end());

		//정답을 가지고 있는 2차원 배열
		vector<vector<int>> ans;

		//순열을 돌면서 나올 수 있는 모든 로또 번호를 저장한다.
		do {
			vector<int> temp;
			for (int i = 0; i < select.size(); ++i) {
				if (select[i] == 1) {
					temp.push_back(s[i]);
				}
			}
			ans.push_back(temp);
		} while (next_permutation(select.begin(), select.end()));

		//문제에서 사전순으로 출력하라고 하였으므로
		sort(ans.begin(), ans.end());

		//저장된 모든 로또 번호를 출력한다.
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}