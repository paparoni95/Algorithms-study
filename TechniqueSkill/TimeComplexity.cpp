#include <iostream>
#include <vector>
using namespace std;

/*
	# 시간복잡도 종류
	
	O(1) : 단순 계산(상수 시간)
	O(logN) : 이진탐색, N개를 절반으로 계속해서 나눔
	O(N) : 1중 for문, 정렬되지 않은 길이가 N인 배열에서 가장 작은 수를 탐색
	O(NlogN) : 힙정렬, 병합정렬, 퀵정렬
	O(N^2) : 2중 for문, 버블정렬, 삽입정렬, 선택정렬
	O(N^3) : 3중 for문, 플로이드 워셜
	O(2^N) : 크기가 N인 집합의 부분 집합, 번호가 매겨진 N개의 동전을 던졌을 때 나올 수 있는 경우를 출력
	O(N!) : 크기가 N인 수열, 1부터 N까지 숫자를 나열할 수 있는 모든 방법을 출력

	# 1초가 걸리는 입력의 크기
	100,000,000 => 1억 => 1초

	O(1) - 1
	O(logN) - 
	O(N) - 1억
	O(NlogN) - 5백만
	O(N^2) - 1만, nC2 = n(n-1)/2 => O(N^2)
	O(N^3) - 500
	O(2^N) - 20
	O(N!) - 10, 11은 4천만

	# 다양한 케이스들
	
	하나의 루프를 사용하여 단일 요소 집합을 반복하는 경우 O(N)
	컬렉션의 절반 이상을 반복하는 경우 O(N/2) -> O(N)
	두 개의 다른 루프를 사용하여 두 개의 개별 컬렉션을 반복할 경우 O(N + M)
	두 개의 중첩 루프를 사용하여 단일 컬렉션을 반복하는 경우 O(N^2)
	두 개의 중첩 루프를 사용하여 두 개의 다른 컬렉션을 반복하는 경우 O(N * M)
	컬렉션을 정렬하는 경우 O(NlogN)

	# 정렬 알고리즘 비교

	SortingAlgorithm  |  SpaceComplexity  |  TimeComplexity
	                  |  Worst            |  Best     |  Average  |  Worst    |
	Bubble Sort       |  O(1)             |  O(N)     |  O(N^2)   |  O(N^2)   |
	Selection Sort    |  O(1)             |  O(N^2)   |  O(N^2)   |  O(N^2)   |
	Insertion Sort    |  O(1)             |  O(N)     |  O(N^2)   |  O(N^2)   |
	Heap Sort         |  O(1)             |  O(NlogN) |  O(NlogN) |  O(NlogN) |
	Merge Sort        |  O(N)             |  O(NlogN) |  O(NlogN) |  O(NlogN) |
	Quick Sort        |  O(logN)          |  O(NlogN) |  O(NlogN) |  O(n^2)   |


	# 자료구조 비교
	
	Data Structure    |           Average Case        |           Worst Case          |
			  |  Search  |  Insert  | Delete  |  Search  |  Insert  | Delete  |
	Array             |  O(N)    |          |         |  O(N)    |          |         |
	Sorted Array      |  O(logN) |  O(N)    |  O(N)   |  O(logN) |  O(N)    |  O(N)   |
	Linked List       |  O(N)    |  O(1)    |  O(1)   |  O(N)    |  O(1)    |  O(1)   |
	DoublyLinked List |  O(N)    |  O(1)    |  O(1)   |  O(N)    |  O(1)    |  O(1)   |
	Stack             |  O(N)    |  O(1)    |  O(1)   |  O(N)    |  O(1)    |  O(1)   |
	Hash table        |  O(1)    |  O(1)    |  O(1)   |  O(N)    |  O(N)    |  O(N)   |
	BinarySearchTree  |  O(logN) |  O(logN) |  O(logN)|  O(N)    |  O(N)    |  O(N)   |
	Red-Black Tree    |  O(logN) |  O(logN) |  O(logN)|  O(logN) |  O(logN) |  O(logN)|
	AVL Tree          |  O(logN) |  O(logN) |  O(logN)|  O(logN) |  O(logN) |  O(logN)|
*/


// O(logN)
while (digit != 0)
{
	digit = digit / 2;
}

// O(N), 1중 FOR
for (int n : arr)
{
	cout << n << ' ';
}

// O(N * M)
// v1 크기 N, v2 크기 M이라고 하면,
void f(vector<int> & v1, vector<int> & v2)
{
	for (int i = 0; i < v1.size(); i++)
		for (int j = 0; j < v2.size(); j++)
			cout << i + j << ' ';
}


// O(a/b)
int div(int a, int b)
{
	int count = 0;
	int sum = b;
	while (sum <= a)
	{
		sum += b;
		count++;
	}
	return count;
}

// O(sqrt(n))
int sqrt(int n)
{
	for (int g = 1; g * g <= n; g++)
	{
		if (g * g == n) return g;
	}
	return -1;
}

/*
	if a binary search tree is not balanced,
	how long might it take worse case to find an element in it?
	O(N)

	You are looking for specific value in a binary tree,
	but the tree is not a binary search tree.
	what is the time complexity of this?
	O(N)
*/


// O(N)
int* appendToNew(int* arr, int len, int value)
{
	int* bigger = new int[len + 1];
	for (int i = 0; i < len; i++) bigger[i] = arr[i];
	bigger[len] = value;
	return bigger;
}

// O(N^2)
int* copyArray(int* array)
{
	int* copy;
	for (int i = 0; i < array.size(); i++)
	{
		copy = appendToNew(copy, array[i]);
	}
	return copy;
}


// O(logN)
int sumDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

// O(blogb + alogb)
int intersection(vector<int>& a, vector<int>& b)
{
	mergesort(b);
	int intersect = 0;
	for (int x : a)
	{
		if (binarySearch(b, x) >= 0)
		{
			intersect++;
		}
	}
	return intersect;
}

// O(2^N)
int f(int n, int r)
{
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	return f(n - 1, r) + f(n - 2, r);
}
