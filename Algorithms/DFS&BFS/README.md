## 탐색 알고리즘

### 그래프 표현 방식
* `인접 행렬`(Adjacency Matrix)
  + 2차원 배열로 그래프의 연결 관계를 표현하는 방식
  ```cpp
  int graph[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  ```
  + 노드의 개수가 많을수록 메모리가 불필요하게 낭비된다. (완전 그래프에서는 높은 효율을 보여준다.)
  + 그렇지만 A노드와 B노드의 연결관계 확인이 `O(1)`로 가능하다. graph[A][B] = 1 (연결), 0(연결되지않음)

* `인접 리스트`(Adjacency List)
  + 리스트로 그래프의 연결 관계를 표현하는 방식
  ```cpp
  vector<int> graph[3];
  
  // 노드 1과 연결된 노드는 2와 3
  graph[1].push_back(2);
  graph[1].push_back(3);
  
  // 노드 2와 연결된 노드는 4와 5
  graph[2].push_back(4);
  graph[2].push_back(5);
  ```
  + 연결된 정보만 저장하기 때문에 메모리를 효율적으로 사용한다. (노드의 개수가 많고 간선이 적다면 유리하다.)
  + 다만 특정한 두 노드가 연결되어 있는지에 대한 정보를 얻는 속도가 느리다. `O(V)`로 확인이 가능.
  
  
### 깊이 우선 탐색(DFS, Depth First Search)
깊이를 우선적으로 탐색하는 알고리즘이며, 모든 노드를 한 번씩 방문한다.        
`스택자료구조`를 사용하며, `재귀`를 사용해도 된다.    
데이터의 개수가 N개인 경우 `O(N)`의 시간이 소요된다.    
```cpp
void dfs(int x){
  visited[x] = true;
  cout << x << ' ';
  // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
  for(int i = 0; i < graph[x].size(); i++){
    int next = graph[x][i];
    if(!visited[next])
      dfs(next);
  }
}
```

### 너비 우선 탐색(BFS, Breadth First Search)
가장 가까운 노드부터 탐색하는 알고리즘이며, 모든 노드를 한 번씩 방문한다.    
`큐 자료구조`를 사용하며, 탐색하는 과정이 마치 물의 파동처럼 퍼져나간다.    
추가적으로 모든 간선의 비용이 1이라고 가정했을 때, 최단 경로를 구할 수 있다.    
```cpp
void bfs(int start){
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    cout << x << ' ';
    // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
    for(int i = 0; i < graph[x].size(); i++){
      int next = graph[x][i];
      if(!visited[next]){
        q.push(next);
        visited[next] = true;
      }
  }
}
```

### Flood Fill
코딩 테스트에서는 2차원 배열에서의 탐색 문제를 만나면 아래와 같이 탐색을 진행하는 방법도 있다.
```cpp
// 2차원 배열에서 상, 하, 좌, 우로 이동할 때 사용하는 배열
int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};
void simulate(){
  queue<pair<int, int>> q;
  q.push({0,0}); // 튜플 형태가 {행, 열}
  visited[0][0] = true;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    cout<< '(' << x <<", " << y << ')' << ' ';
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      // boundary check(n : row, m : column)
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      // 이미 방문을 했거나, 갈 수 없는 길이면 
      if(visited[nx][ny] || graph[nx][ny] != 1) continue;
      visited[nx][ny] = true;
      q.push({nx,ny});
    }
  }
}
```

