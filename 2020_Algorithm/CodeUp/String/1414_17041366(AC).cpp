#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int findC = 0, findCC = 0;
    for(char ch : s)
    {
        if(ch == 'c' || ch == 'C') findC++;
    }
    
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == 'c' || s[i] == 'C')
        {
            if(s[i + 1] == 'c' || s[i + 1] == 'C')
            {
                findCC++;
            }
        }
    }
    
    cout<<findC<<endl;
    cout<<findCC<<endl;
    return 0;
}
