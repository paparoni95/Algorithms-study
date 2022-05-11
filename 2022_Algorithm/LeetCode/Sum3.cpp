// combination 풀이
class Solution {
public:
    set<vector<int>> s;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        go(1, 0, k, n, v);
        
        vector<vector<int>> ans;
        for(auto p : s) {
            ans.push_back(p);
        }
        
        return ans;
    }
    
    void go(int idx, int cnt, int goal, int n, vector<int>& v) {
        if(cnt == goal) {
            int sum = 0;
            for(int i = 0; i < v.size(); i++) {
                sum += v[i];
            }
            
            if (sum == n) {
                s.insert(v);
            }
            
            return;
        }
        
        for(int i = idx; i <= 9; i++) {
            v.push_back(i);
            go(i + 1, cnt + 1, goal, n, v);
            v.pop_back();
        }
    }
};
