#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

/*
정답 배열의 사이즈를 정해놓자. (이거 때문에 시간 20분 날림 ㅠㅠ)
중복 처리 : set 을 이용할지, unique 를 이용할지

stringstream 에서 "abc def" 를 각 "abc", "def" 로 파싱할 때
ss >> a >> b; 이렇게 연달아 적어도 된다. 왜? >> 의 리턴은 자신의 참조를 리턴하므로 연달아 사용이 가능하다.

이런 점만 유의해서 작성하자.
*/
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, set<string> > table; // (key = 신고자, value = 신고한 리스트)
    set<string> chk;
    map<string, int> m;
    
    // 신고부터 처리하자.
    for(int i = 0; i < report.size(); i++) {
        stringstream ss(report[i]);
        
        string a;
        string b;
        
        ss >> a;
        ss >> b;
        
        table[a].insert(b);
        if (chk.find(report[i]) == chk.end()) {
            chk.insert(report[i]);
            m[b]++;
        }
    }
    
    // 신고 횟수가 k 이상인 유저를 추려보자.
    for(int i = 0; i < id_list.size(); i++) {
        string name = id_list[i]; // 신고자 | 신고 당한 사람
        
        for(auto it : table[name]) {
            if (m[it] >= k) {
                answer[i]++;
            }
        }
    }
    
    return answer;
}
