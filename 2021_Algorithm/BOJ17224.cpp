#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Note
{
	int sub1;
	int sub2;
	bool check;
};

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, L, K;
	cin >> N >> L >> K;
	vector<Note> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].sub1 >> v[i].sub2;
		v[i].check = false;
	}

	int answer = 0;
	// 어려운 문제부터 스캔
	for (int i = 0; i < N; i++)
	{
		if (!v[i].check && v[i].sub2 <= L && K > 0)
		{
			answer += 140;
			v[i].check = true;
			K--;
		}
	}

	// 쉬운 문제 스캔
	for (int i = 0; i < N; i++)
	{
		if (!v[i].check && v[i].sub1 <= L && K > 0)
		{
			answer += 100;
			v[i].check = true;
			K--;
		}
	}

	cout << answer;
	return 0;
}