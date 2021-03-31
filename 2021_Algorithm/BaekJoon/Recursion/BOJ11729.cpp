#include <iostream>
using namespace std;

// n개의 원판을 from에서 to로 옮기는 방법
void hanoi(int from, int to, int n)
{
	if (n == 1)
	{
		cout << from << ' ' << to << '\n';
		return;
	}

	hanoi(from, 6 - from - to, n - 1);
	cout << from << ' ' << to << '\n';
	hanoi(6 - from - to, to, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';
	hanoi(1, 3, n);
	return 0;
}