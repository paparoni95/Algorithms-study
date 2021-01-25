#include <iostream>
#include <vector>
#include <string>
using namespace std;

int s, R, C, cnt;
string n;
char board[200][200];
char LCD[23][12];

// 문제 접근법
// 각 숫자에 대한 포인트 지점들을 만들어서 길이가 변화하더라도 변화할 수 있게 함.
// 그 포인트 지점들은 up, mid, bottom, leftUp, leftDown, rightUp, rightDown
// 규칙을 찾아서 1,2,3,4,5,6,7,8,9,0 에 따른 LCD를 만들고
// 그 LCD를 답안 board 배열에 복사함.

void init()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			LCD[i][j] = ' ';
		}
	}
}

void copyLCD(int range)
{
	int start = (s + 3) * range;
	for (int i = 0; i < R; i++)
	{
		for (int j = start; j < start + C; j++)
		{
			board[i][j] = LCD[i][j - start];
		}
	}
}

void makeLCD(int type)
{
	pair<int, int> up = { 0, 1 };        
	pair<int, int> mid = { s + 1, 1 };       
	pair<int, int> bottom = { (s + 1) * 2, 1 }; 

	pair<int, int> leftUp = { 1, 0 }; 
	pair<int, int> leftDown = { s + 2, 0 };

	pair<int, int> rightUp = { 1, s + 1 };
	pair<int, int> rightDown = { s + 2, s + 1 };

	switch (type)
	{
	case 1:
		for (int i = 0; i < s; i++)
		{
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	case 2:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[mid.first][mid.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[leftDown.first + i][leftDown.second] = '|';
			LCD[rightUp.first + i][rightUp.second] = '|';
		}
		break;
	case 3:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[mid.first][mid.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	case 4:
		for (int i = 0; i < s; i++)
		{
			LCD[mid.first][mid.second + i] = '-';
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
			LCD[leftUp.first + i][leftUp.second] = '|';
		}
		break;
	case 5:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[mid.first][mid.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[leftUp.first + i][leftUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	case 6:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[mid.first][mid.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[leftUp.first + i][leftUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
			LCD[leftDown.first + i][leftDown.second] = '|';
		}
		break;
	case 7:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	case 8:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[mid.first][mid.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[leftUp.first + i][leftUp.second] = '|';
			LCD[leftDown.first + i][leftDown.second] = '|';
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	case 9:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[mid.first][mid.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[leftUp.first + i][leftUp.second] = '|';
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	case 0:
		for (int i = 0; i < s; i++)
		{
			LCD[up.first][up.second + i] = '-';
			LCD[bottom.first][bottom.second + i] = '-';
			LCD[leftUp.first + i][leftUp.second] = '|';
			LCD[leftDown.first + i][leftDown.second] = '|';
			LCD[rightUp.first + i][rightUp.second] = '|';
			LCD[rightDown.first + i][rightDown.second] = '|';
		}
		break;
	}
}

void printLCD()
{
	int end = (s + 3) * cnt;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < end; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> n;
	R = 2 * s + 3;
	C = s + 2;

	for (int i = 0; i < 23; i++)
		for (int j = 0; j < 130; j++)
			board[i][j] = ' ';


	for (int i = 0; i < n.length(); i++)
	{
		init();
		makeLCD(n[i] - '0');
		copyLCD(cnt++);
	}

	printLCD();

	return 0;
}