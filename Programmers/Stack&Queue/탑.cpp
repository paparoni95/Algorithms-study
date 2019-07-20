#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
    int len = heights.size();
    vector<int> answer(len, 0);
    stack<pair<int, int>> topInfo; //(탑 높이, 탑 번호)
    queue<pair<int, int>> ready;   // 탑 대기
    
    for(int i = 0; i < len; i++)
        topInfo.push(make_pair(heights[i], i));
    
    int nowHeight = topInfo.top().first; //현재 탑의 높이
    int nowNum = topInfo.top().second;   //현재 탑의 번호
    topInfo.pop();
    while(!topInfo.empty()){
        int lookHeight = topInfo.top().first; //바라보는 탑의 높이
        int lookNum = topInfo.top().second;   //바라보는 탑의 번호
        topInfo.pop();
        
        if(nowHeight < lookHeight){ //송신할 수 있다면
            answer[nowNum] = lookNum + 1;
            nowHeight = lookHeight;
            nowNum = lookNum;
        }else{
            ready.push(make_pair(lookHeight, lookNum));
        }
    }
    while(!ready.empty()){ //아직 검증되지 않은 부분의 탑을 검사
        int lookHeight = ready.front().first;
        int lookNum = ready.front().second;
        ready.pop();
        for(int j = lookNum-1; j >= 0; j--){
            if(heights[j] > lookHeight){
                answer[lookNum] = j + 1;
                break;
            }
        }
    }
    return answer;
} 
