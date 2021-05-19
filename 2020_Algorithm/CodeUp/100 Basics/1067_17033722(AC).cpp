#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n % 2 == 0)
    {
        if(n > 0)
        {
            cout<<"plus\n";
            cout<<"even\n";
        }
        else
        {
            cout<<"minus\n";
            cout<<"even\n";
        }
    }
    else
    {
        if(n > 0)
        {
            cout<<"plus\n";
            cout<<"odd\n";
        }
        else
        {
            cout<<"minus\n";
            cout<<"odd\n";
        }
    }
    
    return 0;
}
