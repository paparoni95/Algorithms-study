#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> chk(10);
    
    for(int i = 0; i < numbers.size(); i++)
        chk[numbers[i]] = true;
    
    for(int i = 0; i < chk.size(); i++)
    {
        if (chk[i]) continue;
        answer += i;
    }
    return answer;
}
