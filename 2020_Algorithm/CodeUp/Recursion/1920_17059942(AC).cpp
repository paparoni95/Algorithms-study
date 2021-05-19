#include <iostream>
using namespace std;

void convert(int k)
{
    if(k <= 1)
    {
        cout << k;
        return;
    }
    
    convert(k / 2);
    cout << k % 2;
}

int main()
{
    int n;
    cin >> n;
    convert(n);
    return 0;
}
