#include <iostream>
using namespace std;

int zoo[100001][3];
//zoo[i][j] : i칸에 j번째에 사자를 배치하는 경우의 수
//zoo[i][0] : 사자를 배치하지 않았을 때
//zoo[i][1] : 사자를 왼쪽에 배치
//zoo[i][2] : 사자를 오른쪽에 배치

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	//처음에 배치하는 경우의 수는
	//사자를 배치하지 않거나, 왼쪽에 배치 혹은 오른쪽에 배치하는 경우는 1가지
	zoo[1][0] = zoo[1][1] = zoo[1][2] = 1;

	//이후부터는 계산해서 저장한다.
	for (int i = 2; i <= n; ++i) {
		zoo[i][0] = (zoo[i - 1][0] + zoo[i - 1][1] + zoo[i - 1][2]) % 9901;
		zoo[i][1] = (zoo[i - 1][0] + zoo[i - 1][2]) % 9901;
		zoo[i][2] = (zoo[i - 1][0] + zoo[i - 1][1]) % 9901;
	}

	int ans = (zoo[n][0] + zoo[n][1] + zoo[n][2]) % 9901;
	cout << ans;
	return 0;
}