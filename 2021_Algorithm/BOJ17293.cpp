#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;

void print(int n)
{
	if (n <= 0)
	{
		cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
		if(N == 1)
			cout << "Go to the store and buy some more, " << N << " bottle of beer on the wall.\n";
		else
			cout << "Go to the store and buy some more, " << N << " bottles of beer on the wall.\n";
		return;
	}

	if (n == 2)
	{
		cout << "2 bottles of beer on the wall, 2 bottles of beer.\n";
		cout << "Take one down and pass it around, 1 bottle of beer on the wall.\n\n";
	}
	else if (n == 1)
	{
		cout << "1 bottle of beer on the wall, 1 bottle of beer.\n";
		cout << "Take one down and pass it around, no more bottles of beer on the wall.\n\n";
	}
	else
	{
		cout << n << " bottles of beer on the wall, " << n << " bottles of beer.\n";
		cout << "Take one down and pass it around, " << n - 1 << " bottles of beer on the wall.\n\n";
	}

	print(n - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	print(N);
	return 0;
}