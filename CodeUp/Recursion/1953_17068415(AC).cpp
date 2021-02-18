#include <iostream>
#include <string>
using namespace std;

string star;

void f(int k, int n)
{
    if(k > n) return;
    
    star += "*";
    cout << star << '\n';
    f(k + 1, n);
}

int main()
{
    int n;
    cin >> n;
    
    f(1, n);
    return 0;
}
