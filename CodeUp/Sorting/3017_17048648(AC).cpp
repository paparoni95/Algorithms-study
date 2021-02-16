#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct student
{
    int num;
    int math;
    int info;
};

int n;
vector<student> v;

bool compare(const student& a, const student& b)
{
    if(a.math == b.math)
    {
        if(a.info == b.info)
            return a.num < b.num;
        else
            return a.info > b.info;
    }
    else
        return a.math > b.math;
}

int main()
{
    cin >> n;
    v.resize(n);
    
    for(int i = 1; i <= n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({i,a,b});
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < n; i++)
    {
        cout<<v[i].num<<' '<<v[i].math<<' '<<v[i].info<<endl;
    }
    
    return 0;
}
