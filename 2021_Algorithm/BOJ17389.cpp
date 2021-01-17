// 구현 문제
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<char> v(N);
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		v[i] = str[i];

	int answer = 0; // 100,000,000
	int bonus = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] == 'X')
		{
			bonus = 0;
		}
		else 
		{
			answer += (i + 1) + (bonus++);
		}
	}

	cout << answer << '\n';
	return 0;
}
