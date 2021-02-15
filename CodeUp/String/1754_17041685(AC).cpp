#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    
    // 문자열 길이가 적은 것이 더 작은 값
    if(a.size() > b.size())
    {
        cout<<b<<' '<<a<<endl;
    }
    else if(a.size() < b.size())
    {
        cout<<a<<' '<<b<<endl;
    }
    // 문자열의 길이가 같다면
    else
    {
        if(a > b) cout<<b<<' '<<a<<endl;
        else cout<<a<<' '<<b<<endl;
    }
        
    return 0;
}
