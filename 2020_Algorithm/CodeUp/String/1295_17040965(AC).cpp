#include <iostream>
#include <string>
#include <cctype> // toupper, tolower
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++)
    {
        // 대문자면 소문자로
        if(isupper(s[i])) s[i] = tolower(s[i]);
        // 소문자면 대문자로
        else if(islower(s[i])) s[i] = toupper(s[i]);
    }
    
    cout<<s<<endl;
    return 0;
}
