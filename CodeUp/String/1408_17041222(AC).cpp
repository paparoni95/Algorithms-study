#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    string password1, password2;
    char ch1,ch2;
    for(int i = 0; i < s.size(); i++)
    {
        ch1 = s[i] + 2;
        ch2 = (s[i] * 7) % 80 + 48;
        password1 += ch1;
        password2 += ch2;
    }
    
    cout<<password1<<endl<<password2<<endl;
    return 0;
}
