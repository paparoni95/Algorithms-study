#include <iostream>
#include <string>
using namespace std;

int n;

void solve()
{
	cin >> n;
	string s = to_string(n);

	string left = s.substr(0, s.size() / 2);
	string right = s.substr(s.size() / 2);

	int leftSum = 0;
	for (int i = 0; i < left.size(); i++)
	{
		leftSum += (left[i] - '0');
	}

	int rightSum = 0;
	for (int i = 0; i < right.size(); i++)
	{
		rightSum += right[i] - '0';
	}

	if (leftSum == rightSum) cout << "LUCKY\n";
	else cout << "READY\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}