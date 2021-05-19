#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int len = arrangement.size();
    stack<int> iron;
    
    char prev = arrangement[0]; // 처음에는 (
    char now;
    int ironCnt = 0;
    for(int i = 1; i < len; i++){
        if(prev == '('){
            if(arrangement[i] == '('){ // "((" 쇠막대기증가
                ironCnt++;
                iron.push(ironCnt);
            }else if(arrangement[i] == ')'){ // "()" 레이저생성
                answer+=iron.size();
            }       
        }else{
            // ")(" 는 따로 의미가 없다.
            if(arrangement[i] == ')'){ // "))" 쇠막대기감소
                ironCnt--;
                iron.pop();
                answer++;
            }
        }
        prev = arrangement[i]; //현재의 값은 다음에 올 값의 이전이기 때문에
    }
    
    return answer;
}
