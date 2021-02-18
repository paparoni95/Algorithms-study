#include <iostream>
using namespace std;

void f(int a, int b) // 함수 정의
{
    if(a > b) return;// base condition
    
    // 재귀식
    if(a % 2 != 0)
        cout << a << ' ';
    f(a + 1, b);    
}

int main()
{
    int a,b;
    cin>>a>>b;
    f(a,b);
    return 0;
}
