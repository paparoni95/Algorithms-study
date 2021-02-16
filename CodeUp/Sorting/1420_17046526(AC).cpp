#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<int,string>> v;

int main()
{
    int n;
    cin>>n;
    v.resize(5);
    
    string name;
    int score;
    for(int i = 0; i < n; i++)
    {
        cin>>name>>score;
        v.push_back({score, name});
    }
    
    sort(v.begin(), v.end(), greater<pair<int, string>>());
    
    cout<<v[2].second<<endl;
    return 0;
}
