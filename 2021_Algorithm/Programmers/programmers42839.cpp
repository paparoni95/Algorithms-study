#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> paper;
    set<int> s;
    for (char c : numbers) paper.push_back(c);

    sort(paper.begin(), paper.end());
    do {
        string temp;
        for (int i = 0; i < paper.size(); i++) {
            temp += paper[i];
            s.insert(stoi(temp));
        }
    } while (next_permutation(paper.begin(), paper.end()));

    for (int n : s) {
        if (isPrime(n)) answer++;
    }

    return answer;
}