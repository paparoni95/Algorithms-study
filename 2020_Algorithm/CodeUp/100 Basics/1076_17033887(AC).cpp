#include <iostream>
using namespace std;

int main()
{
    char end;
    cin>>end;
    
    char ch = 'a';
    do
    {
        cout<<ch<<' ';
        ch++;
    }while(ch <= end);
    return 0;
}
