#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> ready; //대기중인 트럭
    vector<pair<int, int>> onBridge; //다리 위에 있는 트럭
    int cntTrucks = 0; //도착한 트럭의 수
    int sumTrucks = 0; //다리 위의 트럭의 무게의 합
    int temp = 0;
    int size = truck_weights.size();
    
    for(int i = 0; i < size; i++)
        ready.push(make_pair(truck_weights[i], bridge_length)); //다리 건너기 전 상태
    
    while(true){
        answer++; //1초 증가
        //cout<<answer<<"초"<<endl;
        if(cntTrucks == size) break; //다 도착했다면
        if(!ready.empty()){
            temp = ready.front().first;
            //cout<<"들어가기전 트럭의 무게 총합: "<< sumTrucks + temp <<endl;
            if(sumTrucks + temp <= weight){ //다리가 충분히 버틸 수 있는 무게라면
                sumTrucks+=temp;
                 //다리위에 올린다. (무게, 시간)
                onBridge.push_back(make_pair(ready.front().first, ready.front().second));
                ready.pop();
             }
        }
        if(!onBridge.empty()){ //다리 위에 트럭이 있다면?
            for(int i = 0; i < onBridge.size(); i++){
                onBridge[i].second--; //1초에 1칸씩 전진
                if(onBridge[i].second == 0){
                    cntTrucks++; //도착했으니까 도착한 트럭의 수 증가
                    sumTrucks-=onBridge[i].first;
                }
            }
        }
    }
    return answer;
}
