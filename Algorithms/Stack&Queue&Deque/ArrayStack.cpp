#include <bits/stdc++.h>
using namespace std;

const int MX = 10000007;
int dat[MX];
int pos;

void push(int val) {
	dat[pos++] = val;
}

void pop() {
	pos--;
}

int top() {
	return dat[pos - 1];
}

int main() {
	push(10);
	push(20);
	push(30);
	cout << top() << endl;
	pop();
	cout << top() << endl;
	pop();
	cout << top() << endl;
	pop();
	return 0;
}