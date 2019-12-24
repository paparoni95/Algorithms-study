#include <iostream>
using namespace std;

int d[301][301]; // d[i][j] : i x j Å©±âÀÇ ÃÊÄÝ¸´À» ÂÉ°³±â À§ÇÑ ÃÖ¼Ò È½¼ö

int main()
{
	int row, col;
	cin >> row >> col;

	d[1][1] = 0;
	for (int i = 2; i <= row; i++)
		d[i][1] = i - 1;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 2; j <= col; j++)
		{
			d[i][j] = d[i][j - 1] + i;
		}
	}

	cout << d[row][col];
		
	return 0;
}