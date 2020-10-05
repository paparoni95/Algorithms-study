## 탐색 (Search)
내가 원하는 데이터를 찾는 방법으로는 `선형 탐색`과 `이진 탐색`이 있다.    
추가적으로 `트리 자료구조`에서 `이진 탐색 트리`로 효율적인 탐색이 가능하다.    

### 선형 탐색 (Sequential Search)
리스트에서 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 차례대로 확인하는 탐색 알고리즘이다.    
시간복잡도는 데이터의 개수가 N개일 때, `O(N)`
```cpp
int findTarget(vector<int>& arr, int target){
  for(int i = 0; i < arr.size(); i++){
    if(target == arr[i])
      return i; // 원하는 target의 인덱스를 반환
  }
  // target이 없다면 -1 인덱스를 반환(실패)
  return -1;
}
```

### 이진 탐색 (Binary Search)
탐색 범위를 반으로 좁혀가며 빠르게 탐색하는 알고리즘으로 데이터의 개수가 N개일 때, 시간복잡도는 `O(logN)`    
단, 배열 내부의 데이터가 정렬되어 있어야만 사용할 수 있는 알고리즘이다.    
구현 방법은 `반복분`과 `재귀함수`방식이 있다.    
보통 탐색 범위가 매우 큰 상황에서의 탐색을 할 때 사용한다.
```cpp
// 반복문
int binarySearch(vector<int>& arr, int target, int start, int end){
  while(start <= end){
    int mid = (start + end) / 2;
    // 타깃을 찾은 경우 인덱스를 반환
    if(arr[mid] == target) return mid;
    // 중간점의 값보다 타깃의 값이 작은 경우 왼쪽 확인
    else if(arr[mid] > target) end = mid - 1;
    // 중간점의 값보다 타깃의 값이 큰 경우 오른쪽 확인
    else start = mid + 1;
  }
}
```
```cpp
// 재귀함수
int binarySearch(vector<int>& arr, int target, int start, int end){
  if(start > end) return -1;
  int mid = (start + end) / 2;
  // 타깃을 찾은 경우 인덱스를 반환
  if(arr[mid] == target) return mid;
  // 중간점의 값보다 타깃의 값이 작은 경우 왼쪽 확인
  else if(arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
  // 중간점의 값보다 타깃의 값이 큰 경우 오른쪽 확인
  else return binarySearch(arr, target, mid + 1, end);
}
```

### 이진 탐색 트리 (Binary Search Tree)
기본적으로 트리의 구조는 다음과 같은 특징을 가진다.
* 부모 노드보다 왼쪽 자식 노드가 작다.
* 부모 노드보다 오른쪽 자식 노드가 크다.    
`왼쪽 자식 노드` < `부모 노드` < `오른쪽 자식 노드`    
탐색 과정은 루트 노드부터 시작해서 왼쪽 자식 노드 혹은 오른쪽 자식 노드를 비교하면서 이동하며 반복적으로 방문한다.    
종료 시점은 해당 노드가 `단말 노드(Leaf Node)`이거나 target이 아닐 경우이다.    
시간 복잡도는 트리의 데이터의 개수가 N개일 때, 타깃을 찾는 과정이 최악의 경우 트리의 높이까지만 탐색 및 비교하므로 `O(logN)`이다.
