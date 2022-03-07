# 수학
수학과 관련된 알고리즘 정리 노트.

## 단일 소수를 판별하는 방법

`소수` 약수가 1과 자기 자신 밖에 없는 수

어떤 수 N이 소수인지 아닌지 판별하는 방법은 2 ~ N - 1보다 작거나 같은 자연수로 나누어 떨어지면 안된다.
```cpp
TimeComplexity : O(sqrt(N))
SpaceComplexity : O(1)

i <= sqrt(N) : 되도록이면 소수보다는 정수가 좋다.
i * i <= N

bool isPrime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}
```

## 대량의 소수를 판별하는 방법

`에라토스테네스의 체` 라는 알고리즘으로 아래와 같은 방식으로 동작한다.

1. 2부터 N까지 모든 수를 써놓는다.
2. 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
3. 그 수는 소수다.
4. 이제 그 수의 배수를 모두 지운다.

```cpp
TimeComplexity : O(Nloglog(N))
SpaceComplexity : O(N)

bool notPrime[10001]; // false : 소수, true : 소수가 아님

void eratosthenes()
{
	notPrime[0] = true;
	notPrime[1] = true;
	for (int i = 2; i < 10001; i++)
	{
		if (notPrime[i] == false)
		{
			for (int j = i + i; j < 10001; j += i)
			{
				notPrime[j] = true;
			}
		}
	}
}
```

## 나머지 연산(모듈러 연산)

많이 사용하는 방법으로 `%`, `mod`를 이용하여 구하는 연산이다.

최적화 방법에도 많이 사용한다. ex) 이동 경로를 최소화 시킬 때, Random 에도 사용, 정답을 ~로 나눈 나머지를 출력해라~, 주기가 일정할 때

나머지 연산에는 중요한 성질이 있는데 다음과 같다.
```cpp
(A + B) mod M = ((A mod M) + (B mod M)) mod M
(A * B) mod M = ((A mod M) * (B mod M)) mod M

(A - B) mod M = ((A mod M) - (B mod M) + M) mod M
```

## 최대 공약수와 최소 공배수

잊을만 하면 나오는 개념을 묻는 경우가 많다. 잘 정리하자.

`최대 공약수` : 두 수 A 와 B의 최대 공약수는 A 와 B의 공통된 약수 중에서 **가장 큰 정수**
`최대 공약수`가 1인 두 수를 `서로소(coprime)` => 공통된 원소가 없다.

응용으로는 `기약 분수`를 나타낼 때 좋다. 분수를 최대 공약수로 나누게 되면 그게 바로 기약 분수다.

`유클리드 호제법(Euclidean Algorithm)` : 최대 공약수 알고리즘
```cpp
TimeComplexity : O(logN)
SpaceComplexity : O(1)

성능상 반복문 구현이 좋지만, 가독성은 재귀함수가 좋다.

재귀함수
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

반복문
int gcd(int a, int b)
{
  while(b != 0)
  {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
```

만약 세 수의 최대공약수를 구하라고 한다면?

gcd(a, b, c) => gcd(gcd(a, b), c)

최소 공배수는 어떻게 구할까? => 최대 공약수를 응용해서 구할 수 있다.

`최소 공배수(Least Common Multiple, LCM)` : 두 수의 공통된 배수 중에서 **가장 작은 정수**

```cpp
두 수 a, b의 최대 공약수를 g라고 하면
l = g * (a / g) * (b / g)
```





