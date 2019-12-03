#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;

bool IsPossible(string s)
{
	int vowels = 0;     // 모음
	int consonants = 0; // 자음

	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			vowels++;
		else
			consonants++;
	}

	// 최소 한 개의 모음과 최소 두 개의 자음으로 구성
	if (vowels >= 1 && consonants >= 2)
		return true;
	else
		return false;
}

void makePassword(vector<char>& v, int index, string s, int goal)
{
	// 정답인 경우
	if (s.size() == goal)
	{
		if (IsPossible(s))
		{
			for (auto x : s)
			{
				cout << x;
			}
			cout << '\n';
			return;
		}
	}

	// 불가능한 경우
	if (index >= v.size())
		return;

	// 다음 경우
	makePassword(v, index + 1, s + v[index], goal); // index 알파벳을 포함
	makePassword(v, index + 1, s, goal);            // index 알파벳을 불포함
}


int main()
{
	cin >> L >> C;
	vector<char> v(C);
	for (int i = 0; i < C; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	makePassword(v, 0, "", L);
	return 0;
}