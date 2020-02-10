# 알고리즘 정복하기

* 좋은 개발자가 되기 위해 하루동안 학습한 알고리즘 내용이나 경험들을 기록을 통해 남긴다.
* 다양한 알고리즘을 통해서 탄탄한 기본기를 갖추는 것이 목표이다.
* 여기서의 내용은 알고리즘이여도 되고, 알고리즘을 풀 때 사용한 함수나 문법의 경험, 자료구조도 작성한다.
* 지금은 못하더라도 조급해지지 않고 꾸준히 열심히 하자!

작성하게 된 계기는 [namjunemy](https://github.com/namjunemy/TIL)의 Github를 보고 나도 작성하기로 했다.

# 다짐
* 중요한 것은 모르는 부분을 찾고자 할 때, 추가적인 검색의 비용이 들지 않도록 자세히 기록한다.
* 참고한 자료는 꼭 출처를 남기자.
* 어려워도 포기하지 말고 해보자.

# Algorithm
유한한 단계를 통해 문제를 해결하기 위한 절차나 방법을 말한다. <br>
`슈도코드` 의사코드로 흉내낸 코드 <br>
`순서도` 프로그램이나 작업의 진행흐름을 순서에 따라 여러가지 기호나 문자로 나타낸 지표

**성능 분석** <br><br>
1. `정확성` 얼마나 정확하게 동작하는가?
2. `작업량` 얼마나 적은 연산으로 원하는 결과를 얻어내는가?
3. `메모리사용량` 얼마나 적은 메모리를 사용하는가?
4. `단순성` 얼마나 단순한가?
5. `최적성` 더 이상 개선할 여지 없이 최적화되어있는가?

`시간 복잡도(TimeComplex)` 실제 걸리는 시간을 측정의 지표, 빅-오 표기법 사용 <br>
시간 복잡도를 계산할 때 가장 큰 영향력을 주는 `N`에 대한 항만을 표시한다.

![TimeComplex](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F260F4850559AB6672C45F1) <br>
출처: https://ledgku.tistory.com/33

`공간 복잡도(SpaceComplex)` 얼마나 메모리를 사용했는지에 대한 지표

## 1. 패턴 매칭 알고리즘
본문이 되는 string에서 특정한 string을 찾는 알고리즘 <br>
### 1.1. 무식한 방법(Brute Force)
본문 string을 처음부터 끝까지 차례대로 순회하면서 패턴 내의 문자들을 일일이 비교하면서 확인한다. <br>
본문의 string 길이가 M이고, 찾아야 할 패턴 string 길이가 N이면 <br>
최악의 시간 복잡도는 모든 위치에서 패턴을 비교해야하므로 `O(MN)`이 된다.
### 1.2. KMP 알고리즘
불일치가 발생한 텍스트 string 앞 부분에 어떤 문자가 있었는지 미리 알고 있으므로 불일치가 발생한 앞 부분에 대하여 다시 비교하지 않고 넘어간다. <br>

        0 1 2 3 4 5 6 7 8 9 
    T[] a b c d a b c d f f
    P[] a b c d a b c e f
    
    인덱스 7에서 서로 매칭이 맞지 않기 때문에, 틀린 부분의 앞 부분에서 a b c 가 같음을 이용해서 다시 비교한다.
    
        0 1 2 3 4 5 6 7 8 9 
    T[] a b c d a b c d f f
    P[]         a b c d a b c e f (-> shift됨)
    
### 1.3. 보이어-무어 알고리즘
오른쪽에서 왼쪽으로 비교하는 생각의 전환 <br>
대부분의 상용 소프트웨어에서 채택하고 있는 알고리즘이라고 한다. <br><br>

패턴에 오른쪽 끝에 있는 문자가 불일치하고, 이 문자가 패턴 내에 존재하지 않는 경우 이동거리는 패턴의 길이 만큼 된다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y z w a p p l e
    P[] a p p l e
    
    이 경우 아래와 같이 점프한다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y z w a p p l e
    P[]           a p p l e (패턴의 길이 만큼 이동)
    
패턴에 오른쪽 끝에 있는 문자가 불일치하고, 이 문자가 패턴 내에 존재하는 경우

        0 1 2 3 4 5 6 7 8 9
    T[] f d y w a p p l e l
    P[] a p p l e
    
    이 경우 아래와 같이 점프한다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y w a p p l e l
    P[]         a p p l e
    
    이렇게 점프한 뒤 인덱스 8부터 시작해서 4까지 하나씩 문자를 비교해서 맞는지 확인한다.
### 1.4. 카프-라빈 알고리즘

### 1.5. string 매칭 알고리즘 비교 표
찾고자 하는 string 패턴의 길이를 `M`, 총 string 길이를 `N`이라고 하면 <br>

알고리즘 종류 | 시간 복잡도
---|---
`Bruteforce` | O(MN)
`카프-라빈` | O(N)
`KMP` | O(N)
`보이어-무어` | O(N)보다 빠름, 단 최악의 경우 O(MN)
    
## 2. Stack
물건을 쌓아 올리듯 자료를 쌓아 올린 형태의 자료구조 <br>
Stack에 저장된 자료는 `선형구조`를 가진다. <br>
가장 마지막에 들어간 자료가 가장 먼저 나오는 `후입선출(LIFO)`특징을 지닌다.

### 2.1. 구현
스택에 저장되는 자료구조의 형태는 자료를 선형으로 저장해야 한다. <br>
가장 간단한 방법은 `배열`을 이용하여 구현한다. <br><br>

**배열을 이용한 구현** <br><br>
구현하기는 쉬우나, Stack의 크기를 변경하기 어렵다. (배열은 정적이기 때문에) <br><br>

**연결리스트를 이용한 구현** <br><br>
배열에서의 정적의 문제를 해결할 수 있도록 저장의 크기를 동적으로 할당하여 구현한다. <br>
다만, 배열의 구현에 비해서 구현이 복잡하다. (버그가 일어날 가능성이 있다!) <br>

### 2.2. 필요한 연산
연산 | 기능
--- | ---
`push`    |스택에 자료를 넣는 연산이다.
`pop`     |스택에 자료를 빼는 연산이다. 여기서 뺄 때, 해당 자료를 스택에서 삭제한다.
`isEmpty` |스택이 현재 비어있는지를 확인해주는 연산이다.
`size`    |현재 스택에 몇 개의 요소들이 저장되어있는지 알려주는 연산이다.
`peek`    |스택에 `top`에 있는 원소가 무엇인지 알려준다. `pop`과 다른 점은 top의 원소를 알려주되, 삭제를 하지 않는다는 것이다.

* 스택의 push와 pop을 하는 과정

![stack](https://images.velog.io/post-images/ollabu3/9c1b6840-2a7a-11ea-b060-3102f9b60d17/%EC%8A%A4%ED%83%9DIMG.PNG) <br>
출처: https://velog.io/@ollabu3/codestates-immersive-TIL-2

* push의 슈도코드

```cpp
push(s, x)
{
   top <- top + 1;
   if(top > stack_size) then
        overflow;
   else
        s[top] <- x;
}
end push()
```

* pop의 슈도코드

```cpp
pop(s)
{
   if(top == 0) 
        then underflow;
   else
   {
        return s[top];
        top <- top - 1;
   }
}
end pop()
```

### 2.3. Stack
#### 2.3.1. 괄호검사
  - 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야한다.
  - 괄호의 종류는 `()` `{}` `[]` 가 있다.
  - 괄호의 짝을 검사할 때 `Stack`을 이용할 수 있다.
  - 동작 방식은 문자열에 있는 괄호를 차례대로 하나씩 확인하면서, 여는 괄호이면 stack에 push한다.
  - 닫는 괄호이면 stack의 top에 있는 괄호와 비교해서 맞으면 pop한다.
  - pop을 할 때 이미 stack이 비어있거나, 괄호의 짝이 맞지 않거나, pop을 한 후에 문자열이 끝나게 되고 stack에 남아있다면 실패한다.

#### 2.3.2. 함수호출
  - 가장 마지막에 호출된 함수가 가장 먼저 실행을 완료하고 복귀하는 후입선출 구조이므로 이를 `stack`을 이용해서 수행순서를 관리한다.
  - 함수 호출이 발생하면 호출할 함수 수행에 필요한 `지역변수`, `매개변수` 및 수행후 복귀할 `복귀주소`의 정보를 stack 프레임에 저장한다.
  - 함수의 실행이 끝나게 되면 시스템 stack의 top 원소를 pop하면서 stack 프레임에 저장되어있던 복귀주소를 확인하고 복귀한다.
  - 함수 호출과 복귀에 따라 이 과정을 반복하면서 전체 프로그램 수행이 종료되면 시스템 stack은 공백상태가 된다.

#### 2.3.3. 재귀호출
  - 자기 자신을 호출하여 순환 수행된다.
  - 일반적으로 재귀호출을 이용해서 구현하면 가독성이 높아지며, 프로그램의 크기가 줄어들게 된다.
  - 다만, 디버깅이 어려우며 잘못 작성하게 되면 수행 시간이 많이 소요된다. (깊이가 깊어지게 되면 `stack overflow`가 발생한다.)
  - 재귀호출의 대표적인 것은 `factorial`구현이다.

#### 2.3.4. Memoization
  - 일반적으로 `피보나치 수열`을 구현할 때, 재귀호출을 이용해서 구현할 수 있다. (다만, 중복 호출이라는 문제점이 생기게 된다.)
  
  ```cpp
  fibo(n)
  {
        if(n == 0) then return 0;
        if(n == 1) then return 1;
        else return fibo(n-1) + fibo(n-2);
  }
  end fibo()
  ```
  
  - 위 코드의 문제점은 함수를 한 번 호출할 때마다, 내부적으로 2번의 함수를 호출한다.
  - 이는 호출의 깊이가 깊어질수록 중복 호출이 발생하게 된다.
  ![fibonacci](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Recursions/pix/fib.bmp) <br>
  출처 : http://1ambda.github.io/data-analysis/intro-to-data-science-3/ <br>
  - 한 번 호출할 때마다, 내부적으로 2번을 하므로 결국 시간복잡도는 `O(2^N)`이 되게 된다.
  - 이를 해결하기 위한 solution은 `Memoization`이다.
  
  - Memoization의 핵심은 한 번 구한 답은 메모해놓고, 다시 계산하지 않도록 전체적인 실행속도를 빠르게 하는 기술이다.
  - 이는 DP(동적계획법)에서 쓰이는 테크닉이다.
  - Memoization을 이용해 다시 피보나치 수열을 구현하면 아래와 같다.
  
  ```cpp
  memset(memo, -1, sizeof(memo));
  memo[0] = 0, memo[1] = 1;
  fibo(n)
  {
        if(memo[n] == -1)
                memo[n] = fibo(n-1) + fibo(n-2);
        else
                return memo[n];
  }
  ```
   - 이처럼 기존에 계산하여 저장된 값이 있는 경우에는 다시 계산하지 않고 저장된 메모리에서 값을 찾아 쓰기만 하면 된다.

#### 2.3.5. DFS(깊이우선탐색)
   - 그래프 알고리즘 중 하나이다.
   - 이 알고리즘에서 `stack`은 현재 정점에서 다음 정점으로 갈 곳이 없다면, 기존으로 돌아가기위해 기록하는 역할을 한다.
   - 동작 방식은 다음과 같다.
   - 시작 정점의 한 방향으로 갈 수 있는 경로가 있는 곳까지 깊이 있게 탐색한다.
   - 더 이상 갈 곳이 없게 되면, 가장 마지막에 왔던 길로 되돌아간다. (스택을 사용하는 이유)
   - 다른 방향의 정점으로 탐색을 계속 반복하여 결국 모든 정점을 방문하는 원리이다.
   - 더 자세한 내용은 따로 분류해서 작성한다.

#### 2.3.6. 계산식 사용
`중위 표기식`을 `후위 표기식`으로 변환하는 방법
1. 입력받은 중위표기식에서 `token`을 읽는다.
2. 토큰이 피연산자이면 토큰을 출력한다.
3. 토큰이 연산자(괄호포함)일 경우
	- 우선순위가 높으면 `stack`에 `push`한다.
	- 우선순위가 높지않으면 `token`의 우선순위보다 작을 때까지 `stack`에서 `pop`한 후에 `token`의 연산자를 `push`한다.
4. 토큰이 오른쪽 괄호`)`일 경우
	- `stack`의 `top`에 있는 `(`가 나올 때까지 스택에서 `pop`연산을 수행한다.
	- 여기서 `pop`한 연산자들은 출력하고, `(`를 만나면 `pop`하고 출력하지 않는다. (괄호는 무마하는 방식)
5. 중위표기식에 더 이상 읽을 문자열이 없다면 종료하고, 아니라면 1 ~ 4단계를 반복한다.
6. `stack`에 남아 있는 연산자를 모두 `pop`하여 출력한다.

`후위 표기식`을 `stack`을 이용하여 계산할 수 있다.
1. 피연산자를 만나면 `stack`에  `push`한다.
2. 연산자를 만나면 필요한 만큼의 피연산자를 `stack`에서 `pop`하여 연산하고, 그 연산결과를 다시 `stack`에 `push`한다.
	- 보통 `이항연산자`는 피연산자를 2개를 필요로 하므로, 뽑을 때 먼저 뽑은 것은 뒤로 그 다음 뽑은 것은 앞으로 해서 계산한다.
	- 가장 먼저 뽑은 것을 `second`, 그 다음으로 뽑은 것을 `first`라고할 때
	- `first` + `second` 형식이 되야 한다.
3. 수식이 끝나면, 마지막으로 `stack`에서 `pop`하면 그 결과가 원하는 계산의 결과를 얻을 수 있다.

#### 2.3.7. Backtracking (백트래킹)
해를 찾는 도중에 '막히면' 되돌아가서 다시 해를 찾아가는 기법이다. <br>
어떤 노드의 유망성을 검사한 후에 `유망(Promising)`하지 않다고 결정되면 그 노드의 부모로 `되돌아가(Backtracking)`다음 자식 노드로 간다. <br>
여기서 유망하지 않는 것은 어떤 노드를 방문했을 때 그 노드를 포함한 경로가 해답이 될 수 없다면 그 노드는 유망하지 않은 것이다. <br>
백트래킹을 이용해서 `Optimization(최적화)문제`와 `Decision(결정)문제`를 해결할 수 있다. <br>
* `Decision`문제들의 list
	- 미로찾기
	- N-Queen 문제
	- Map coloring
	- 부분 집합의 합(Subset Sum) 문제

**백트래킹 vs 깊이우선탐색** <br>

* 백트래킹의 특징
	- 어떤 노드에 출발하는 경로가 유망하지 않을 것 같으면 더 이상 그 경로를 가지 않는다.
	- 가치치기(Prunning)이며 불필요한 경로를 조기에 차단한다.
	- 가치치기는 유망하지 않는 노드가 포함되는 경로는 더 이상 고려하지 않는 것이다. `상태공간트리`로도 나타낸다.
	- N!가지의 경우의 수를 가진 문제에 대해서는 일반적으로 DFS보다는 경우의 수는 줄어드나 최악의 경우 지수함수 시간복잡도를 가진다.
	- 모든 후보를 검사하지 않는다.

* 깊이우선탐색의 특징
	- 모든 경로를 추척한다. (다 돌아본다는 뜻)
	- N!가지의 경우의 수를 가진 문제에 대해서는 문제를 해결할 수 없다. (지수 함수의 시간복잡도를 가지므로), 그러나 가짓수가 적으면 가능
	- 모든 후보를 검사한다.

**백트래킹의 동작 방식**
1. 상태공간트리의 깊이 우선 검색을 한다.
2. 각 노드가 유망한지를 점검한다.
3. 만일 그 노드가 유망하지 않는다면, 그 노드의 부모 노드로 백트래킹하여 검색을 계속한다.

**백트래킹을 이용한 다양한 문제들**

1. 미로찾기
	- 스택에 이동한 좌표를 push한다.
	- 막히면 스택의 top에 있는 좌표를 pop하여 되돌아와서 다음에 갈 수 있는 경로를 찾아 다시 스택에 push한다.
	- 여기서 막힌다의 뜻은 더 이상 진행할 수 없으면 진행할 수 있는 상태로 되돌아가야함을 의미한다.
	- 보통 미로찾기의 경우 상,하,좌,우 4방향으로 움직이므로 되돌아온 상태에서는 그 상태에서 아직 방문하지 않은 곳을 방문한다.

2. N-Queen 문제
	- 4 x 4 타일에서 4개의 Queen을 놓는 방법 <br>
![nQueen](https://mblogthumb-phinf.pstatic.net/MjAxOTEyMjZfNDEg/MDAxNTc3MzU4NTkzMTMz.Pf0dYJ8wZJ0UGUJGcDIip4ApUL6v9Nuz3b_YfKO_zMwg.Bvr6Qa0nYsT9ziIxCU053_3ApfMhKPQT4xSw-Ee4QJYg.PNG.do9562/image.png?type=w800) <br>

	- 아래의 두 코드는 권오흠 교수님의 제 2-3강 Recursion의 응용: N queens problem을 공부하고 작성한 방법입니다.<br>
```cpp
int cols[N+1]; // cols[i] = j : i번째 행에 j열에 Queen을 뒀다는 표시
return-type Queens(int level)
{
    if(!Promising(level))         // 유망한지 테스트
       report failure and return; // 유망하지 않다면 백트래킹
    else if (level == N)          // Queen을 N개를 뒀다면 이는 성공을 의미
       report answer and return;
    else
    {
       for(int i = 1; i <= N; i++) // level + 1 행에 1~N까지의 열에 Queen을 놓는다.
       {
           cols[level+1] = i;
           Queens(level+1);
       }
    }
    return false; // 1~N 열에 다 시도해봤지만 다 실패를 의미
}
```

```cpp
bool Promising(int level)
{
   for(int i = 1; i < level; i++)
   {
      if(cols[i] == cols[level]) // 같은 열에 있는지 검사
        return false;
      else if ((level - i) == abs(cols[level] - cols[i])) // 대각선 검사
        return false;
   }
   return true; // 같은 열에도 없고, 대각선에도 걸리지 않는 다면 제대로 Queen을 둔 것이다.
}
```
3. Power Set 문제
	- 어떤 집합의 공집합과 자기자신을 포함한 모든 부분집합을 구하는 문제
	- 구하고자 하는 어떤 집합의 원소 개수가 n개일 경우 부분집합의 개수는 `2^n`이 나온다.
	- 백트래킹 기법으로 Power Set을 만들 수 있다.

	- 일반적인 백트래킹 접근 방법을 이용한다.
	- `True` 또는 `False`값을 가지는 항목들로 구성된 n개의 배열을 만들어서 사용한다.
	- 배열의 i번째는 해당 i번째의 원소가 부분집합의 값인지 아닌지를 나타내는 값이다. `True`면 포함, `False`면 포함하지 않는다.
	- ex) n = 3인 경우
		- `{}`, `{1}`, `{2}`, `{3}`, `{1,2}`, `{1,3}`, `{2,3}`, `{1,2,3}` 총 8가지 이므로, 2^3 = 8이다.

**백트래킹의 주의할 점**
1. 가지치기를 많이 하지 않으면 시간초과 발생한다.
2. 유망한지를 검사할 때 비효율적으로 계산하면 시간초과가 발생한다.
3. 유망하지 않아서 백트래킹을 시도할 때, 값을 제대로 바꿔놓지 않으면 제대로 된 답을 얻을 수 없다.
4. 배열 대신 vector와 같은 STL을 사용했을 때, 함수의 인자로 참조자를 넘기지 않고 직접 넘기면 복사비용이 생겨서 시간초과가 발생할 수 있다.
    


## 3. DP (동적계획법, Dynamic Programming)
그리디 알고리즘 설계 기법과 같이 최적화 문제를 해결하는 알고리즘 설계기법이다. <br><br>
입력의 크기가 작은 부분 문제들을 모두 해결한 후에 그 해들을 이용해서 보다 큰 크기의 부분 문제들을 해결하여 결국에 최종적으로 구해야하는 문제를 해결하는 기법이다. <br><br>

핵심은 풀었던 답을 이용해서 더 큰 문제를 해결하는 기법이다. <br>

### 3.1. Overlapping Subproblem
**`중복되는 부분문제`여야 한다.** <br>
피보나치 수열에서의 중복되는 부분문제는 다음과 같다.<br>

    fibo(5) = fibo(4) + fibo(3)
    fibo(4) = fibo(3) + fibo(2)
    fibo(3) = fibo(2) + fibo(1)
    fibo(2) = fibo(1) + fibo(0)
 
### 3.2. Optimal Substructure
**문제의 정답을 작은 문제의 정답에서 구할 수 있다.** <br>
기존에 `fibo(3)`과 `fibo(2)`를 구했으면 `fibo(4)`를 구할 때 이용할 수 있다. <br>
여기에서 사용하는 테크닉은 `Memoization`이다. <br>
한 번 구한 답은 다시 구할 필요가 없으며, 구한 답을 이용해서 문제를 해결하는 기술이다. <br>

### 3.3. DP 구현방식
`Top-down`과 `bottom-up`방식이 있다.

### 3.3.1 Top-down
`stack`이나 `recursive`방식을 이용해서 구현한다. <br>
다만 문제는, 깊이가 깊어지게 되면 `overflow`가 발생할 수 있다. <br>

* 기존에 문제가 되었던 피보나치 수열을 재귀로 푼 방식

```cpp
#include <stdio.h>

int fibo(int n) {
	if (n == 1) return 1; //fibo(1)
	if (n == 2) return 2; //fibo(2)
	return fibo(n - 1) + fibo(n - 2); //fibo(3)이상
}

int main() {
	printf("%d\n", fibo(5));
	return 0;
}
```

* Memoization 기법을 이용해서 조금 더 효율적으로 작성한 방식

```cpp
#include <stdio.h>

int memo[100]; //푼 답을 저장할 공간

int fibo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
    /* 이미 문제를 푼 답이 있다면? */
	if (memo[n] > 0) return memo[n];
    /* 처음 보는 문제이면 */ 
	else {
		memo[n] = fibo(n - 1) + fibo(n - 2);
		return memo[n];
	}
}

int main() {
	printf("%d\n", fibo(45)); //아까는 fibo(5)를 구했지만, fibo(45)도 구할 수 있다.
	return 0;
}
```
이렇게 구현함으로써 얻을 수 있는 성능의 이점은 다음과 같다. <br>
기존에 함수를 한 번 호출하면 2번이 호출되어 시간복잡도 `O(2^N)`이였다면, Memoization을 이용하여 `O(N)`으로 단축했다.<br>

### 3.3.2. Bottom-up
재귀적으로 구현하는 것보다 반복적 구조를 이용해서 구현하면 성능면에서 보다 효율적이다.

```cpp
#include <stdio.h>

int memo[100]; //푼 답을 저장하는 공간

int fibo(int n) {
	memo[1] = 1; //fibo(1)
	memo[2] = 2; //fibo(2)
	for (int i = 3; i <= n; i++) {
		/* 차근차근 아래의 작은 문제부터 푼다.*/
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	return memo[n]; //구하려고 하는 fibo(n)
}

int main() {
	printf("%d\n", fibo(45));
	return 0;
}
```

### 3.4. DP VS Divide & Conquer
DP | Divide & Conquer
---|---
문제가 -1로 줄어듬 | 문제가 절반으로 줄어듬
결과가 여러 번 사용 | 결과가 한 번 사용
결과 재사용이 성능 향상됨 | 분할이 성능 향상됨

### 3.5. DP tip
중요한 것은 `점화식`을 세워야 한다. <br>
이 점화식을 이용해서 테이블을 차곡차곡 쌓아서 나중에 더 큰 문제를 해결하는 방식이기 때문이다. <br>
또한, 점화식을 이용해서 다음의 해를 구할 수 있다. <br>
그러나 다음의 해에서 알 수 없는 것은 변수를 추가적으로 둬서 `BruteForce` 방식으로 접근하는 법도 있다. <br>

## 4. Divide & Conquer (분할 정복)
`분할(Divide)`, `정복(Conquer)`, `통합(Combine)` 각 단계를 거쳐서 문제를 해결하는 기법이다. <br><br>
`분할(Divide)`은 해결할 문제를 여러 개의 작은 문제들로 나눈다. <br>
`정복(Conquer)`은 나눈 작은 문제들을 각각 해결한다.<br>
`통합(Combine)`은 각각 작은 문제들을 해결했으니, 그 해답들을 다시 합친다. <br>

* 분할 정복의 예시
	- 합병 정렬(Merge Sort)
	- 퀵 정렬(Quick Sort)
	- 거듭 제곱(Exponentiation)

![Divide&Conquer](https://t1.daumcdn.net/cfile/tistory/99FC283C5C5303501F)<br>
출처 : https://godgod732.tistory.com/3?category=659135 <br>

분할의 가장 이상적인 경우는 반반씩 나뉘는 것이다. <br>
이는 분할을 할 때마다 데이터의 크기가 절반으로 줄어드는 것을 의미한다. <br>


### 4.1. 거듭 제곱(Exponentiation)
일반적으로 2의 2승은 `2^2 = 2x2`를 의미한다. <br>
거듭 제곱 알고리즘을 단순하게 구현하면 다음과 같다. <br>
```cpp
int Power(int Base, int Exponent)
{
	int result = 1;
      
	if (Exponent == 0) return 1;
	if (Exponent == 1) return Base;
	if (Base == 0) return 1;

	for (int i = 0; i < Exponent; i++)
		result = result * Base;

	return result;
}
```
위의 알고리즘은 시간복잡도가 `O(N)`이 된다. Exponent에 따라서 결정되기 때문이다. <br>
이를 좀 더 빠르게 할 수 있도록 `분할 정복`기법을 이용해서 해결하면 다음과 같다. <br>
```cpp
int Power(int Base, int Exponent)
{
	if (Exponent == 0) return 1;
	if (Exponent == 1) return Base;
	if (Base == 0) return 1;
	
	if (Exponent % 2 == 0)
	{
		int temp = Power(Base, Exponent/2);
		return temp * temp;
	}
	else
	{
		int temp = Power(Base, (Exponent-1)/2);
		return temp * temp * Base;
	}
}
```
위의 알고리즘은 시간복잡도가 `O(logN)`이 된다. <br>
이유는 한 번 함수를 호출할 때, 구하려고 하는 문제가 두개씩 쪼개지기 때문이다. <br>
예를 들어서 `2^8`을 구한다고 가정하면 다음과 같다. <br>
`2^8 = 2x2x2x2x2x2x2x2` 이런식이면 8번을 곱해야지만 구할 수 있지만, <br>
`2^8 = 2^4 x 2^4 = (2^2 x 2^2) x (2^2 x 2^2) = (2x2) x (2x2) x (2x2) x (2x2)`으로 총 4번의 연산으로 구할 수 있게 된다.

## 5. 정렬 (Sorting)
컴퓨터 과학과 수학에서 정렬 알고리즘은 다음과 같이 정의한다. <br>
원소들을 번호순이나 사전 순서와 같이 일정한 순서대로 열거하는 알고리즘 기법이다. <br>

* 정렬 알고리즘 종류
	- 버블 정렬(Bubble Sort)
	- 선택 정렬(Selection Sort)
	- 삽입 정렬(Insertion Sort)
	- 병합 정렬(Merge Sort)
	- 힙 정렬(Heap Sort)
	- 퀵 정렬(Quick Sort)
	- 쉘 정렬(Shell Sort)
	-  정렬(Counting Sort)
	- 기수 정렬(Radix Sort)
	
### 5.1. 버블 정렬(Bubble Sort) 안정 정렬
두 인접한 원소를 검사하여 정렬하는 방법이다. <br>
시간 복잡도가 상당히 느리지만, 코드가 단순해서 자주 사용된다고 한다. <br>
원소의 이동이 거품이 수면으로 올라오는 듯한 모습을 보여주기 때문에 `버블`이라고 지어졌다. <br>

* 장점
	- 구현이 쉽다.
	
* 단점
	- 굉장히 비효율적이다.
	- 최악이든 최선이든 시간복잡도 `O(N^2)`을 가진다.
	
### 5.2. 선택 정렬(Selection Sort) 불안정 정렬
제자리 정렬 알고리즘 중 하나이다. <br>
주어진 리스트 중에서 최소값을 찾고, 그 값을 맨 앞에 위치한 값과 교체한다. <br>
맨 처음 위치를 뺀 나머지 리스트를 위와 같은 방법으로 반복한다. <br>

* 장점
	- 구현이 쉽다.
	- 많은 교환이 일어나야 하는 자료상태에서 효율적으로 사용할 수 있다.
	- 실제로 교환되는 횟수가 `버블 정렬`보다 적다.
	- 그래서, `버블 정렬`보다는 조금 더 빠른 정렬 기법이다.
* 단점
	- 역시 시간복잡도 `O(N^2)`를 가진다.
	- 데이터의 양이 많을수록 오래걸리는 알고리즘이다.
	
### 5.3. 삽입 정렬(Insertion Sort) 안정 정렬
자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교해서, 자신의 위치를 찾아 삽입하는 정렬 기법이다. <br>
이미 `정렬된 부분`과 `정렬되지 않은 부분`으로 나뉜다. <br>

* 장점
	- Best Case의 경우에 `O(N)`이라는 시간복잡도를 가진다.
	- 성능이 좋아서 다른 정렬 알고리즘의 일부로 사용되기도 한다.
* 단점
	- Worst Case의 경우 `O(N^2)`이라는 시간복잡도를 가진다.
	- 데이터의 양에 따라서 성능의 편차가 심한 정렬 기법이다.
	
### 5.4. 병합 정렬(Merge Sort, 합병 정렬) 안정 정렬
이 정렬은 `안정 정렬`에 속하며, `분할 정복`알고리즘 중 하나이다. <br>
분할 정복 기법을 사용한 대표적인 방법이다. <br>

* 장점
	- 주어진 배열을 반씩 분할해가면서 정렬하는 기법으로 기존 정렬보다는 훨씬 빠르다.
	- 전체 시간복잡도는 `O(NlogN)`이며, 분할하는 과정의 시간복잡도는 `O(logN)`이다.
	- `퀵 정렬`(Pivot에 따라서 성능이 달라짐)과 달리 무조건 반씩 쪼개므로 항상 `O(NlogN)`이라는 시간복잡도를 가지게 된다.
* 단점
	- 추가적인 메모리가 필요하다. (병합 정렬은 임시배열에 주어진 배열을 계속해서 옮겨주면서 정렬하므로)
	- `O(N^2)`이 걸리는 정렬 기법에 비해서 구현 복잡도가 어렵다.
	
### 5.5. 힙 정렬(Heap Sort) 불안정 정렬
최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법이다. 여기에서는 `힙(Heap)` 자료구조를 기반으로 한다. <br>
`내림차순`으로 정렬을 위해서는 `Max-Heap`을 구성한다. <br>
`오름차순`으로 정렬을 위해서는 `Min-Heap`을 구성한다. <br>

* 장점
	- 추가적인 메모리를 사용하지 않으면서 `O(NlogN)`이라는 시간복잡도를 가진다.
	- 효율적인 정렬 기법이다.
* 단점
	- 실제 시간으로 측정하면 `병합 정렬`과 `퀵 정렬`에 비해서 느리다고 한다.
	
* 다만 `힙(Heap)` 자체의 장점을 가지고 있다.
	- 가장 크거나 작은 값을 구할 때 유용하다.
	
### 5.6. 퀵 정렬(Quick Sort) 불안정 정렬
다른 원소와의 비교만으로 정렬을 수행하는 `비교 정렬`에 속한다. <br>
`합병 정렬`과 비슷하게 주어진 배열을 분할하고, 각각을 정렬하는 방법이다. <br>
분할할 때, `피벗(Pivot)`을 기준으로 이보다 작은 것은 왼편으로, 큰 것은 오른편에 위치시키면서 정렬한다. <br>
`피벗(Pivot)`을 설정하는 기준에 따라서 알고리즘의 성능차가 있다. <br>
가장 좋은 성능을 내는 방법은 리스트 내에서 크기순으로 `중간 값(medium)`을 피벗으로 선택하는 방법이다. <br>

* 장점
	- 속도가 빠르다. (이름부터가 퀵이다.)
	- 시간복잡도 `O(NlogN)`을 가지면서 다른 정렬 알고리즘과 비교했을 때도 가장 빠르다.
	- 추가적인 메모리 공간을 사용하지 않는다.
* 단점
	- 정렬된 리스트에 대해서는 퀵 정렬의 불균형 분할에 의해서 오히려 더 수행시간이 오래 걸린다.
	- Worst Case의 경우 시간복잡도는 `O(N^2)`을 가지게 된다.

** 퀵 정렬 알고리즘 **
```cpp
void quickSort(int a[], int begin, int end)
{
	if (begin < end)
	{
		int p = partition(a, begin, end);
		quickSort(a, begin, p - 1);
		quickSort(a, p + 1, end);
	}
}
```
** 파티션 부분** 
```cpp
int partition(int a[], int begin, int end)
{
	int pivot = (begin + end) / 2; // 피벗을 잘 선택해야 알고리즘의 성능이 향상으로 이어진다.
	int l = begin;
	int r = end;
	
	while(l < r)
	{
		while(a[l] < a[pivot] && l < r) // pivot이 가리키는 값보다 큰 값을 찾는 l
			l++;
		while(a[r] >= a[pivot] && l < r) // pivot보다 작거나 같은 값을 찾는 r
			r--;
			
		if(l < r)
		{
			if(l == pivot)
				pivot = r;
			
			swap(a[l], a[r]);
		}
	}
	swap(a[pivot], a[r]);
	return r;
}
```

데이터의 중간을 기준으로 pivot을 잡으면 아래와 같은 순서로 정렬이 이루어진다. <br>
![middle_pivot](https://miro.medium.com/max/272/1*QWVKm7o7aSWJCSQ4Z_5Kag.png) <br>
출처 : https://medium.com/quantum-ant <br>

#### 5.6.1 퀵 정렬 vs 합병 정렬
* 공통점
	- 주어진 배열을 두 개로 분할하고, 각각을 정렬한다.
* 차이점
	- 합병 정렬은 분할할 때, 단순히 두 부분으로 나눈다.
	- 퀵 정렬은 Pivot을 기준으로 작은 것은 왼쪽에, 큰 것은 오른쪽에 둔다.
	- 합병 정렬은 각 부분의 정렬이 끝난 후에 `Merge`라는 과정이 있지만, 퀵 정렬은 각 부분의 정렬이 끝나면 후 처리 작업이 없다.
	


### 5.7. 쉘 정렬(Shell Sort)
`삽입 정렬`을 보완한 알고리즘이다. <br>
삽입 정렬이 어느 정도 정렬된 배열에 대해서는 대단히 빠른 것을 착안하여 만든 기법이다. <br>

삽입 정렬의 문제점은 요소를 삽입할 때, 이웃한 위치로 한 칸씩만 이동한다는 점이다. <br>
쉘 정렬에서는 요소들이 멀리 떨어진 위치로 이동할 수 있다는 장점을 가진다. <br>
이런 것이 가능한 이유는 쉘 정렬은 전체의 배열을 한 번에 정렬하지 않는다는 점이다. <br><br>

먼저 정렬해야 할 배열을 일정한 기준에 따라 분류해서 연속적이지 않은 여러 개의 부분 배열을 만들고, 각 부분 배열을 삽입 정렬을 이용해서 정렬한다. <br>
실제로는 `간격(Gap)`으로 간격을 주어 부분 배열이 만들어진 것처럼 구현한다. 모든 부분 배열이 정렬이 된다면 다시 전체 배열을 더 적은 개수의 부분 배열로 만든 후에 이를 반복한다. 이러한 과정은 부분 배열의 개수가 1이 될 때까지 반복한다.


* 장점
	- `삽입 정렬`의 단점을 보완해서 만든 정렬법으로 더 뛰어난 성능을 가진다.
	- Average case의 경우 `O(N^1.5)`의 성능을 지닌다.
* 단점
	- 일정한 간격에 따라서 배열을 바라봐야 한다.
	- `간격(Gap)`을 잘못 설정하면 성능이 나뻐질 수 있다.
	- Worst case의 경우 `O(N^2)`의 성능을 지닌다.

** 구체적인 구현을 위한 개념**
1. 정렬해야 할 리스트의 각 k번째 요소를 추출해서 부분 리스트를 만든다. 이때, k를 `간격(Gap)`이라고 한다.
	- 간격의 초깃값은 `(정렬할 값의 수) / 2
	- 생성된 부분 리스트의 개수는 `gap`과 같다.
2. 각 회전마다 간격 k를 절반으로 줄인다.
	- 간격은 홀수로 하는 것이 좋다고 한다.
	- 만약에 짝수가 나오면 +1을 해서 홀수로 만든다.
3. 간격 k가 1이 될 때까지 반복한다.

![shell](https://gmlwjd9405.github.io/images/algorithm-shell-sort/shell-sort.png) <br>
출처 : https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html <br>

### 5.8. 계수 정렬(Counting Sort)
작은 정수인 키에 따라 객체 모음을 정렬하는 알고리즘이다. <br>

* 장점
	- `O(N)`이라는 시간복잡도를 가지면서, 엄청나게 빠른 정렬 기법이다.
	- 조건에만 맞는다면, 기존에 `퀵 정렬`보다 더 빠른 정렬이다.
* 단점
	- 추가적인 메모리가 필요하다. 생각보다 많은 메모리를 소비한다.
	- 데이터의 양이 N이면 N의 메모리가 필요하다.
	- 안 쓰는 메모리가 존재한다. (즉, 일부 값을 위해서 메모리의 낭비가 심해진다.)

### 5.9. 기수 정렬(Radix Sort)
낮은 자리수부터 비교하여 정렬해 가는 기법이다. <br>

* 장점
	- `계수 정렬`과 같은 시간복잡도 `O(N)`을 가진다.
	- 조건에만 맞는다면, 기존에 `퀵 정렬`보다 더 빠른 정렬이다.
* 단점
	- `버킷`이라는 추가적인 메모리가 필요하다.
	- 데이터 타입이 같아야만 가능하다.
	- 구현을 위한 조건이 굉장히 많이 있으므로 많이 사용하지 않는다고 한다.

![Radix](https://t1.daumcdn.net/cfile/tistory/99792B495A6EDBD631) <br>


출처 : https://sexycoder.tistory.com/74

## 6. Queue
* Queue의 특징
	- 삽입, 삭제의 위치가 제한적인 자료구조 (큐는 뒤에서 삽입하고, 앞에서는 빼는 자료구조)
	- `선입선출구조`(FIFO, First In First Out)
	- 실생활에서 보통 먼저 온 사람부터 서비스를 받고 나가는 형태가 있다.
	- 보통 앞 부분(머리)를 `front`라고 하고, 뒷 부분(꼬리)를 `rear`이라고 한다.

* Queue의 연산들

연산 | 기능
---|---
enQueue(item) | Queue의 뒤쪽에 rear 다음에 원소를 삽입
deQueue() | Queue의 앞쪽에서 원소를 삭제하고 반환
createQueue() | Queue를 생성
isEmpty() | Queue가 공백상태인지를 확인
isFull() | Queue가 꽉찬상태인지를 확인
Qpeek() | Queue의 앞쪽에서 원소를 삭제하지 않고 확인해서 반환

* Queue의 종류들

이름 | 특징
---|---
선형큐 | 배열을 사용해서 구현한 큐
환영큐(원형큐) | 기존의 선형큐의 단점을 보완하고자 만든 큐
연결큐 | 리스트를 이용하여 구현한 큐
우선순위 큐 | `Heap` 자료구조를 이용한 큐

### 6.1 선형 큐(Linear Queue)

* 선형 큐의 특징
	- 1차원 배열을 이용한 Queue이다.
	- 초기 상태 : `front = rear = -1`
	- 공백 상태 : `front = rear`
	- 포화 상태 : `rear = n - 1 ( n : 배열의 크기 )`

* 선형 큐의 구현과정
1. createQueue()<br><br>
	크기가 n인 1차원 배열을 생성하고, front와 rear를 -1로 초기화 시킨다.
	
2. enQuene(item) <br><br>
	rear를 1증가 시킨 후, 그 자리에 새로운 원소를 삽입한다.
	```cpp
	enQueue(item)
	{
		if(isFull()) then return;
		else
		{
			rear <- rear + 1;
			Q[rear] <- item;
		}
	}
	end enQueue()
	```
	
3. deQueue() <br><br>
	front를 1증가 시킨 후, 그 자리에 있는 원소를 반환한다. <br>
	원래라면, 반환하고 삭제이지만 여기서는 첫 번째 원소를 반환한다는 점에서 삭제와 동일시 여긴다. <br>
	```cpp
	deQueue()
	{
		if(isEmpty()) then return;
		else
		{
			front <- front + 1;
			return Q[front];
		}
	}
	end deQueue()
	```
	
4. isEmpty(), isFull() <br><br>
	공백 상태를 검사하는 `isEmpty()`와 포화 상태를 검사하는 `isFull()` <br>
	`front = rear`이면 공백이고, `rear = n - 1`이면 포화상태이다. <br>
	```cpp
	isEmpty()
	{
		if(front == rear) return true;
		else return false;
	}
	end isEmpty()
	```
	```cpp
	isFull()
	{
		if(rear == n - 1) return true;
		else return false;
	}
	end isFull()
	```

5. Qpeek() <br><br>
	가장 앞에 있는 원소를 삭제하지 않고 반환하는 연산이다. <br>
	```cpp
	Qpeek()
	{
		if(isEmpty()) return;
		else return Q[front+1];
	}
	end Qpeek()
	```
* 선형 큐의 문제점은 꽉차있지도 않은데 꽉찼다고 인식하는 것이다.
	- `rear = n - 1`인 상태이지만, 배열의 앞부분에는 활용 공간이 남아있는 상태
	- 이런 경우는 더 이상의 삽입을 수행하지 못한다.
	<br>
* 선형 큐의 해결방안
	- 1차원 배열은 사용하면서, 논리적으로는 배열의 처음과 끝이 연결되어 있는 원형 큐로 가정하고 사용하는 것이다.

### 6.2. 원형 큐(Circular Queue)
* 원형 큐의 특징
	- 초기 공백 상태 : `front = rear = 0`
	- index가 순환할 수 있도록 `mod`연산을 활용한다. (계속 인덱스는 돌아야하기 때문에)
	- front변수는 `공백 상태`와 `포화 상태`를 구분을 쉽게하기 위해서 front가 가리키는 자리는 사용하지 않고 빈자리로 둔다.
	- 선형 큐에서는 삽입과 삭제할 때, rear와 front를 각각 1씩 증가시켰다.
	- 원형 큐에서는 삽입과 삭제할 때, rear와 front를 각각 1씩 증가시킨 후에 `mod`연산을 활용한다.
	
* 원형 큐의 구현
1. createQueue()<br><br>
	크기가 n인 1차원 배열을 생성하고, <br>
	front = rear = 0으로 초기화 한다. <br>
2. isEmpty(), isFull()<br><br>
	 공백 상태 : `front = rear`
	 포화 상태 : `삽입할 rear의 다음 위치 = front`
	 ```cpp
	 isEmpty()
	 {
	 	if(front == rear) return true;
		else return false;
	 }
	 end isEmpty()
	 ```
	 ```cpp
	 isFull()
	 {
	 	if((rear+1) mod n == front) return true;
		else return false;
	 }
	 end isFull()
	 ```
3. enQueue(item)<br><br>
	기존의 선형 큐와 마찬가지로 rear를 1증가 시킨다. <br>
	다만 여기서 `mod`연산을 이용해서 넣어줘야 한다. <br>
	```cpp
	enQueue(item)
	{
		if(isFull()) return false;
		else
		{
			rear <- (rear + 1) mod n;
			cQ[rear] <- item;
		}
	}
	end enQueue()
	```
4. deQueue()<br><br>
	 기존의 선형 큐와 마찬가지로 front를 1증가 시킨다. <br>
	 다만 여기서 `mod`연산을 이용해서 반환해줘야 한다. <br>
	 ```cpp
	 deQueue()
	 {
	 	if(isEmpty()) return;
		else
		{
			front <- (front + 1) mod n;
			return cQ[front];
		}
	 }
	 end deQueue()
	 ```
* 원형 큐의 문제점은 배열의 길이가 정해지면 바꿀 수 없다는 것이다.
	- 배열의 가장 큰 문제점은 정적이다.
	- 더 많은 원소를 넣고 싶으면 새로 만들어서 복사하는 비용이 발생하게 된다.
	- 그래서 한 번에 어느정도의 크기를 예상하고 만들어서 사용해야 한다는 점이 있다.
	<br>
* 원형 큐의 해결방안
	- 연결 큐를 이용하자.

### 6.3. 연결 큐(Linked Queue)
* 연결 큐의 특징
	- `Single Linked List`를 이용한 큐 구현이다.
	- 여기서의 큐의 원소는 하나의 `node`가 된다.
	- 원소의 순서는 `node`와 `node`가 서로 `연결(link)`되어 있다.
	- front는 첫 번째 노드를 가리키는 링크
	- rear는 마지막 노드를 가리키는 링크
	- 초기 상태는 `front = rear = NULL`
	- 공백 상태는 `front = rear = NULL`
	- 동적이다.

* 연결 큐의 구현
1. createLinkedQueue()<br><br>
	```cpp
	createLinkedQueue()
	{
		front <- NULL;
		rear  <- NULL;
	}
	end createLinkedQueue()
	```
2. isEmpty()<br><br>
	선형 큐와 원형 큐에 있었던 포화 상태를 체크해주는 `isFull()`은 연결 큐에서는 없어도 된다. <br>
	그 이유는 연결 큐에서는 포화가 발생할 수 없기 때문이다. (동적으로 늘어나기 때문에) <br>
	공백 상태 검사는 `front = rear = NULL`이다.
	```cpp
	isEmpty()
	{
		if(front == NULL) return true; // 둘 중 하나만 검사해줘도 된다.
		else return false;
	}
	end isEmpty()
	```
3. enQueue(item)<br><br>
	새로운 원소를 삽입하기 전에, 새로운 노드를 하나 생성하고 데이터 필드에 item을 저장한다. <br>
	그런 다음에 큐가 공백이면 그 노드를 front와 rear로 지정하고, 아니라면 rear의 next로 붙여 넣는다. <br>
	 
	```cpp
	enQueue(item)
	{
		new <- getNode(); // 보통 malloc을 이용해서 만든다.
		new.data <- item;
		new.link <- NULL;
		if(front == NULL)
		{
			// 큐가 비어있다는 것이므로
			rear  <- new;
			front <- new;
		}
		else
		{
			rear.next <- new;
			rear <- new;
		}
	 }
	 end enQueue()
	 ```
4. deQueue()<br><br>
	`old`가 삭제할 노드를 가리키게 한다. <br>
	반환할 `item`을 위해서 `front.data`를 저장해준다. <br>
	`front`를 하나 뒤로 이동시킨다. <br>
	만약에 삭제한 후에 큐가 공백이 되어버리면 `rear`도 NULL로 설정한다. <br>
	`메모리 누수(Memory Leak)`를 방지하기 위해서 `old`의 할당을 `해제(free)`해버린다. <br>
	```cpp
	deQueue()
	{
		if(isEmpty()) return;
		else
		{
			old <- front;
			item <- front.data;
			front <- front.next;
			if(isEmpty()) rear <- NULL;
			free(old);
			return item;
		}
	}
	end deQueue()
	```

### 6.4. 우선순위 큐(Priority Queue)
우선순위를 가진 항목들을 저장하는 큐의 형태로, 기존의 `FIFO`형태가 아닌 우선순위가 높은 순서대로 먼저 빠져나오는 구조이다. <br>

* 우선순위 큐를 활용하는 형태는 다음과 같다.
	- 시뮬레이션 시스템
	- 네트워크 트래픽 제어
	- 운영체제의 태스크 스케줄링(스케줄링 큐)
	- 우선순위를 부여해서 보관해야할 때
	- Max나 Min을 한 번에 찾는 방법
	
	
* 우선순위 큐의 구현 방법
	- 배열
	- 연결 리스트
	- Heap 자료구조 이용
	- 삽입 : 기존의 큐처럼 삽입은 `enQueue`이지만 삽입되면서 우선순위를 기준으로 제 자리를 찾아서 삽입된다.
	- 삭제 : 우선순위 큐의 가장 앞에 있는 우선순위가 가장 높은 항목이 빠져나오게 되고 삭제된다.

1. **배열을 이용**
	- 배열을 이용해서 자료를 저장한다.
	- 원소를 삽입하는 과정에서 우선순위를 비교하면서 적절한 위치에 삽입한다.
	- 우선순위 큐의 특징상 가장 앞에 원소는 우선순위가 가장 높다.

**배열의 문제점** 
단, 배열을 이용하면 배열의 특징인 삽입이나 삭제 연산이 일어날 때 데이터의 이동이 빈번하다. <br>
또 시간복잡도가 데이터의 양이 많을수록 불리하며, 메모리의 낭비가 크다. 그리고 정적인 것도 단점이다. <br>

2. **연결 리스트를 이용**
	- 리스트를 이용해서 자료를 저장한다.
	- 리스트의 장점인 삽입, 삭제는 단순히 링크 형태만 바꿔주면 되기 때문에 좋다.
	- 우선순위 큐의 특징상 가장 앞에 원소는 우선순위가 가장 높다.
	
**리스트의 문제점** 
어느정도 배열의 문제를 해결했다고는 하지만, 삽입이나 삭제를 할 때 기존에 저장된 우선순위를 하나씩 비교하면서 새로 삽입될 위치를 찾아야하는 번거로움이 존재한다. 그래서 비교하는 연산이 데이터의 양이 많을수록 역시나 불리하다.<br>

3. **Heap 자료구조 이용**
	- Heap 자료구조를 이용해서 자료를 저장한다.
	- 기존의 배열과 리스트에서 존재했던 원소를 삽입하는 과정에서의 문제점을 해결할 수 있다.
	- 삽입할 때 원소의 우선순위 비교를  `O(logN)`만 확인하면 삽입될 위치를 찾을 수 있다.
	- 마찬가지로 우선순위 큐의 특징상 가장 앞에 원소는 우선순위가 가장 높다.

### 6.5. 버퍼 (큐의 활용)
데이터를 한 곳에서 다른 한 곳으로 전송하는 동안 일시적으로 그 데이터를 보관하는 메모리 영역이다. <br>
`버퍼링`은 버퍼를 활용하는 방식으로 버퍼를 채우는 동작을 의미한다. <br><br>
보통 버퍼의 활용의 예는 입출력에서 자주 일어난다. <br>
1. 사용자가 키보드로 입력을 한다.
2. 키보드 입력 버퍼에 문자열이 쌓이게 된다.
3. 키보드 입력 버퍼에서 `Enter키`가 들어오게 되면 해당 데이터를 프로그램 실행 영역으로 옮긴다.
4. 이를 가지고 연산한다.

### 6.6. BFS(Breadth First Search, 너비 우선 탐색)
그래프의 알고리즘 중 하나로, 자료구조 `Queue`를 이용한다. <br>

* 동작 방식
	- 시작점의 인접한 정점들을 모두 차례로 방문한 후 방문했던 정점을 시작점으로 하여 다시 인접한 정점들을 차례로 방문한다.
	- 여기서 한 정점을 기준으로 인접해 있는 모든 정점들을 차례로 너비 우선 탐색을 진행해야 하므로 `Queue`가 이용된다.
	- 더 자세한 내용은 따로 분류해서 작성한다.

## 7. List (리스트)
* 리스트의 특징들
	- 자료를 순서대로 한 줄로 저장하는 자료구조
	- 제일 처음 데이터를 보통 Head가 가리킨다.
	- 제일 마지막 데이터를 보통 Tail이 가리킨다. (Tail을 구현하면, 성능 향상에 도움이 된다.)
	- 빈틈없는 데이터의 적재가 가능하다.

* list의 구현 방식
	- ArrayList : 배열을 기반으로 구현된 list
	- LinkedList : 메모리의 동적할당을 기반으로 구현된 list

* list의 주요 함수

함수명 | 기능
--- | ---
addtoFirst() | list의 앞쪽에 원소를 추가하는 연산
addtoLast() | list의 뒤쪽에 원소를 추가하는 연산
add() | list의 특정 위치에 원소를 추가하는 연산
delete() | list의 특정 위치에 있는 원소를 삭제하는 연산
get() | list의 특정 위치에 있는 원소를 반환하는 연산


### 7.1. ArrayList (순차 리스트)
![ArrayList](https://t1.daumcdn.net/cfile/tistory/227EE9505639FDBC2B) <br>
출처 : https://robodream.tistory.com/170

**사용해야할 자료구조는 배열을 이용하자** <br>
	- 구현 방법은 1차원 배열을 이용해서 항목들을 순서대로 저장한다. <br>
	- 필요에 따라서 구조체를 만들어서 저장할 수도 있다. <br>
	
**접근방법** <br>
	- 배열의 인덱스를 이용해서 원하는 위치에 접근할 수 있다. <br>
	- 랜덤 액세스가 가능하므로 빠르게 `O(1)`에 접근이 가능하다. <br>

**삽입 연산** <br>
	- 삽입 위치의 다음의 항목들을 먼저 이동시킨다. <br>
	- 이동을 완료한 후에 새로운 원소를 삽입한다. <br>
	- 단, 이동할 때에는 가장 바깥쪽부터 이동한다. <br>
	- 삽입 연산의 경우는 `O(N)`이 걸린다. <br>
**삭제 연산** <br>
	- 삭제 위치 다음의 항목들을 이동해야한다. <br>
	- 단, 이동할 때는 삭제 위치의 가까운 곳부터 이동한다. <br>
	- 삭제 연산의 경우는 `O(N)`이 걸린다. <br>

**배열을 이용해서 list를 구현하면 생기는 단점들**
1. 자료의 삽입/삭제 연산 과정에서 배열의 단점이 있다. (데이터의 이동이 빈번하다.)
2. 원소의 개수가 많고 삽입/삭제 연산이 빈번하게 일어날수록 시간이 크게 증가한다.
3. 배열의 크기는 정적이므로, 이보다 적게 사용하면 메모리 낭비 혹은 메모리 초과가 발생한다.

### 7.2. LinkedList (연결 리스트)
위에서 배열 기반의 리스트를 보완한 것이 바로 연결 리스트이다. <br>
조금 더 유연하게 사용이 가능하다. <br>
1. 자료의 논리적인 순서가 메모리 상의 물리적인 순서와 일치하지 않는다는 것이다. (원소를 이동시키는 작업이 없다.)
2. 항상 물리적인 순서에 맞게 연산을 하지 않아도 된다. (링크의 연결만 바꿔주면 삽입/삭제가 빠르게 완료된다.)
3. 리스트의 크기는 동적이므로, 메모리의 효율적인 사용이 가능하다.
4. 다만 배열의 구현보다 어렵고, 버그가 일어날 수 있다.

**연결 리스트에서는 다음과 같은 개념을 가지고 있다** <br>
* 노드(Node)
	- `데이터의 필드`와 `링크 필드`를 가지고 있다. (data, link)
	- `데이터 필드`는 원소의 값을 저장한다. 필요에 따라서는 구조체가 저장될 수도 있다.
	- `링크 필드`에는 다음 노드의 주소를 저장한다.
* 헤드(Head)
	- list에서 처음 노드를 가리킨다.
	- `헤드`를 이용해서 다양한 연산들을 활용할 수 있다. (순회, 삽입, 삭제 등등..)

* 리스트는 다양한 종류를 가지고 있다.
	- 단순 연결 리스트 (Single Linked List)
		+ 한 방향으로 순회가 가능한 리스트
		+ `헤드`가 가장 앞의 노드를 가리킨다.
		+ 가장 마지막 노드의 다음은 `NULL`을 가리킨다.
		+ ![list1](https://t1.daumcdn.net/cfile/tistory/991EA73A5D4911250C)
		+ 출처 : https://xzio.tistory.com/295
	- 이중 연결 리스트 (Double Linked List)
		+ 후행 노드뿐만 아니라, 선행 노드를 참조하는 링크필드를 만들어서 양방향으로 순회가 가능한 리스트
		+ ![list2](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2949.png)
		+ 출처 : https://opentutorials.org/module/1335/8940
	- 원형 연결 리스트 (Circular Linked List)
		+ 마지막 노드가 첫 번째 노드와 연결되어 있는 리스트
		+ ![list3](https://t1.daumcdn.net/cfile/tistory/22793044534C1A3C03)
		+ 출처 : https://supark7.tistory.com
	- 이중 원형 연결 리스트 (Doubly Circular Linked List)
		+ 이중 연결 리스트에서 next와 prev링크가 연결되어 있는 리스트
		+ ![list4](https://t1.daumcdn.net/cfile/tistory/99C296465C52D2DA10)
		+ 출처 : https://aerocode.net/181
		
* 단순 연결 리스트의 연산들
	- 삽입 연산
	- 삭제 연산
* 삽입 연산
	- 1. 새로운 메모리(노드)를 할당한다.
	- 2. 새로운 노드에 데이터 필드와 링크 필드를 저장한다.
	- 3. 삽입될 위치의 바로 앞에 위치한 노드의 링크 필드를 new의 링크 필드에 복사한다.
	- 4. new의 주소를 앞 노드의 링크 필드에 저장한다.
	- List의 처음 위치에 노드를 삽입하는 방법
	```cpp
	addtoFirst(L, i) // List 포인터 L, 원소 i
	{
		new <- createNode(); // 새로운 노드 생성
		new.data = i;        // 데이터 필드
		new.link = L;        // 링크 필드
		L = new;             // list의 처음으로 저장
	}
	end addtoFirst()
	```
	- List의 임의의 위치에 노드를 삽압하는 방법
	- 여기서의 pre는 삽입될 위치의 전 노드를 말한다.
	```cpp
	add(L, pre, i) // List 포인터 L, 노드 pre, 원소 i
	{
		new <- createNode();
		new.data = i;
		if( L == NULL )
		{
			L = new;
			new.link = NULL;
		}
		else
		{
			new.link = pre.link;
			pre.link = new;
		}
	}
	end add()
	```
	- List의 마지막에 노드를 삽입하는 방법
	```cpp
	addtoLast(L, i)
	{
		new <- createNode();
		new.data = i;
		new.link = NULL;
		if( L == NULL )
		{
			L = new;
			return;
		}
		temp = L;  // temp라는 포인터를 이용해서 List를 순회한다.
		while(temp.link != NULL) // 마지막 노드를 찾을 때 까지 이동한다.
			temp = temp.link;
		temp.link = new; // 마지막 노드 추가
	}
	end addtoLast()
	```
* 삭제 연산
	- 1. 삭제할 노드의 앞 노드(선행 노드) 탐색한다.
	- 2. 삭제할 노드의 링크 필드를 선행노드의 링크 필드에 복사한다.
	- 3. 삭제할 노드를 할당 해제한다.
	- 노드 pre의 다음 위치에 있는 노드를 삭제하는 방법
	```cpp
	delete(L, pre)
	{
		if( L == NULL )
			return;
		else
		{
			target = pre.link; // 삭제할 노드를 지정
			if(target == NULL)
				return;
			pre.link = target.link;
		}
		free(target); // 할당된 메모리 반납
	}
	end delete()
	```
* 이중 연결 리스트의 연산들
	- 두 개의 링크 필드와 한 개의 데이터 필드로 구성된다.
	- 보통 pre 링크 필드와, next 링크 필드, data 데이터 필드로 구성된다.
	- 삽입 연산
	- 삭제 연산
* 삽입 연산
	- 이중 연결 리스트에서는 순서가 중요하다.
	- cur가 가리키는 노드 다음으로 D값을 가진 노드를 삽입하는 과정을 보자.
	- 1. 메모리를 할당하여 새로운 노드 new를 생성하고 데이터 필드에 D값을 저장한다.
	```cpp
	new <- createNode();
	new.data = 'D';
	```
	- 2. cur의 next를 new의 next에 저장한다.
	```cpp
	new.next <- cur.next;
	```
	- 3. cur의 next를 new로 가리키게 한다.
	```cpp
	cur.next <- new;
	```
	- 4. new의 prev가 cur를 가리키게 한다.
	```cpp
	new.prev <-  cur;
	```
	- 5. new의 next의 prev가 new를 가리키게 한다.
	```cpp
	new.next.prev <- new;
	```
* 삭제 연산
	- cur가 가리키는 노드를 삭제하는 과정을 알아보자.
	- `prev`노드, `cur`노드, `next노드`가 일렬로 있다고 하자.
	- 1. 삭제할 노드의 다음 노드의 주소를 삭제할 노드의 이전 노드의 next 필드에 저장한다.
	```cpp
	prev.next <- cur.next;
	```
	- 2. 삭제할 노드의 다음 노드의 prev 필드에 삭제할 노드의 이전 노드의 주소를 저장한다.
	```cpp
	next.prev <- cur.prev;
	```
	- 3. cur가 가리키는 노드를 삭제하고, 할당된 메모리를 반환한다.
	```cpp
	free(cur)
	```
### 7.3. List를 이용한 Stack
1. stack 내의 순서는 list의 링크를 통해 연결된다.
2. `Push`는 list의 마지막에 노드 삽입
3. `Pop`은 list의 마지막 노드를 반환하고 삭제
4. `Top`은 list의 마지막 노드를 가리키는 변수이다.

* push 연산과 pop 연산
	- 1. stack을 만든다
	- 2. 원소 하나를 삽입한다. push(A)
	- 3. 원소 하나를 삭제한다. pop()
	```cpp
	push(i)
	{
		temp = createNode();
		temp.data = i;
		temp.link = top;
		top = temp;
	}
	end push()
	```
	```cpp
	pop()
	{
		element remove;
		stackNode* temp = top;
		
		if(top == NULL)
			return 0;
		else
		{
			remove = temp.data;
			top = temp.link;
			free(temp);
			return remove;
		}
	}
	```
### 7.4. 우선순위 큐 (Priority Queue)
* 구현 방식
	- 배열을 이용한 우선순위 큐
	- 리스트를 이용한 우선순위 큐
* 배열을 이용한 우선순위 큐 방식
	- 배열을 이용하여 자료를 저장
	- 원소를 삽입하는 과정에서 우선순위를 비교하여 적절한 위치에 삽입한다. (이 때 데이터의 이동이 반드시 일어남)
	- 가장 앞에 높은 우선순위의 원소가 위치하게 된다.
	- 문제는 정적이면서, 삽입/삭제 연산에서 빈번한 데이터의 이동이 시간이나 메모리 낭비가 크다.
* 리스트를 이용한 우선순위 큐 방식
	- 연결 리스트를 이용하여 자료를 저장
	- 원소를 삽입하는 과정에서 list 내의 노드들과 원소들을 비교해서 적절한 위치에 삽입한다. (이 때 데이터의 이동이 아닌 링크의 연결만 바꿈)
	- 가장 앞에 높은 우선순위의 원소가 위치하게 된다.
	- 배열에 비해 삽입/삭제 연산에서 데이터의 이동이 일어나지 않는다.
	- 메모리의 효율적인 사용이 가능하다. (유연성)
	

## 8. Tree (트리)
비선형 구조이며, 원소들 간의 `1 : n` 관계를 가지는 자료구조이다. 다른 말로 계층형 자료구조라고도 한다. <br>

### 8.1. Tree의 명칭들
![Tree](https://gmlwjd9405.github.io/images/data-structure-tree/tree-terms.png) <br>
출처 : https://gmlwjd9405.github.io/2018/08/12/data-structure-tree.html <br>

보통 트리는 `노드`와 `간선`으로 이루어져 있으며 `나무모양`을 띄고 있다. <br><br>

명칭 | 설명
---|---
루트노드 | 부모가 없는 노드, 트리는 단 하나의 루트 노드만 가짐
단말노드 | 자식이 없는 노드, 말단 노드 혹은 잎 노드로 불린다.
부모노드 | 자식의 부모가 부모노드이다.
자식노드 | 부모의 자식들이 자식노드이다.
서브트리(subTree) | 부모노드와 연결된 간선을 끊었을 때 생성되는 Tree
형제(Sibling) | 같은 부모를 가지는 노드
차수(degree) | 노드에 연결된 자식노드의 수
높이(height) | 루트 노드에서 노드에 이르는 간선의 수
레벨(Level) | 트리의 특정 깊이를 가지는 노드의 집합
트리의 차수 | 트리의 최대 차수를 말한다.
트리의 높이 | 트리의 최대 높이를 말한다.


## 9. Graph (그래프)
그래프는 `정점(Vertex)`와 `간선(Edge)`로 이루어진 자료구조이다. <br>
![graph](https://www.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png) <br>
출처 : https://www.geeksforgeeks.org/wp-content/uploads/undirectedgraph.png <br>

### 9.1. Path, UnDirected Graph, Directed Graph
그래프의 종류는 다양하다. <br>
보통 그래프가 주어지는 경우 방향성이 없는 `UnDirected Graph`와 방향성이 있는 `Directed Graph`가 있다.
![Graph](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMTgx/MDAxNDg1ODQzNTQ4NTgz.nh0nifj5nlyy2jx7fer2oCErJLBPlTTWh_E7UpyGf1cg.-mKQRyyDUzyHWGrRziXyi7Ptosd-kBqWhJTqt7sbNFQg.JPEG.occidere/image_6319709181485828897310.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220923695595 <br>
그리고 `Path`는 경로를 뜻하며, 내가 어디에서 어디로 왔는지를 보여주는 일련의 과정들이다. <br>
경로들 중에서 더 빠른 경로를 `최단 경로(Shortest Path)`라고 하며, 이를 구하는 알고리즘은 `다익스트라(Dijkstra)`와 `플로이드 와샬(Floyd Washall)` 알고리즘이 있다. <br>

### 9.2. Cycle
하나의 정점으로 시작해서 끝나는 정점이 같다면? 그것을 우리는 `Cycle(사이클)`이라고 한다. <br>
예를 들면) `A -> C -> D -> E -> B -> A` (A의 정점에서 시작해서 도착도 A의 정점으로 끝나는 그래프) <br>
자기 자신의 정점에서 자기 자신으로 끝나는 것도 해당한다. `A -> A`<br>
![Cycle](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMjdfMjYy/MDAxNDg1NTIzODc3NzIx.CN9J8Vp3u91LkZynrljXfOvvZf1Ch7gvAU0dyNfNuaMg.ZPQVYG1Kqzdg4HEE1sN6b4f_AdmzGKNth17o5PeecMUg.JPEG.occidere/image_1779474731485523735508.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220921661731 <br>
위의 그림은 방향은 있으면서도 `Cycle`이 존재하지 않는 그래프를 `DAG(Directed Acyclic Graph)`라고 한다. <br>
`DAG`의 유무는 `위상 정렬(Topological Sort)` 알고리즘을 사용할 때 이용한다. <br>

### 9.3. Weight
그래프 중에서는 간선 마다 `Weight(가중치)`가 붙어있는 그래프가 있다. <br>
이러한 간선은 A -> B로 간다고 했을 때 10의 의미는 그 때의 비용이 든다고 할 수 있다. <br>
보통 간선의 비용을 중요하게 여기는 알고리즘은 `다익스트라(Dijkstra)`와 `플로이드 와샬(Floyd Washall)` 알고리즘이 있다. <br>
![Weight](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMTcy/MDAxNDg1ODQzNjMzMTA5.vNinscdDoQT4sANCCH_Q3PrT3UMwSYjAum9ck0e1Iv0g.bSmfZRMhbgYCotbhD8ZnGv-pzpJUHyJN6yPjlLje3IMg.JPEG.occidere/image_6359776771485841053989.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220923695595 <br>

### 9.4. 그래프의 표현 방법
그래프를 표현하는 방법은 2가지가 있다. <br>
2차원 배열 형태를 이용한 `인접 행렬(Adjacency Matrix)` 과  <br>
리스트 형태를 이용한 `인접 리스트(Adjacency List)` 가 있다. <br>

#### 9.4.1. 인접 행렬(Adjacency Matrix)
모든 정점과 모든 정점 사이의 간선의 정보를 다 저장하는 형태이다. <br>

* 장점
	- 구현이 쉽고 직관적이다.
	- 한 정점에서 다른 정점이 연결되어 있는지 확인하는 시간이 `O(1)`이다.
	- graph[u][v]가 0이면 연결 X, 1이면 연결 O 형태이다.
	- `(Complete Graph)완전 그래프`에서는 `인접 행렬`이 `인접 리스트`보다 더 좋다.
	- `(Complete Graph)완전 그래프`는 그래프의 모든 정점 사이에 간선이 존재하는 그래프이다.
	- `(dense Graph)밀집 그래프`에서도 적합하다.
	- `(dense Graph)밀집 그래프`는 정점에 비해서 간선의 개수가 더 많은 그래프이다.
* 단점
	- 한 정점에서 인접한 정점을 찾을 때에는 `O(N)`이 걸린다.
	- 불필요한 정보의 저장이 많다.
	- 2차원 배열 형태를 유지하므로 N이 커지면 메모리의 사용량도 N^2이 된다.
	- 그래서 `Sparse Graph(희소 그래프)`에서는 성능이 좋지 못하다.
	- `Sparse Graph(희소 그래프)`는 정점이 간선의 개수보다 더 많은 그래프이다.
	
![Matrix](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMTAy/MDAxNDg1ODQzNTU5NTYw.emxOr6a5-YI-IqPFG4pMWFzylg-Y3aFc0gvD2bdxvXIg.HiAfnWGkn_4jH5d5O2MpKeGbU5_FNJr6lLebEdRTYS4g.JPEG.occidere/image_5867957401485829917305.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220923695595 <br>

#### 9.4.2. 인접 리스트(Adjacency List)
실제로 정점과 정점이 연결된 간선들의 정보만 저장하는 형태이다. <br>

* 장점
	- 한 정점에서 인접한 정점을 찾을 때에는 `O(E)`이 걸린다. (실제로 있는 간선의 정보만 저장하고 있기 때문에)
	- 보통 그래프 알고리즘(DFS, BFS)을 구현할 때 `인접 리스트`를 이용하면 시간을 단축시킬 수 있다.
	- 필요한 정보만 저장하므로 메모리 절약도 된다.
	- `Sparse Graph(희소 그래프)`에서는 좋은 성능을 보인다.
* 단점
	- `인접 행렬`에 비해서 구현이 어렵다.
	- 그래서 보통 CPP의 STL에서 `List`나 `vector`를 이용해서 구현한다.
	- `(Complete Graph)완전 그래프`의 경우 효율이 좋지 못하다.
	- `(dense Graph)밀집 그래프`의 경우도 효율이 좋지 못하다.

![list1](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMjM5/MDAxNDg1ODQzNTY5MzAx.LuvDUrY0ZNJDyT7sXSPtdvprIUxN5uRE8YJGbkPvmfcg.b6z71d7VkH75ByBGfXzJa_EfUAagKh1WwObjP9mJpU4g.JPEG.occidere/image_3029405931485831316448.jpg?type=w800) <br>

![list2](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMjkx/MDAxNDg1ODQzNTc5OTc5.SxJSDnBn9eS-q2T6IvifbmHaUjG84zKbhPnFszDoOKQg.abtanX15WZje27L_dNJyb8e8Lqlevd8YaDJ2DmsnCNYg.JPEG.occidere/image_1713515921485831634971.jpg?type=w800)<br>

출처 : https://m.blog.naver.com/occidere/220923695595 <br>

![list3](https://t1.daumcdn.net/cfile/tistory/265E074D584C26DD2B)<br>
출처 : https://sarah950716.tistory.com/12 <br>

### 9.5. 그래프 탐색 (Graph Search)
정점을 탐색하는 방법은 `DFS`와 `BFS`, `Dijkstra`와 `Floyd Washall`이 있다. <br>
서로 지향하는 목표가 다르다는 것이 핵심이다. <br>
`DFS`와 `BFS`는 **하나의 정점에서 시작해서 모든 정점을 1번씩 탐색하는 알고리즘이다.** <br>
`Dijkstra`는 **하나의 정점에서 모든 정점간의 최단 경로를 구해주는 알고리즘이다.** <br>
`Floyd Washall`은 **모든 정점에서 모든 정점간의 최단 경로를 다 구해주는 알고리즘이다.** <br><br>

**그래프에서의 탐색의 유형들**
![Search](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfODEg/MDAxNDg1ODQzNjU1NDQ0.Z2GhsS5VNR8oc1BCmOwuv3GO723QVPjVWYiels4N3Csg.4WLB5Niq4o4EqFOxNzp5opccFlOG4nIIRP-babdFFeIg.JPEG.occidere/image_4888565491485842708240.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220923695595 <br>

보통 그래프가 아닌 모양도 그래프로 취급하고 문제를 풀어야 하는 형태도 존재한다. <br>
그러한 경우 그래프를 이용해서 풀면 문제를 보다 쉽게 해결할 수 있는 시각이 생긴다. <br>

비교분석 |BFS | DFS | Dijkstra | Floyd Washall
---|---|---|---|---
탐색방법 | 하나의 정점에서 인접 정점들 탐색 | 하나의 정점을 선택하고 깊이 파고드는 탐색 | BFS + 최단경로 찾기 | 모든 정점 + 최단경로 찾기
자료구조 | Queue | Stack | Priority Queue | 3중 for문
특징 | 깊이가 깊은 그래프에서 좋다 | 넓이가 넓은 그래프에서 좋다 | 비교적 빠르게 최단경로 탐색 가능 | 모든 최단 경로를 구해줌(코드가 단순)
시간 복잡도 | 인접행렬 O(V^2)<br>인접리스트 O(V+E) | 인접행렬 O(V^2)<br>인접리스트 O(V+E) | Queue 구현 O(V^2)<br>우선순위 큐 사용 O(E+VlogV) | O(V^3)

출처 : https://m.blog.naver.com/occidere/220923695595

#### 9.5.1. DFS (Depth First Search, 깊이 우선 탐색)
현재 정점에서 연결된 정점을 하나 골라서 갈 수 있는 만큼 최대한 깊게 들어가면서 탐색하는 방법이다. <br>
여기서 `가지치기` 기술이 들어가게 되면 `Backtracking`이다. <br>
사용되는 자료구조는 `stack`이며, 스택을 이용해서 구현해도 되고 `recursive`를 이용해서 구현할 수도 있다. <br>
옆으로 넓은 그래프에 대해서는 준수한 성능을 보인다고 하고, 아래로 깊은 그래프의 경우는 좋은 성능을 보이기가 어렵다고 한다. <br>

![DFS](https://gmlwjd9405.github.io/images/algorithm-dfs-vs-bfs/dfs-example.png) <br>
출처 : https://gmlwjd9405.github.io/2018/08/14/algorithm-dfs.html <br>

보통 `DFS`를 구현할 때 `stack`을 이용해서 구현도 하지만, 가장 쉬운 방법은 `recursive` 방식을 이용해서 구현하는 방법이다. <br>

* **인접 행렬**을 이용해서 구현한 DFS
```cpp
void DFS(int x)
{
	visited[x] = true; // 방문했다고 표시
	cout << x << " ";
	for(int i = 1; i <= n; i++)
	{
		if(a[x][i] == 1 && visited[i] == false) // x -> i의 간선이 존재하고, 방문하지 않았다면
			DFS(x);   // 방문한다.
	}
}
```
	
	- 위의 구현결과의 시간복잡도는 O(V^2)이다.
	- 하나의 V는 DFS 함수를 실행하는 횟수 * for문 안에 1 ~ V까지 실행하는 횟수 = V^2가 나오게 된다.

* **인접 리스트**를 이용해서 구현한 DFS
```cpp
void DFS(int x)
{
	visited[x] = true; // 방문했다고 표시
	cout << x << " ";
	for(int i = 0; i < a[x].size(); i++)
	{
		int next = a[x][i]; // 다음 정점을 찾고
		if(visited[next] == false) // 방문하지 않았다면
			DFS(next);  // 방문한다.
	}
}
```
	- 위의 구현결과의 시간 복잡도는 O(V+E)이다.
	- 하나의 V는 DFS함수를 실행하는 횟수 + for문 안에는 실제 간선의 정보만 담고 있으므로 E = V+E가 나오게 된다.
	
* 인접 행렬과 인접 리스트의 차이
	- 두 구현은 메모리의 공간과 시간복잡도의 차이가 다르다.
	- 따라서, 상황에 맞게 적용하면 된다.

#### 9.5.2. BFS (Breadth First Search, 너비 우선 탐색)
현재 정점과 연결된 인접 정점들에 대해서 우선적으로 넓게 탐색하는 방법이다. <br>
자료구조는 `Queue`를 이용한다. <br>
아래로 깊은 그래프에 대해서는 좋은 성능을 기대할 수 있으나, 옆으로 넓은 그래프에 대해서는 탐색시간이 오래걸린다고 한다. <br>

![BFS](https://gmlwjd9405.github.io/images/algorithm-dfs-vs-bfs/bfs-example.png) <br>
출처 : https://gmlwjd9405.github.io/2018/08/15/algorithm-bfs.html <br>

* **인접 행렬**을 이용해서 구현한 BFS
```cpp
void BFS(int x)
{
	queue<int> q;      // 큐 생성
	q.push(x);         // 큐에 시작 지점 넣고
	visited[x] = true; // 방문했다고 체크
	while(!q.empty())
	{
		int cur = q.front();  // 큐에서 하나를 빼고
		q.pop();              // 삭제한다.
		cout << x << " ";
		for(int i = 1; i <= n; i++) // cur에서 인접한 정점들을 확인한다.
		{
			if(a[x][i] == 1 && visited[i] == false) // 간선이 존재하고, 방문하지 않았다면
			{
				visited[i] = true; // 방문해주고
				q.push(i); // 큐에 넣어준다.
			}
		}
	}
}
```
	- 위의 구현결과의 시간복잡도는 O(V^2)이다.
	- 중요한 것은 DFS와 BFS의 목적은 같다는 것이다. 그래서 시간복잡도 비슷하다.
* **인접 리스트**를 이용해서 구현한 BFS
```cpp
void BFS(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << x << " ";
		for(int i = 0; i < a[x].size(); i++)
		{
			int next = a[x][i];
			if(visited[next] == false) // 인접 리스트는 실제로 존재하는 간선만 넣기 때문에, 방문 여부만 체크
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}
```
	- 위의 구현결과의 시간복잡도는 O(V+E)이다.

* BFS의 추가적인 것들
	- 앞서 목적은 모든 정점을 1번씩만 방문한다는 것이다.
	- 그런데, `BFS`는 `최단 거리를 구하는 알고리즘`이기도 하다. (단, 조건부)
	- 조건부는 그래프에서의 `모든 가중치가 1일 때`이다.
	- 보통 `미로 탐색 유형(Flood Fill)`에서 사용된다.
	
![Flood](https://hyunjae-lee.github.io/assets/img/algorithm/ps/ff2.jpg) <br>
출처 : https://hyunjae-lee.github.io/hyunjae-lee.github.io/problem%20solving/DFSandBFS2/ <br>

#### 9.5.3. Dijkstra (다익스트라, 1-N)
`BFS`의 응용으로 하나의 정점에서 모든 정점까지의 최단 경로를 찾는데 사용하는 알고리즘이다. <br>
보통 영어로 `Single source Shortest path problem`라고 한다. <br>
이 알고리즘은 모든 간선이 모두 양의 간선들을 가져야 하는 조건부가 있다. <br>
매 탐색마다 해당 정점까지의 가중치의 합을 최소값으로 갱신시켜서 탐색하는 방식이다. <br>
사용하는 자료구조는 `Queue`를 사용하는 방법과 `우선순위 큐(Priority Queue)`를 사용해서 시간을 단축하는 방법이 있다. <br>

![Dijkstra](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMTcy/MDAxNDg1ODQzNjMzMTA5.vNinscdDoQT4sANCCH_Q3PrT3UMwSYjAum9ck0e1Iv0g.bSmfZRMhbgYCotbhD8ZnGv-pzpJUHyJN6yPjlLje3IMg.JPEG.occidere/image_6359776771485841053989.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220923695595 <br>

* 다익스트라 응용편
	- 실생활에 쓰이는 GPS
	- 네비게이션

* 다익스트라의 구현
	- `인접 리스트`에 `우선순위 큐`를 같이 사용해서 시간복잡도를 줄이는 방법으로 구현한다.
	```cpp
	vector<int> Dijkstra(int start)
	{
		vector<int> dist(N + 1, -1); // 보통 dist 배열의 초기화는 INF, -1 중 한다. 
		priority_queue<pair<int, int>> pq; // first : dist, second : pos
		dist[start] = 0; // 자기 자신은 비용이 0으로 설정한다.
		pq.push(make_pair(-dist[start], start));  // Min-Heap처럼 사용하기 위해서 first인자에 -부호를 넣었다.
		while(!pq.empty())
		{
			int cur = pq.top().second;
			int cur_cost = pq.top().first;
			pq.pop();
	
			if(cur_cost > dist[cur]) continue; // 뽑아온 값이 기존에 저장한 값보다 크면 무용지물이므로
			
			for(int i = 0; i < a[cur].size(); i++)
			{
				int next = a[cur][i].first;
				int next_cost = a[cur][i].second;
				if(dist[next] == -1 || dist[next] > next_cost) // 최단 거리 갱신
				{
					dist[next] = next_cost;
					pq.push(make_pair(-next_cost, next));
				}
			}
		}
		return dist;
	}
	```
	- 위의 구현결과의 시간복잡도는 `O(E+VlogV)`이다.
	- `BFS`의 응용이므로 기본적인 틀은 비슷하지만, 다른 정점의 정보와 그 때의 비용을 저장하는 것에 주의하자.

#### 9.5.4. Floyd Washall (플로이드 와샬, N-N)
모든 정점에서 모든 정점으로의 최단 경로를 구하는 문제에 사용하는 알고리즘이다. <br>
영어로는 `All pairs shortest path problem` 라고 한다. <br>
이 알고리즘은 간선이 양이든 음이든 가능하다. <br>
다만, 음의 사이클이 없는 경우에만 가능하다. 그렇지 않으면 뺑뺑이 된다. <br>

![Floyd Washall](https://mblogthumb-phinf.pstatic.net/MjAxNzAxMzFfMjIw/MDAxNDg1ODQzNjQzNjM2.BMVGdp_1YhX6iwcfV-xZ9RAKPr1na8ygULvdhqGgSrQg.prrxd4BxgQmWR_tHTmvkeQQqcVU-oRxkOd6ajCRH614g.JPEG.occidere/image_6323615901485841577936.jpg?type=w800) <br>
출처 : https://m.blog.naver.com/occidere/220923695595 <br>

* 플로이드 와샬 구현
	- `인접 행렬`을 이용해서 구현하는 방법이다.
	```cpp
	void floydWarshall()
	{
		for(int k = 1; k <= n; k++) // 거쳐가는 노드
		{
			for(int i = 1; i <= n; i++) // 출발하는 노드
			{
				for(int j = 1; j <= n; j++) // 도착하는 노드
				{
					// [i -> k 비용 + k -> j 비용] vs [i -> j 비용]
					if(d[i][k] + d[k][j] < d[i][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	```
	- 위의 구현결과의 시간복잡도는 `O(V^3)`이다.
	- 모든 정점에서 `Dijkstra`를 실행시킨 것과 동일한 결과를 보여주며, 그런 경우에는 `FloydWarshall`을 쓰는 것이 좋다.
	
#### 9.5.5. Bellman Ford (벨만 포드)
출처 : https://victorydntmd.tistory.com/104 <br>

# C, C++
## 1. String
### 1.1. string::find 와 string::npos
`string::find` 찾는 문자열의 첫 번째 인덱스를 반환하는 함수 <br>
`string::npos` 찾는 문자열이 없는 경우에는 `string::npos`를 반환한다. <br>

```cpp
string str = "Hello World";
if(str.find("World") != string::npos)
{
  cout << "찾는 문자열이 있습니다. 해당 문자열의 시작 인덱스 번호는 << str.find("World") << "입니다. << endl;
}
else
{
  cout << "찾는 문자열이 없습니다." << endl;
}
```
### 1.2. C언어에서 string 처리
문자열을 배열 형태로 구현된 응용 자료형을 의미한다. <br>
문자배열에 string을 저장할 때는 항상 마지막에 끝을 표시하는 `\0` 문자를 넣어준다.

```c
char a1[] = {'a', 'b', 'c', '\0'};
char a2[] = "abc";
```
C언어에서는 string 처리를 위한 다양한 함수들을 제공한다. <br>
`strlen()` 문자열의 길이를 반환하는 함수 <br>
`strcpy()` 문자열을 복사하는 함수 <br>
`strcmp()` 문자열을 비교하는 함수 <br>

**string을 복사하는 알고리즘** <br><br>
src로부터 한 글자씩 읽어서 des에 한 글자씩 복사하는 방법
```c
void strcpy(char* des, char* src)
{
    while(*src != '\0')
    {
      *des = *src;
      src++;
      des++;
    }
    *des = '\0';
}
```
**string을 역순으로 바꾸는 방법** <br>
1. 자기 string을 직접 뒤집는 방법
2. 새로운 빈 string을 만들어서 소스의 뒤에서부터 읽어서 복사하는 방법

1번의 경우 `swap함수`를 위한 임시변수가 필요하고, Loop를 string의 길이의 반만큼 수행하면 된다. <br>
2번의 경우 뒤에서부터 읽는 방식이니, Loop를 string의 길이만큼 수행하면 된다. <br>

**string 비교** <br><br>
`strcmp()`함수를 이용한다.

strcmp에서 반환되는 값에 따라 다음과 같은 결과를 가진다. <br>
`0`이면 두 문자열은 서로 같은 문자열 <br> 
`-1`이면 문자열이 사전순으로 앞인 문자열 <br>
`1`이면 문자열이 사전순으로 뒤인 문자열 <br>

**string로 된 숫자를 정수로 변환하는 방법** <br><br>
C언어에서는 `atoi()` 함수가 제공된다. <br>

  
