#include <iostream>
#include <vector>
using namespace std;

bool check = false;
void dfs(int sum, vector<int>& cnt)
{
	if (sum % 7 == 4)
	{
		check = true;
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		if (cnt[i] == 0) continue;
		cnt[i]--;
		dfs(sum + i, cnt);
		cnt[i]++;
	}
}

// 핵심은 미리 나눠도 전체적인 결과에 지장을 주지 않는다.
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> cnt(1000, 0);
	
	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x % 7 == 0) continue;
		cnt[x % 7]++;
		total++;
	}

	// 이미 만드는 방법이 존재하면 끝
	if (cnt[4] > 0)
	{
		cout << "YES\n";
		return 0;
	}
	// 1~6 숫자가 입력되어 있을 때, 적절하게 배치하면 나머지가 4인 정답을 만들 수 있기 때문
	if (total >= 6)
	{
		cout << "YES\n";
		return 0;
	}

	dfs(0, cnt);
	cout << (check ? "YES\n" : "NO\n");
	return 0;
}
