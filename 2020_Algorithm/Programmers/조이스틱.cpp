#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 이번 문제는 조금 이상하다.
// 현재 위치에서 오른쪽으로 이동한 것과 왼쪽으로 이동한 것이 같다면,
// 오른쪽으로 이동하는 것이 정답이고, 왼쪽으로 이동하게 되면 정답이 아니게 된다.
// 케이스) BBBAAAB 오른쪽으로 이동할 시 9 / 왼쪽으로 이동할 시 8

int ChangeAlphabet(int i, string str) {
    int up = str[i] - 'A';
    int down = 'Z' - str[i] + 1;

    return min(up, down);
}

int solution(string name) {
    int answer = 0;
    int cnt = 0;
    int len = name.length();
    vector<int> check(len, 0);
    for (int i = 0; i < len; ++i) {
        if (name[i] != 'A')
            cnt++;
        else
            check[i] = 1;
    }

    int idx = 0;
    for (int i = 0; i < cnt; ++i) {
        if (check[idx]) {
            int l_idx = idx;
            int r_idx = idx;
            int left = 0;
            int right = 0;

            // <-
            while (check[l_idx]) {
                if (l_idx == 0) l_idx = len - 1;
                else l_idx--;
                left++;
            }

            // ->
            while (check[r_idx]) {
                r_idx = (r_idx + 1) % len;
                right++;
            }

            if (left < right) {
                idx = l_idx;
                answer += left;
            }
            else {
                idx = r_idx;
                answer += right;
            }
        }
        check[idx] = 1;
        answer += ChangeAlphabet(idx, name);
    }
    return answer;
}