# BFS (Breadth First Search, 너비 우선 탐색)
가장 가까운 노드부터 탐색하는 알고리즘이며, 모든 노드를 한 번씩 방문한다.

마치 잔잔한 호수에 물방울을 떨어트렸을 때, 진동하는 파동처럼 탐색을 펼친다.<br>
`Queue` 자료구조를 이용해서 구현한다.

## 동작 방식
1. 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다.
2. 큐에서 노드를 꺼내 해당 노드의 인접 노드 중 아직 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리를 한다.
3. 1~2 과정을 더 이상 수행할 수 없을 때까지 반복한다.

## 유의사항
- 모든 경로의 가중치가 동일해야한다. 만약 가중치가 서로 다를 때의 최단경로는 구하라고 한다면 `다익스트라`를 이용하자.
- 모든 경로의 가중치가 동일하다는 조건하에 최단 경로를 구할 수 있다.
- 일반적으로는 `DFS`보다 실제 수행 시간이 좋은 편이다. (DFS는 재귀로 보통 구현하기 때문)

## 구현
```cpp
void bfs(int start)
{
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while(!q.empty())
  {
    int cur = q.front();
    q.pop();
    
    for(int i = 0; i < graph[cur].size(); ++i)
    {
      int next = graph[cur][i];
      if(!visited[next])
      {
        q.push(next);
        visited[next] = true;
      }
    }
  }
}
```
