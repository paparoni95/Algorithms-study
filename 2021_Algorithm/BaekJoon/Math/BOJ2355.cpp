#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    long long total_b = (b + 1) * b / 2;
    long long total_a = (a + 1) * a / 2;
    if (a < b)
    {
        cout << total_b - total_a + a << '\n';
    }
    else
    {
        cout << total_a - total_b + b << '\n';
    }
    
    return 0;
}