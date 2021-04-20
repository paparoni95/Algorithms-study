#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

deque<char> dq_front;
deque<char> dq_back;
string a, t;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> t;

	int s = 0, e = t.length() - 1;

	// 전수조사가 30만 * 30만 = 900만
	while (s <= e)
	{
		while (s <= e) // 앞에서부터 검열 시작
		{
			bool ok = false;
			dq_front.push_back(t[s++]);
			if (dq_front.size() >= a.length())
			{
				ok = true;
				for (int i = 0; i < a.length(); i++)
				{
					// a 문자와 비교해서 검열한다. 비교는 최대 25자
					if (a[i] != dq_front[dq_front.size() - a.length() + i])
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				for (int i = 0; i < a.length(); i++)
					dq_front.pop_back();
				break;
			}
		}

		while (s <= e)
		{
			bool ok = false;
			dq_back.push_front(t[e--]);
			if (dq_back.size() >= a.length())
			{
				ok = true;
				for (int i = 0; i < a.length(); i++)
				{
					if (a[i] != dq_back[i])
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				for (int i = 0; i < a.length(); i++)
					dq_back.pop_front();
				break;
			}
		}
	}

	// 두 개의 덱을 합칠 때에도 새로운 A라는 문자열이 생길 수 있으므로 이 역시 제거해준다.
	string ret;
	for (int i = 0; i < dq_front.size(); i++)
		ret.push_back(dq_front[i]);
	for (int i = 0; i < dq_back.size(); i++)
		ret.push_back(dq_back[i]);

	// 앞서 전수조사가 900만이므로 추려져서 나온다면 이 길이는 3만 아래일 것이다.
	// 따라서 그 안에 index 를 모두 찾아서 지워주면 끝
	while (ret.find(a) < 30000)
		ret.erase(ret.find(a), a.length());

	cout << ret << '\n';
	return 0;
}