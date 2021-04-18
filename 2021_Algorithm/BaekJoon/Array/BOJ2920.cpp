#include <iostream>
using namespace std;

int main()
{
	int arr[8];
	for (int i = 0; i < 8; i++) cin >> arr[i];

	bool ok1 = true; // ascending
	bool ok2 = true; // descending
	for (int i = 1; i < 8; i++)
	{
		if (arr[i - 1] < arr[i]) ok2 = false;
		if (arr[i - 1] > arr[i]) ok1 = false;
	}

	if (ok1)
		cout << "ascending\n";
	else if (ok2)
		cout << "descending\n";
	else
		cout << "mixed\n";
	return 0;
}