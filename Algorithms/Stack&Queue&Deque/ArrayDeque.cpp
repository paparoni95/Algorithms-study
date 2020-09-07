#include <bits/stdc++.h>
using namespace std;

const int MX = 1000007;
int dat[2 * MX + 3];
int head = MX, tail = MX; // 스택/큐와는 달리 왼쪽으로도 확장되기 때문에 0번지에서 시작하는게 아니라 중간에서 시작, 길이는 tail - head

void push_front(int val) {
	dat[--head] = val;
}

void push_back(int val) {
	dat[tail++] = val;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}

int main() {
	push_back(10);
	push_front(20);
	cout << front() << endl;
	cout << back() << endl;
	push_back(50);
	cout << front() << endl;
	cout << back() << endl;
	cout << "length() : " << tail - head << endl;
	return 0;
}