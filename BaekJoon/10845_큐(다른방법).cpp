#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

void push(int x);   //push x : 정수 x를 큐에 넣는 연산이다.
int pop(void);      //pop: 큐에 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력
int get_size(void); //size : 큐에 들어있는 정수의 개수를 출력한다.
int empty(void);    //empty : 큐가 비어있다면 1, 아니면 0
int front(void);    //front : 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1
int back(void);     //back : 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1

queue<int> q;

int main(void)
{
	int num;
	char str[6]; //문자열 끝을 의미해주는 null문자를 포함해서 +1

	scanf("%d", &num);
	//명령어의 개수 만큼
	for (int i = 0; i < num; i++)
	{
		int x;
		scanf("%s", &str);

		if (strcmp(str, "push") == 0) {
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", pop());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", get_size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", empty());
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", front());
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", back());
		}
	}
	return 0;
}


void push(int x)
{
	q.push(x);
}

int pop(void)
{
	int temp = 0;
	if (empty())
		return -1;
	else
	{
		temp = q.front();
		q.pop();
		return temp;
	}

}

int get_size(void)
{
	return q.size();
}

int empty(void)
{
	return q.empty();
}

int front(void)
{
	if (q.empty())
		return -1;
	else
		return q.front();
}

int back(void)
{
	if (q.empty())
		return -1;
	else
		return q.back();
}
