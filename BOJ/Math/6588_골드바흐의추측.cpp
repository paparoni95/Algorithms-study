#include <iostream>
using namespace std;

bool prime[1000001];

void eratosthenes()
{
	prime[1] = true;

	for (int i = 2; i * i <= 1000000; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i + i; j <= 1000000; j += i)
				prime[j] = true;
		}
	}
}

void goldBach(int n)
{
	for (int i = 0, j = n; i <= n / 2; i++, j--)
	{
		if (i % 2 == 1 && j % 2 == 1 && !prime[i] && !prime[j])
		{
			printf("%d = %d + %d\n", n, i, j);
			return;
		}
	}

	printf("Goldbach's conjecture is wrong.\n");
	return;
}

int main()
{
	eratosthenes();

	int n;
	while (1)
	{
		scanf("%d", &n);
		
		if (n == 0)
			break;

		goldBach(n);
	}

	return 0;
}