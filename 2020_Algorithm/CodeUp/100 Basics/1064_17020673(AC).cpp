#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    
    int result;
    result = ((a > b) ? b : a);
    result = (result > c) ? c : result;
    cout<<result<<endl;
    return 0;
}
