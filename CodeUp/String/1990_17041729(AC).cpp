#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    //21 21
    //3 6 9 12 15 ... 30 33 ... 99 102 105 108 111 114
    //각 수의 합들이 3의 배수이면 3의 배수이다.
    int sum = 0;
    for(char ch : s)
    {
        sum += (ch - '0');
    }
    
    if(sum % 3 == 0)
        cout<<1<<endl;
    else
        cout<<0<<endl;
        
    return 0;
}
