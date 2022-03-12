/*
생각보다 애먹은 문제

범위가 -300 <= x,y <= 300 이여서, 음수의 범위에서도 나이트가 움직일 수 있다는 점을 캐치해야된다.
그런데 배열의 인덱스에는 음수가 들어갈 수 없기 때문에 좌표를 전부 +300씩 이동시켜 계산하면 된다.
*/
class Solution {
public:
    int minKnightMoves(int x, int y) {
        int dx[] = {-1,-2,-2,-1, 1, 2,2,1};
        int dy[] = {-2,-1, 1, 2,-2,-1,1,2};
        
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<bool>> visit(602, vector<bool>(602, false));
        visit[300][300] = true;
        
        int cnt = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                
                if(cx == x && cy == y) {
                    return cnt;
                }
                
                for(int i = 0; i < 8; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(nx < -300 || ny < -300 || nx > 300 || ny > 300)
                        continue;
                    if(visit[nx+300][ny+300])
                        continue;
                    q.push({nx, ny});
                    visit[nx+300][ny+300] = true;
                }
            }
            cnt++;
        }
        
        return -1; // 잘못된 경우
    }
};
