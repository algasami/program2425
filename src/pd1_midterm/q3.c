#include <stdio.h>

#define TWO_POW16 65536LL

/*
[10] Internet IPv6 address is 128 bits, which is usually represented as eight 16-bit numbers seperated
by colon (:). An example IPv6 address is 1050:0000:0000:0000:0005:0600:300c:326b, each 16-bit
number is represented in the format of 4 hex digits. Please write two functions where
(a) one takes an array of 8 short int as a IPv6 address and store it in two 64-bit long int,
(b) one takes two 64-bit long int as a IPv6 address and output its colon-separated representation.
Note: The bitwise operators (such as shift, and, or) are not allowed to be used in this question.
*/

void combine_shorts()
{
	long long a = 0;
	for (int i = 0; i < 4; i++) // one short = 2 bytes = 16 bits
	{
		long long v; // should be short but using long long for uniform
		scanf("%lld", &v);
		a += v;
		if (i < 3)
		{
			a *= TWO_POW16;
		}
	}
	long long b = 0;
	for (int i = 0; i < 4; i++) // one short = 2 bytes = 16 bits
	{
		long long v; // should be short but using long long for uniform
		scanf("%lld", &v);
		b += v;
		if (i < 3)
		{
			b *= TWO_POW16;
		}
	}
	printf("%lld %lld\n", a, b);
}

void output_ll(long long);

void combine_longs()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);

	output_ll(a);
	putchar(':');
	output_ll(b);
}

// 2 bytes
void output_hex(unsigned short n)
{
	char s[5];
	for (int i = 3; i >= 0; i--, n /= 16)
	{
		int x = n % 16;
		s[i] = x < 10 ? x + '0' : x - 10 + 'A';
	}
	s[4] = '\0';
	printf("%s", s);
}

void output_ll(long long x)
{
	unsigned short results[8];
	for (int i = 0; i < 8; i++)
	{
		results[8 - i - 1] = x % TWO_POW16;
		x /= TWO_POW16;
	}
	output_hex(results[0]);
	for (int i = 1; i < 8; i++)
	{
		putchar(':');
		output_hex(results[i]);
	}
}

/**
 * Why is using bitwise operator forbidden prof???
 */

int main()
{
	int op;
	printf("1 for combine shorts, 2 for combine two long longs\n");
	scanf("%d", &op);
	if (op == 1)
	{
		combine_shorts();
	}
	else
	{
		combine_longs();
	}
	return 0;
}