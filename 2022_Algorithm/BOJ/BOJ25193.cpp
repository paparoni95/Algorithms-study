#include <iostream>
#include <string>
using namespace std;

// 약간의 센스가 필요한 문제.
// 치킨의 배열을 조정할 수 있고, 어떻게 하면 가장 최대값을 줄일 수 있을까? 하는 문제
// 치킨을 따로 Chicken 카운팅
// 치킨이 아닌 음식은 food 카운팅
// food + 1 하는 이유 :
// CCCCA => CCACC
// 치킨 4개, food 1개
// food를 가운데에 두면 치킨이 둘로 쪼개지는데 이 때 4 / 1 이 아니고 4 / 2 여야하기 때문이다.
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int chicken = 0;
	int food = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'C') chicken++;
		else food++;
	}

	if (chicken % (food + 1) != 0)
	{
		cout << (chicken / (food + 1)) + 1 << endl;
	}
	else
	{
		cout << (chicken / (food + 1)) << endl;
	}

	return 0;
}
