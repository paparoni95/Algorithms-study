#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    cout.setf(ios::fixed);
    cout.precision(4);
    cout << b / (double)a * -1 << endl;
    return 0;
}