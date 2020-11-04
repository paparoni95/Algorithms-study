// 출처 : 코딩 인터뷰 완전 분석

// 여러가지 경우에 대한 Big-O 표기법을 확인하자.

// 재귀적 호출 : O(2^N)
int f(int n)
{
	if (n <= 1)
		return 1;
	return f(n - 1) + f(n - 1);
}

// 배열을 읽을 때 : O(N)
// 한 번 읽든, 두 번 읽든 Big-O에는 영향을 주지 않음.
void foo(int array[])
{
	int sum = 0;
	int product = 1;

	for (int i = 0; i < array.length; i++)
		sum += array[i];

	for (int i = 0; i < array.length; i++)
		product *= array[i];
}

// 2중 루프 : O(N^2)
void printUnorderedPairs(int array[])
{
	for (int i = 0; i < array.length; i++)
		for (int j = i + 1; j < array.length; j++)
			printf("%d, %d ", array[i], array[j]);
}

// 2중 루프에 추가적인 연산이 들어가면? : O(N^2)
void printUnorderedPairs(int array[])
{
	for (int i = 0; i < array.length; i++)
		for (int j = i + 1; j < array.length; j++)
			/* if ... O(1) 시간이 걸리는 작업 ...  */
}

// 2중 루프이지만 실수하는 경우 : O(AB)
// 두 배열의 크기를 모두 고려해야 한다.
void printUnorderedPairs(int A[], int B[])
{
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < B.size(); j++)
			/* 연산 */
}

// O(AB)
// 실상 k가 10만이라 O(KAB)가 될 수 도 있다. (영향이 없지 않으므로)
void printUnorderedPairs(int A[], int B[])
{
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < B.size(); j++)
			for(int k = 0; k < 100000; k++)
				/* 연산 */
}

// O(N)
void reverse(int arr[])
{
	for(int i = 0; i < array.size() / 2; i++)
	{
		int other = array.size - i - 1;
		int temp = array[i];
		array[i] = array[other];
		array[other] = temp;
	}
}
