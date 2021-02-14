#include <iostream>
using namespace std;

int main()
{
    int n;
    play:
    cin>>n;
    if(n != 0)
    {
        cout<<n<<endl;
        goto play;
    }
    return 0;
}
