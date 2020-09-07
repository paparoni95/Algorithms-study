#include <bits/stdc++.h>
using namespace std;

const int MX = 10000007;
int dat[MX];
int head, tail; // tail-head : 큐의 길이

void push(int val) {
	dat[tail++] = val;
}

// head == tail일 때 해당 연산을 수행하지 않도록
void pop() {
	head++;
}

// head == tail일 때 해당 연산을 수행하지 않도록
int front() {
	return dat[head];
}

// head == tail일 때 해당 연산을 수행하지 않도록
int back() {
	return dat[tail - 1];
}

int main() {
	push(10);
	push(20);
	push(30);
	cout << front() << endl;
	pop();
	cout << front() << endl;
	cout << back() << endl;
	pop();
	cout << front() << endl;
	cout << back() << endl;
	return 0;
}