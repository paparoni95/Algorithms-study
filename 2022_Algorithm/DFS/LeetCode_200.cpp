// TimeComplexity : O (M x N)
// SpaceCOmplexity : O(M x N)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return ans;
    }
    
    int m, n;
    bool visited[301][301];
    
    void dfs(int x, int y, const vector<vector<char>>& grid) {
        const int dx[] = {0,0,-1,1};
        const int dy[] = {1,-1,0,0};
        
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (!visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(nx, ny, grid);
            }
        }
    }
};
