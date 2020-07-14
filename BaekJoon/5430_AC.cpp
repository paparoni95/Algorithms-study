// https://jaimemin.tistory.com/838

// 배열에서 숫자를 뽑아내는 작업인 split이 미숙해서 틀렸다..
// 추가적으로 시간초과 나는 이유는 배열을 직접 역순으로 만들기보다는
// deque을 이용해서 앞에서 뺄지, 뒤에서 뺄지를 결정해주는 변수를 둬서 이용하면 된다.

// 추가적으로 함정
// R
// 0
// []
// 입력으로 들어오면
// 답은 [] 이다.
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); // 속도 향상
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		string command, number;
		cin >> command >> N >> number;

		deque<int> dq;
		string temp;
		// 숫자 split하기
		for (int i = 0; i < number.size(); i++)
		{
			char ch = number[i];
			if (ch == '[') continue;
			else if (ch >= '0' && ch <= '9') temp += ch;
			else if (ch == ',' || ch == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool isFront = true; // 앞에서 뽑겠다.
		bool ok = true;      // error 색출
		for (int i = 0; i < command.size(); i++)
		{
			char ch = command[i];
			if (ch == 'R')
			{
				isFront = !isFront;
			}
			
			else if(ch == 'D')
			{
				if (dq.empty())
				{
					ok = false;
					cout << "error" << '\n';
					break;
				}
				
				if (isFront)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (ok == false) continue;

		if (isFront)
		{
			cout << "[";
			while (!dq.empty())
			{
				cout << dq.front();
				dq.pop_front();
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
		else
		{
			cout << "[";
			while (!dq.empty())
			{
				cout << dq.back();
				dq.pop_back();
				if (!dq.empty()) cout << ",";
			}
			cout << "]\n";
		}
	}
	return 0;
}