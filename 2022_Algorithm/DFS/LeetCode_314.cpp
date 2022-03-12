/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
 생각보다 문제 풀이가 어려웠는데,

 input = [1,2,3,4,5,6,null,null,7,8,null,null,9,null,10,null,11,10]
 output = [[4],[2,7,8],[1,5,6,10,11,10],[3,9]]
 
 column | (row, val)
 -2     | (2, 4)
 -1     | (1, 2)
 -1     | (3, 7)
 -1     | (3, 8)
 0      | (0, 1)
 0      | (2, 5)
 0      | (2, 6)
 0      | (4, 10)
 0      | (4, 11)
 0      | (4, 10)
 1      | (1, 3)
 1      | (3, 9)
 
 와 같은 테이블이 만들어지게 되는데, 이렇게 만드는 이유는 root를 기준으로
 root는 column 이 0이고, row 가 0이며 val 는 1이라는 기준으로
 left 트리로 갈 때는 column - 1, row + 1, val 으로 적용된다.
 right 트리로 갈 때는 column + 1, row + 1, val 으로 적용된다.
 
 재귀로 해당 트리를 preorder로 순회하면서 맵에 {column, {row, val}} 순으로 만들어준다.
 
 그 후 출력할 때는 vertical 순서에 맞도록 안정 정렬로 수행한 후, 답에 넣어주면 된다.
 
 안정 정렬로 하는 이유?
 column = 0 일 때, (4, 10), (4, 11), (4, 10) 으로 출력해야 되지만,
 그냥 정렬 할 때 (4, 10), (4, 10), (4, 11) 순으로 안정이 깨지기 때문이다.
 */
class Solution {
    vector<vector<int>> ans;
    map<int, vector<pair<int, int>> > m;
    int minCol;
    int maxCol;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if (root == nullptr) {
            return ans;
        }
        
        dfs(root, 0, 0);
        
        for(int i = minCol; i <= maxCol; i++) {
            vector<pair<int, int>> cur = m[i];
            
            // verticalOrder 를 맞추기 위해서 안정 정렬로 해줘야 한다.
            stable_sort(cur.begin(), cur.end(), compare);
            
            vector<int> v;
            for(int j = 0; j < cur.size(); j++) {
                v.push_back(cur[j].second);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
    
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    
    void dfs(TreeNode* root, int row, int col) {
        if(root == nullptr) {
            return;
        }
        
        m[col].push_back({row, root->val});
        
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);
        
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
};
