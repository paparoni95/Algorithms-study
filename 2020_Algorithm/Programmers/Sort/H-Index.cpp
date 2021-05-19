#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    bool chk = false;
    sort(citations.begin(), citations.end(), greater<int>()); //내림차순
    
    //논문 size 편 중, h번 이상 인용된 논문이 h편 이상이고,
    //나머지 논문들도 h번 이하로 인용됬다면, 그것이 H-index
    //H-index는 0편부터 시작하며, 규칙은 다음과 같다.
    //H-index는 H-index 이상 인용된 논문이 h개 이상이여야 되고,
    //동시에 나머지 논문들은 h번 이하로 인용되어야 한다.
    for(int h = 0; h < citations.size(); h++){
        if(h >= citations[h]){ 
            answer = h;
            chk = true;
            break;
        }
    }
    if(chk) return answer;
    else return citations.size(); //조건을 만족하지 않으면, 발표한 논문의 개수가 답이다.
}
