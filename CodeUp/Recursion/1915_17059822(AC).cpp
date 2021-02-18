#include <iostream>
using namespace std;

int fibo(int k)
{
    if(k == 1 || k == 2) return 1;
    return fibo(k - 1) + fibo(k - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
