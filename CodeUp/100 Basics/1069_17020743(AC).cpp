#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin>>ch;
    
    switch(ch)
    {
        case 'A':
            cout<<"best!!!";
            break;
        case 'B':
            cout<<"good!!";
            break;
        case 'C':
            cout<<"run!";
            break;
        case 'D':
            cout<<"slowly~";
            break;
        default:
            cout<<"what?";
            break;
    }
    
    return 0;
}
