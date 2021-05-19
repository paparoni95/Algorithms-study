#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(7);
    for(int i = 0; i < 7; i++)
        cin >> v[i];
        
    sort(v.begin(), v.end());
    
    cout << v[6] << endl;
    cout << v[5] << endl;
    return 0;
}
