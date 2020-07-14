// https://yabmoons.tistory.com/303
// 어떻게 접근할 지가 중요한 것 같다. 확실히 이 문제는 어려웠다..
// 항상 코드는 이해를 하고나서 작성하는 것이 가장 좋다. 그렇지 않으면 한 줄도 못쓰기 때문
// BackTracking + BruteForce
#include <iostream>

#define MAX 10
using namespace std;

struct STATE
{
	int Prev;              // 현재 칸
	int Next;              // 이동하려는 칸
	int Start_Circle;      // 시작한 파랑원의 번호 (1,2,3 중 하나)
	bool Select_Circle;    // 이번 움직임으로 파랑색 원의 번호가 결정되었는지에 대한 여부판단
	bool Finish;           // 이번 움직임으로 윷이 도착점에 도달하였는지에 대한 여부 판단
};

struct YUT
{
	int Blue_Circle;       // 윷이 한번이라도 시작한 파랑색 원의 번호
	int Pos;               // 윷의 정보
	int Score;             // 윷의 점수
	bool Finish;           // 윷이 도착점에 도달했는지에 대한 여부
};

int answer;
int Command[MAX];
int MoveNum[4];            // 각 경로 별, 움직여야 하는 최대 칸수
int MAP_Score[4][30];      // 점수 판
bool Visit[4][30];         // 이미 다른 윷이 있는지 없는지 판단하기 위한 배열
bool Special_Point[4][30]; // 특별한 점 (모든 경로가 겹치는 칸들을 의미)

YUT Yut[4];

void Setting()
{
	/* 기본 세팅 작업 */
	/*
		1. 각 경로 별 움직여야 하는 최대 칸수를 저장하자.
		2. 특별한 점들을 체크하자.
		3. 점수 판 만들자.
	*/
	MoveNum[0] = 21;
	MoveNum[1] = 13;
	MoveNum[2] = 17;
	MoveNum[3] = 23;

	Special_Point[1][9] = Special_Point[1][10] = Special_Point[1][11] = Special_Point[1][12] = true;
	Special_Point[2][13] = Special_Point[2][14] = Special_Point[2][15] = Special_Point[2][16] = true;
	Special_Point[3][19] = Special_Point[3][20] = Special_Point[3][21] = Special_Point[3][22] = true;
	Special_Point[0][1] = Special_Point[0][2] = Special_Point[0][3] = Special_Point[0][4] = Special_Point[0][5] = Special_Point[0][20] = true;

	for (int i = 1; i <= 20; i++) MAP_Score[0][i] = 2 * i;
	MAP_Score[1][6] = 13; MAP_Score[1][7] = 16; MAP_Score[1][8] = 19; MAP_Score[1][9] = 25;
	MAP_Score[1][10] = 30; MAP_Score[1][11] = 35; MAP_Score[1][12] = 40;
	MAP_Score[2][11] = 22; MAP_Score[2][12] = 24; MAP_Score[2][13] = 25; MAP_Score[2][14] = 30;
	MAP_Score[2][15] = 35; MAP_Score[2][16] = 40;
	MAP_Score[3][16] = 28; MAP_Score[3][17] = 27; MAP_Score[3][18] = 26; MAP_Score[3][19] = 25;
	MAP_Score[3][20] = 30; MAP_Score[3][21] = 35; MAP_Score[3][22] = 40;

	for (int i = 1; i <= 5; i++) MAP_Score[1][i] = MAP_Score[0][i];
	for (int i = 1; i <= 10; i++) MAP_Score[2][i] = MAP_Score[0][i];
	for (int i = 1; i <= 15; i++) MAP_Score[3][i] = MAP_Score[0][i];
}

void Input()
{
	for (int i = 0; i < 10; i++) cin >> Command[i];
}

