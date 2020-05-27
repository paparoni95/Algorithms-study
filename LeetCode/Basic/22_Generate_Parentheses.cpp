class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //backtracking  recursion À¯Çü
        vector<string> answer;
        DFS(n, 0, 0, "", answer);
        return answer;
    }

    void DFS(int n, int numOpen, int numClosed, string s, vector<string>& v)
    {
        // termination check
        if (numOpen == n && numClosed == n)
        {
            v.push_back(s);
            return;
        }

        // recurse next
        if (numOpen < n)
        {
            DFS(n, numOpen + 1, numClosed, s + "(", v); // add open bracket
        }

        if (numOpen > numClosed)
        {
            DFS(n, numOpen, numClosed + 1, s + ")", v); // add close bracket 
        }
    }
};