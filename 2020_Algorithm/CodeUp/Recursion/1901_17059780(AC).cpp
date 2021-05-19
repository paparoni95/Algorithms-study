#include <iostream>
using namespace std;

void print(int s, int e)
{
    if(s > e) return;
    cout << s << '\n';
    print(s + 1, e);
}

int main()
{
    int n;
    cin>>n;
    print(1, n);
    return 0;
}
