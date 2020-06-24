#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;

bool IsRightPassword(const string& password)
{
	int volwels = 0, consonants = 0;

	for (int i = 0; i < password.size(); i++)
	{
		char ch = password[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') volwels++;
		else consonants++;
	}

	if (volwels >= 1 && consonants >= 2) return true;
	else return false;
}

void Solution(vector<char>& alpha, string password, int index, int cnt)
{
	if (cnt == L)
	{
		if (IsRightPassword(password))
		{
			for (char ch : password)
			{
				cout << ch;
			}
			cout << '\n';
		}
		return;
	}

	if (index >= alpha.size()) return;

	// 다음의 경우
	Solution(alpha, password + alpha[index], index + 1, cnt + 1);
	Solution(alpha, password, index + 1, cnt);
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	cin >> L >> C;
	
	vector<char> alphabet(C);
	for (int i = 0; i < C; i++) cin >> alphabet[i];

	sort(alphabet.begin(), alphabet.end());
	Solution(alphabet, "", 0, 0);

	return 0;
}