#include <iostream>
#include <queue>
using namespace std;

struct Person
{
	int r;
	int t;
	int id;

	Person(int r, int t, int id)
	{
		this->r = r;
		this->t = t;
		this->id = id;
	}
};

int main()
{
	priority_queue<Person, vector<Person>, greater<Person>()> pq;
	pq.push(Person(0, 1, 1));
	pq.push(Person(0, 2, 2));
	pq.push(Person(0, 2, 3));
	pq.push(Person(1, 3, 4));

	while (!pq.empty())
	{
		cout << pq.top().r << ' ' << pq.top().t << ' ' << pq.top().id << endl;
		pq.pop();
	}
	return 0;
}