STATE GetState(int idx, int c_idx)
{
	/* 현재의 움직임으로 변하는 윷의 상태를 받아오는 함수 */


	int Prev = Yut[idx].Pos;                   // 윷이 현재 있는 칸
	int Next = Yut[idx].Pos + Command[c_idx];  // 윷이 이동하려는 칸
	int Start_Circle = Yut[idx].Blue_Circle;   // 기존에 시작한 파랑색 원의 번호
	bool Select_Circle = false;                // 이번 턴의 움직임으로 인해 파랑색 원이 결정되었는지에 대한 여부
	bool Finish = false;                       // 이번 턴의 움직임으로 인해 도착점에 도달했는지에 대한 여부

	if (Start_Circle == 0)        //  아직 시작한 파랑색 원이 없는 경우에만
	{
		if (Prev == 5 || Prev == 10 || Prev == 15)
		{
			Select_Circle = true; // 이번 턴의 움직임으로 파랑색 원이 결정됨.
			Start_Circle = Prev / 5;
		}
	}

	if (Next >= MoveNum[Start_Circle]) Finish = true;    // 도착점에 도달했다면 체크

	return { Prev, Next, Start_Circle, Select_Circle, Finish };
}

bool Check_Special_Point(int Circle, int Pos)
{
	/* 특별한 점에 다른 윷이 존재하는지 판단하는 함수 */

	if (Circle == 0)
	{
		/* 현재 이동하려는 윷이 파랑색 원에서 시작한 적이 없는 경우 */
		/* '40'점이 설정되어있는 칸에 기존에 윷이 있는지 판단해 주면 된다. */
		/* '40'점이 있는 칸은, 빨강색, 파란색, 초록색, 주황색 모두 겹치는 경로이기 때문이다. */

		if (Pos == 20) // 40번 칸에 도달했는데
		{
			if (Visit[1][12] == true || Visit[2][16] == true || Visit[3][22] == true) return false; // 하나라도 윷이 있다면 실패
		}
		else
		{
			if (Visit[0][Pos] == true) return false;
		}
	}
	else if (Circle == 1)
	{
		/* 현재 윷이, 1번 파랑 원에서 시작해서 움직이고 있는 경우 */
		/* 파랑색 / 주황색 경로가 겹치는 '25', '30', '35', '40'을 체크해줘야 한다.*/

		if (Visit[2][Pos + 4] == true || Visit[3][Pos + 10] == true) return false;

		if (Pos == 12) // 40번 칸에 도달했는데
		{
			if (Visit[0][20] == true) return false;
		}
	}
	else if (Circle == 2)
	{
		if (Visit[1][Pos - 4] == true || Visit[3][Pos + 6] == true) return false;
		if (Pos == 16)
		{
			if (Visit[0][20] == true) return false;
		}
	}
	else if (Circle == 3)
	{
		if (Visit[1][Pos - 10] == true || Visit[2][Pos - 6] == true) return false;
		if(Pos == 22)
		{
			if (Visit[0][20] == true) return false;
	    }
	}
	return true;
}

bool Check_Visit(STATE S, int idx)
{
	/* 현재 윷이 움직일 수 있는지를 판단해주는 함수 */
	/* 판단해 줘야 할 것
		1. 움직이려는 좌표가 특별한 점인지?
			- 특별한 점이라면 다른 경로를 통해서 해당 좌표에 있는 놈들도 check해주자.
		2. 움직이려는 좌표에 다른 윷이 존재하는지?
	*/
	if (Special_Point[S.Start_Circle][S.Next] == true)
	{
		if (Check_Special_Point(S.Start_Circle, S.Next) == false) return false;
	}

	if (Visit[S.Start_Circle][S.Next] == true) return false;
	return true;
}

