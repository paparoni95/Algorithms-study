#include <string>
#include <vector>
#include <tuple>
#include <queue>
#define MAX_VALUE 987654321
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = MAX_VALUE;
    queue<tuple<vector<string>, string, int>> q;
    
    //처음에는 words와 시작 단어, 비교한 횟수 넣기.
    q.push(make_tuple(words, begin, 0));
    
    while(!q.empty()){
        vector<string> v = get<0>(q.front());
        string str = get<1>(q.front());
        int cnt = get<2>(q.front());
        
        q.pop();
        
        //words에서 선택한 단어가 target과 같다면 (목표성공)
        if(str.compare(target) == 0){
            answer = cnt;
            break;
        }
        
        for(int i = 0; i < v.size(); i++){
            int diff = 0;
            
            //다음 칸으로 이동하려면 문자의 차이가 1이여야 한다.
            for(int j = 0; j < str.size(); j++){
                if(str[j] != v[i][j])
                    diff++;
            }
            
            //차이가 1이라면, begin은 한 칸 증가하게 되고,
            //기존 words에서 비교했던 문자열을 지운다.
            if(diff == 1){
                vector<string> temp = v;
                vector<string>::iterator iter =  temp.begin() + i;
                temp.erase(iter);
                //수정된 words, begin, cnt로 큐에 다시 넣는다.
                q.push(make_tuple(temp, v[i], cnt + 1));
            }
        }
    }
    //전혀 움직일 수 없었다면
    if( answer == MAX_VALUE) return 0;
    else return answer;
}
