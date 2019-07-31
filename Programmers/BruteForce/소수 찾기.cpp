#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

//소수인지 아닌지 판별
bool prime(int num){ 
    if(num == 0) return false;
    if(num == 2) return true;
    
    int cycle = (int)sqrt(num);
    for(int i=2; i<=cycle; i++){
        if(num % i == 0) return false;
    }
    return true;
}
//해당 문자열을 가지고 있는 종이로 만들 수 있는지
bool usePaper(vector<int> copy, string str){
    int size = str.size();
    for(int i=0; i<size; i++){
        char ch = str[i];
        if(copy[(int)(ch-'0')] >= 1){
            copy[(int)(ch-'0')]--; //종이 사용
        }else
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int size = numbers.size();
    
    vector<int> check(10, 0); //가지고 있는 종이 배열
    for(int i=0; i<size; i++){
        int temp = (numbers[i]-'0');
        check[temp]++; //종이 사용횟수 증가
    }
    vector<char> v; 
    for(int i=0; i<size; i++){
        v.push_back(numbers[i]);
    }
        
    sort(v.begin(), v.end(), greater<char>());
    string str;
    for(int i=0; i<size; i++)
        str+=v[i];
    int maxValue = stoi(str); //만들 수 있는 가장 큰수를 저장
    
    vector<int> copy; //여러가지 테스트 케이스에 쓰기위해서
    for(int i=2; i<=maxValue; i++){
        if(prime(i)){ //소수인지 체크
            str = to_string(i);
            copy = check; //종이 개수 초기화
            if(usePaper(copy, str)) //가지고 있는 종이로 만들 수 있는지
                answer++;
        }
    }
    
    return answer;
}
