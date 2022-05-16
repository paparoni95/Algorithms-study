#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

// 원소에 정해진 순서가 있으며, 원소의 순서가 다르면 서로 다른 튜플
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

// 파싱할 때 주의할 점, isdigit 보다는 확실히 구분해서 사용하고,
// 현재가 i일 때, 배열에서 i + 1의 범위 볼 수 있다.
vector<int> solution(string s) {
    vector<int> ans;
    map<int, int> m;
    
    s = s.substr(1, s.length() - 2);
    
    string num;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c != '{' && c != '}' && c != ',') {
            num += c;
            if (s[i + 1] != ',' && s[i + 1] != '}') continue;
            m[stoi(num)]++;
        }
        num = "";
    }
    
    // map의 pair를 vector로 이주
    vector<pair<int, int>> list(m.begin(), m.end());
    sort(list.begin(), list.end(), compare);
    
    for(auto p : list) {
        ans.push_back(p.first);
    }

    return ans;
}
