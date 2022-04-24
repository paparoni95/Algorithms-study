#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

// stringstream 파싱 (원하는 자료형의 데이터를 추출할 때 유용하다.)
int solution(string dartResult) {
    stringstream ss(dartResult);
    
    vector<int> sum(3, 0);
    vector<int> option(3, 1);
    for(int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char type;
        
        ss >> score;
        //score = ss.get(); // 문자를 숫자 아스키코드로 읽는다.
        bonus = ss.get();   // 커서를 하나씩 옮기면서 값을 반환
        type = ss.get();
        
        if (type != '*' && type != '#')
            ss.unget(); // 커서를 앞으로 다시 옮긴다. (잘못된 문자열을 읽어드렸기 때문에)
        
        if (bonus == 'S') sum[i] += pow(score, 1);
        if (bonus == 'D') sum[i] += pow(score, 2);
        if (bonus == 'T') sum[i] += pow(score, 3);
        
        if (type == '*') {
            if (i > 0 && option[i - 1])
                option[i - 1] *= 2;
            option[i] *= 2;
        }
        else if (type == '#') 
            option[i] *= -1;
    }
    
    int answer = 0;
    for(int i = 0; i < 3; i++)
        answer += (sum[i] * option[i]);
    
    return answer;
}
