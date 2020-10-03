#include <bits/stdc++.h>
using namespace std;

// 주어진 로직을 그대로 구현할 수 있는지 파악
// 재귀함수를 이해하고 작성할 수 있는지 파악

// "균형잡힌 괄호 문자열"의 인덱스 반환
int BalancedIndex(string p) {
    int count = 0; // 왼쪽 괄호의 개수
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count++;
        else count--;
        if (count == 0) return i;
    }
    return -1;
}

// "올바른 괄호 문자열"인지 판단
bool CheckProper(string p) {
    int count = 0; // 왼쪽 괄호의 개수
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') count++;
        else {
            if (count == 0) return false; // 쌍이 맞지 않는 경우에 false 반환
            count--;
        }
    }
    return true; // 쌍이 맞는 경우에 true 반환
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;
    int index = BalancedIndex(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    // "올바른 괄호 문자열"이면, v에 대해 함수를 수행한 결과를 붙여 반환
    if (CheckProper(u)) {
        answer = u + solution(v);
    }
    // "올바른 괄호 문자열"이 아니라면 아래의 과정을 수행
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2); // 첫 번째와 마지막 문자를 제거
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}