#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> pq; // 최대힙
priority_queue<int, vector<int>, less<int> > pq2; // 최대힙pq와 똑같다
priority_queue<int, vector<int>, greater<int> > pq3; // 최소힙

vector<int> arr = { 3,1,4,1,5,9 };

struct test
{
	int start;
	int end;
	int value;
};

struct compare
{
	bool operator()(test& a, test& b)
	{
		return a.value < b.value; // 큰 순으로 나온다.
		//return a.value > b.value; // 작은 순으로 나온다.
	}
};

priority_queue<test, vector<test>, compare> pq4; // 사용자 정의 자료형 힙

int main()
{
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(9);
	while (!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	} // result : 9 5 4 3 1 1
	cout << endl;


	for (int i = 0; i < arr.size(); i++) pq3.push(arr[i]);
	while (!pq3.empty())
	{
		cout << pq3.top() << ' ';
		pq3.pop();
	} // result : 1 1 3 4 5 9
	cout << endl;

	pq4.push({ 0,1,5 });
	pq4.push({ 1,2,1 });
	pq4.push({ 4,3,2 });
	pq4.push({ 2,1,1 });
	pq4.push({ 1,2,7 });
	pq4.push({ 3,2,9 });
	while (!pq4.empty())
	{
		cout << pq4.top().start << ' ' << pq4.top().end << ' ' << pq4.top().value << endl;
		pq4.pop();
	}

	/*
	return a.value < b.value 일 때, 큰 순으로 나온다.
	result:
	3 2 9
	1 2 7
	0 1 5
	4 3 2
	2 1 1
	1 2 1

	return a.value > b.value 일 때, 작은 순으로 나온다.
	result:
	1 2 1
	2 1 1
	4 3 2
	0 1 5
	1 2 7
	3 2 9
	*/

	return 0;
}