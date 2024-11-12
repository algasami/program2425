#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[10] Use the random number generator to write a complete program that can generate n random
numbers ranged from min to max by running “myrandom n min max” in command line. Also
answer what is the maximum number that function rand() can generate and where it is defined? Why
we have to set seed, usually using time()?
*/

int main(int argc, char *argv[])
{
	srand(time(NULL));
	if (argc < 4)
	{
		printf("Insufficient parameters, usage is %s n min max\n", argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);
	int mini = atoi(argv[2]);
	int maxi = atoi(argv[3]);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", rand() % (maxi - mini + 1) + mini);
	}
	return 0;
}

/**
 * Maximum number it can generate: RAND_MAX
 * The random number generator provided by stdlib.h is deterministic, meaning given
 * a certain initial parameter, it would output the same sequence of numbers. Thus,
 * we need to provide a different parameter every time we invoke it to ensure
 * a more reliable "random-ness".
 */