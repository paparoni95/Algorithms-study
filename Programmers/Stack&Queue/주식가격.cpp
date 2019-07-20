#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    for(int i = 0; i < len; i++) //가격이 떨어지지 않는 최대기간
        answer.push_back(len-1-i);
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(prices[i] > prices[j]){//현재 위치의 가격보다 더 떨어지는 가격대가 있다면
                answer[i] = j - i; //갱신한다.
                break;
            }
        }
    }
    return answer;
}
