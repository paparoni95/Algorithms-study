#include <iostream>
using namespace std;

void f(int k)
{
    if(k <= 1)
    {
        cout << k << '\n';
        return;
    }
    
    if(k % 2 != 0)
        f(k * 3 + 1);
    else
        f(k / 2);
        
    cout << k << '\n';    
}

int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}
