#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

long long solution(vector<int>& v)
{
	int size = v.size();
	long long sum = 0; // 주의할 점은 int의 범위를 벗어나므로 더 큰 자료형으로 변경한다.

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			sum += gcd(v[i], v[j]);
		}
	}

	return sum;
}

int main()
{
	int tc, n;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++)
		{
			cin >> v[j];
		}
		long long ans = solution(v);
		cout << ans << '\n';
	}
}