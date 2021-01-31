#include <iostream>
using namespace std;

char ML, MR, TL, TR;
bool mWin, tWin;

void mGame(char ch)
{
	switch (ch)
	{
	case 'S':
		if (TL == 'P' && TR == 'P') mWin = true;
		break;
	case 'R':
		if (TL == 'S' && TR == 'S') mWin = true;
		break;
	case 'P':
		if (TL == 'R' && TR == 'R') mWin = true;
		break;
	}
}

void tGame(char ch)
{
	switch (ch)
	{
	case 'S':
		if (ML == 'P' && MR == 'P') tWin = true;
		break;
	case 'R':
		if (ML == 'S' && MR == 'S') tWin = true;
		break;
	case 'P':
		if (ML == 'R' && MR == 'R') tWin = true;
		break;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> ML >> MR >> TL >> TR;

	// 민성 게임
	mGame(ML);
	mGame(MR);
	// 태경 게임
	tGame(TL);
	tGame(TR);

	if (mWin && tWin) cout << '?';
	else if (mWin) cout << "MS";
	else if (tWin)cout << "TK";
	else cout << '?';
	return 0;
}
