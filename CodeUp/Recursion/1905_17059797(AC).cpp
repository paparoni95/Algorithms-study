#include <iostream>
using namespace std;

int sum;

// s ~ e 까지의 합
void f(int s, int e)
{
    if(s > e) return;
    sum += s;
    f(s + 1, e);
}

int main()
{
    int n;
    cin>>n;
    f(1, n);
    cout << sum << endl;
    return 0;
}
