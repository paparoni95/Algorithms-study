#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 100 + 1
using namespace std;

int N;
int a[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE][MAX_SIZE];

vector<vector<int>> v;
vector<bool> visited;

void dfs(int node)
{
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (!visited[next])
		{
			visited[next] = true;
			dfs(next);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}

	v.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j])
			{
				v[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		fill(visited.begin(), visited.end(), false);
		dfs(i);
		for (int j = 0; j < N; j++)
		{
			if (visited[j] == true) b[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}