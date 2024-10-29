#include <bits/stdc++.h>

// #define DEBUG

// O(log_10 x)
int sumbase10(int x)
{
	int val = 0;
	do
	{
		val += x % 10;
	} while (x /= 10);

	return val;
}

int visited[100001] = {0}; // visited (one base to represent something)
int buffered[100001];	   // array of previous n
int buffer_length = 0;

// O(n) around 10^10 seconds
// but we have cycles
// so at most 10^5 :) modulo arithmetic <3
int main()
{
	int n;
	unsigned long long k;
	scanf("%d %llu", &n, &k);
	while (k--)
	{
		if (visited[n])
		{
			// found a cycle, initiate mod arithmetic
			int pivot = visited[n] - 1;
			int cycle_length = buffer_length - pivot; // the actual cycle snippet
#ifdef DEBUG
			printf("%d\n", cycle_length);
			for (int i = pivot; i < pivot + cycle_length; i++)
			{
				printf("%d,", buffered[i]);
			}
			putchar('\n');
#endif
			n = buffered[((k + 1) % cycle_length) + pivot];
			break;
		}
		int next = (sumbase10(n) + n) % 100000;
		buffered[buffer_length++] = n;
		visited[n] = buffer_length; // one base
		n = next;
	}
	printf("%d\n", n);
	return 0;
}