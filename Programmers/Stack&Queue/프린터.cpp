#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; //몇 번째로 출력했는지
    queue<pair<int,int>> q;
    for(int i = 0; i < priorities.size(); i++)
        q.push(make_pair(i, priorities[i])); //(들어온 순서, 중요도)를 큐에 삽입
    while(!q.empty()){
        int order = q.front().first; //들어온 순서
        int value = q.front().second;//중요도
        q.pop(); //대기큐에서 인출
        //나머지 준비큐에서 가장 높은 중요도를 넣는다.
        int listMaxValue = 0;
        for(int i = 0; i < priorities.size(); i++){
            if(listMaxValue < priorities[i])
                listMaxValue = priorities[i];
        }
        //cout<<value<<' '<<listMaxValue<<endl;
        if(value >= listMaxValue){
            answer++;
            priorities[order] = -1; //해당 순서의 중요도는 약해진다.
            if(location == order) break;
        }else
            q.push(make_pair(order,value)); //대기목록의 가장 마지막에 넣는다.
    }
    return answer;
}
