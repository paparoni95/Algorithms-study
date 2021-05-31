#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        //가격이 줄었다면, 반영해주기
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        //stack에서 가장 위쪽에 있는 데이터는 마지막에 들어온 데이터이기 때문에
        answer[st.top()] = n - st.top() - 1;
        st.pop();
    }
    return answer;
}