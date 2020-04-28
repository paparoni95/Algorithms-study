#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int now = 665, cnt = 0;
	while (now++)
	{
		string s = to_string(now);

		// 현재 숫자에 666이 포함되어 있다면
		if (s.find("666") != -1) cnt++;

		if (cnt == n)
		{
			cout << now << '\n';
			break;
		}
	}
	return 0;
}