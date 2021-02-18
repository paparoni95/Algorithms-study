#include <iostream>
using namespace std;

void f(int k)
{
    if(k <= 1)
    {
        cout << k << '\n';
        return;
    }
    
    cout << k << '\n';
    
    if(k % 2 != 0) 
        f(k * 3 + 1);
    else 
        f(k / 2);
}

int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}
