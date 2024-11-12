#include <stdio.h>

/*
Write iterative and recursive versions of the sequence numbers defined by the following:
(1)A(n) = output (n) + B(n – 1) and A(0) = output (0);
(2)B(n) = output (n) + A(n/2) and B(0) = output (0);
(3)What is the outputs of B(20).
*/

/*
By (1) and (2),
A(n) = output (n) + output (n - 1) + A((n - 2) / 2)
*/

int a_recursive(int n)
{
	if (!n)
	{
		return 0;
	}
	return 2 * n - 1 + a_recursive((n - 2) / 2);
}

int a_iterative(int n)
{
	int aggregate = 0;
	int current_n = n;
	while (current_n)
	{
		aggregate += 2 * n + 1;
		current_n = (current_n - 1) / 2; // same as current_n / 2
	}
	aggregate += 0; // a(0) = output(0)
	return aggregate;
}

/*
By (1) and (2),
B(n) = output (n) + output(n / 2) + B(n / 2 - 1)
*/

int b_recursive(int n)
{
	if (!n)
	{
		return 0;
	}
	return n + n / 2 + b_recursive(n / 2 - 1);
}

int b_iterative(int n)
{
	int aggregate = 0;
	int current_n = n;
	while (current_n)
	{
		aggregate += current_n + current_n / 2;
		current_n = current_n / 2 - 1;
	}
	aggregate += 0;
	return aggregate;
}