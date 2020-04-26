// https://yabmoons.tistory.com/86

// 혼자 풀려고 했지만, 계속 주변을 돌고있는 느낌이 들어서 결국 참고하였다.
// 질문을 했을 때, 정답이 아닌 것들을 제외시키는 부분이 어려웠다...
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef struct
{
	int number;
	int strike;
	int ball;
}Game;

int n;
bool check[1000];
vector<Game> question;

int main()
{
	//freopen("input.txt", "r", stdin);
	memset(check, true, sizeof(check));

	// 나올 수 없는 정답은 미리 지워준다.
	for (int i = 123; i <= 999; i++)
	{
		string str = to_string(i);
		if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]) check[i] = false;
		if (str[0] == '0' || str[1] == '0' || str[2] == '0') check[i] = false;
	}

	// 입력
	cin >> n;
	while (n--)
	{
		int num, s, b;
		cin >> num >> s >> b;
		Game g;
		g.number = num;
		g.strike = s;
		g.ball = b;

		question.push_back(g);
	}

	// 질문들과 비교해서 나올 수 없는 경우들을 지워준다.
	for (int i = 0; i < question.size(); i++)
	{
		int num = question[i].number;
		int strike = question[i].strike;
		int ball = question[i].ball;
		string origin = to_string(num);

		for (int j = 123; j <= 999; j++)
		{
			int temp_strike = 0;
			int temp_ball = 0;
			
			if (check[j] == true)
			{
				string temp = to_string(j);
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						if (a == b && origin[a] == temp[b]) temp_strike++;
						if (a != b && origin[a] == temp[b]) temp_ball++;
					}
				}

				// 정답이라고 생각한 후보가 맞는지 체크, 아닌 것들은 지우기
				if (strike != temp_strike || ball != temp_ball) check[j] = false;
			}
		}
	}

	// 모든 질문들의 검증을 확인한 후에도 살아남은 숫자들은 정답이다.
	int ans = 0;
	for (int i = 123; i <= 999; i++)
	{
		if (check[i] == true) ans++;
	}
	cout << ans << '\n';
	return 0;
}
