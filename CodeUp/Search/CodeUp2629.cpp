#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Info
{
	double len;
	int people;
};

int n, p;
vector<Info> v;

double getDistance(int x, int y)
{
	return sqrt(x * x + y * y);
}

bool compare(Info& a, Info& b)
{
	return a.len < b.len;
}

void input()
{
	cin >> n >> p;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ getDistance(a, b), c });
	}
}

void solve()
{
	input();
	sort(v.begin(), v.end(), compare); // 거리 순으로 정렬한다.

	double ans = -1;
	// 최소 거리부터 확장해나가면서 인구수가 백만명이 되는지 체크한다.
	for (int i = 0; i < n; i++)
	{
		p += v[i].people;
		if (p >= 1000000)
		{
			ans = v[i].len;
			break;
		}
	}

	if (ans == -1) cout << -1 << endl;
	else
	{
		cout.setf(ios::fixed);
		cout.precision(3);
		cout << ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}