#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int one[5]={1,2,3,4,5};
int two[8]={2,1,2,3,2,4,2,5};
int three[10]={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    int oneCnt = 0, twoCnt = 0, threeCnt = 0;
    int oneIdx = 0, twoIdx = 0, threeIdx = 0;
    vector<int> answer;
    
    for(int i = 0; i < answers.size(); i++){
        if(one[i%5] == answers[i]) oneCnt++;
        if(two[i%8] == answers[i]) twoCnt++;
        if(three[i%10] == answers[i]) threeCnt++;
    }
    vector<int> v;
    vector<int> v2;
    int count = 0;
    v.push_back(oneCnt); v.push_back(twoCnt); v.push_back(threeCnt);
    int total = max(oneCnt, max(twoCnt, threeCnt));
    for(int i = 0; i < v.size(); i++){
        if(total == v[i]){
            count++;
            v2.push_back(i+1);
        }    
    }
    if(count == 1){
        for(int i = 0; i < v2.size(); i++)
            answer.push_back(v2[i]);
    }else if(count == 2){
        for(int i = 0; i < v2.size(); i++)
            answer.push_back(v2[i]);
    }else{
        for(int i = 0; i < v2.size(); i++)
            answer.push_back(v2[i]);
    }
    
    return answer;
}
