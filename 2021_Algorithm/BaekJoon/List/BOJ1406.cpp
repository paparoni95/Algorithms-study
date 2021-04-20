#include <iostream>
#include <list>
#include <string>
using namespace std;

string s;
int M;

// 삽입 삭제가 빈번하게 일어나면서 길이가 10만.
// list의 특징을 잘 알고 있으면 쉽게 해결할 수 있다.
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> M;

	list<char> lt;
	for (int i = 0; i < s.length(); i++) lt.push_back(s[i]);
	auto cursor = lt.end();
	while (M--)
	{
		char ch, x;
		cin >> ch;

		if (ch == 'L')
		{
			if (cursor != lt.begin())
				cursor--;
		}
		else if (ch == 'D')
		{
			if (cursor != lt.end())
				cursor++;
		}
		else if (ch == 'B')
		{
			if (cursor != lt.begin())
			{
				// 삭제 후에 다음 원소를 가리킴.
				cursor = lt.erase(--cursor);
			}
		}
		else if (ch == 'P')
		{
			cin >> x;
			// 삽입은 반복자가 가리키는 원소의 앞쪽.
			lt.insert(cursor, x);
		}
	}


	for (auto iter = lt.begin(); iter != lt.end(); iter++)
		cout << *iter;
	cout << '\n';
	return 0;
}