void MakeState(STATE S, int idx, bool T)
{
	/* 방문 체크를 하고, 실제로 윷을 옮기는 함수 */
	/* T = true 일 경우, 실행 */
	/* T = false 일 경우, 실행 취소 (백트래킹) */

	if (T == true)
	{
		if (S.Finish == true)
		{
			/* 현재 턴의 움직임으로 윷이 도착점에 도달했다면? */
			Visit[S.Start_Circle][S.Prev] = false;  // 기존 좌표 방문 체크 해제
			Yut[idx].Pos = S.Next;                  // 현재 윷의 좌표 갱신
			Yut[idx].Finish = true;                 // 끝났음을 표시
		}
		else
		{
			/* 현재 턴의 움직임으로 윷이 도착점에 도달하지는 못한 경우는 */
			if (S.Select_Circle == true)
			{
				/* 현재 턴의 움직임으로 파랑원의 번호가 결정 되었다면? */

				Yut[idx].Blue_Circle = S.Start_Circle;  // 윷의 파랑 원의 번호를 결정
				Visit[0][S.Prev] = false;               // 기존 좌표 방문 체크 해제

				/* 이번 턴에 파랑원의 번호가 결정되었다 = 기존에는 파랑원이 결정되지 않은 상태였다.
				   즉, 기존의 좌표 체크 해제는 파랑원이 결정되지 않은 Visit[0][S.Prve]로 해준다.
				*/
			}
			else
			{
				/* 현재 턴의 움직임으로 파랑원의 번호가 결정되지 않았다.
				   혹은, 이미 정해져있을 수도, 아니면 아직 정해지지 않은 것일수도 있다. */

				Visit[Yut[idx].Blue_Circle][S.Prev] = false; // 기존 좌표 방문 체크 해제
			}
			Visit[Yut[idx].Blue_Circle][S.Next] = true; // 방문 체크
			Yut[idx].Pos = S.Next;                      // 좌표 갱신
			Yut[idx].Score = Yut[idx].Score + MAP_Score[Yut[idx].Blue_Circle][S.Next]; // 점수 갱신
		}
	}
	else
	{
		/* 실행 취소하는 과정 */
		if (S.Finish == true)
		{
			/* 이번 턴에 윷이 도착점에 도달했다면? */
			Visit[S.Start_Circle][S.Prev] = true;  // 기존의 좌표 방문 체크
			Yut[idx].Pos = S.Prev;                 // 좌표값 되돌리기
			Yut[idx].Finish = false;               // 끝남표시 해제
		}
		else
		{
			if (S.Select_Circle == true)
			{
				/* 이번 턴으로 인해서 파랑색 원이 결정 되었는데, 이를 실행취소한다. */
				Visit[0][S.Prev] = true;
				Visit[Yut[idx].Blue_Circle][S.Next] = false;
				Yut[idx].Pos = S.Prev;
				Yut[idx].Score = Yut[idx].Score - MAP_Score[Yut[idx].Blue_Circle][S.Next];
				Yut[idx].Blue_Circle = 0; // 선택한 파랑원의 번호 다시 0으로 갱신.
			}
			else
			{
				Visit[Yut[idx].Blue_Circle][S.Prev] = true;
				Visit[Yut[idx].Blue_Circle][S.Next] = false;
				Yut[idx].Pos = S.Prev;
				Yut[idx].Score = Yut[idx].Score - MAP_Score[Yut[idx].Blue_Circle][S.Next];
			}
		}
	}

}

void DFS(int cnt)
{
	if (cnt == 10)
	{
		int temp = 0;
		for (int i = 0; i < 4; i++) temp = temp + Yut[i].Score;

		if (answer < temp) answer = temp;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (Yut[i].Finish == true) continue;            // 해당 윷이 도착점에 도달했는지?
		STATE State = GetState(i, cnt);                 // 아니라면, 현재 상태를 가져오고,
		if (Check_Visit(State, i) == false) continue;   // 그 상태에서 움직일 수 있는지 체크

		MakeState(State, i, true);                      // 가능하다면 움직이자.
		DFS(cnt + 1);                                   // 다음 말 선택
		MakeState(State, i, false);                     // 되돌리자.
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	Setting();
	Input();
	DFS(0);
	cout << answer << '\n';
	return 0;
}