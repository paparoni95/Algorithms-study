#include <iostream>
using namespace std;

int main()
{
    double d; cin>>d;
    cout.setf(ios::fixed);
    cout.precision(6); // 소숫점 아래를 6자리로 고정
    cout<<d<<endl;
}
