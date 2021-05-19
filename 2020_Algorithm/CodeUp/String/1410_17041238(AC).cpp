#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int openCount = 0, closeCount = 0;
    for(char c : s)
    {
        if(c == '(') openCount++;
        else if(c == ')') closeCount++;
    }
    
    cout<<openCount<<' '<<closeCount<<endl;
    return 0;
}
