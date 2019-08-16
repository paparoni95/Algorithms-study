#include <string>
#include <vector>
#define SIZE 20
using namespace std;

int len, ans;
bool visit[SIZE];
//v : 배열 참조
//sum : 더한 총 합
//cnt : 사용한 숫자의 개수
//target : 맞추려고 하는 숫자
//idx : 현재 숫자의 인덱스
void dfs(const vector<int> &v, int sum, int cnt, int target, int idx){
    if(cnt == len){
        if(sum == target)
            ans++;
    }else{
        //선택 더하거나 혹은 빼거나
        //더하기 선택
        dfs(v, sum + v[idx], cnt + 1, target, idx + 1);
        //빼기 선택
        dfs(v, sum - v[idx], cnt + 1, target, idx + 1);
    }
}

int solution(vector<int> numbers, int target) {
    len = numbers.size();
    dfs(numbers, 0, 0, target, 0);
    return ans;
}
