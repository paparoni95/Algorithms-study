#include <iostream>
using namespace std;

int a[1001];
int n, temp, step;
bool isFinish;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        step++;
        isFinish = true;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                isFinish = false;
                break;
            }
        }

        if (isFinish)
        {
            cout << step << endl;
            break;
        }
    }

    return 0;
}
