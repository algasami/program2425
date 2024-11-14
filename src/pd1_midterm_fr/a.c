#include <stdio.h>
#include <string.h>

// #define DEBUG

int is_palindrome(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	char str[12];
	scanf("%s", str);
	int len = strlen(str), good = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		char buffer[12];
		int j = -1;
		int fromi = 0, toi = 0;
		while (fromi <= len)
		{
			if (fromi == i)
			{
				fromi = i + 1;
			}
			buffer[toi] = str[fromi];
			fromi++;
			toi++;
		}
#ifdef DEBUG
		printf("%s\n", buffer);
#endif
		if (is_palindrome(buffer))
		{
			printf("%d ", len - i);
			good = 1;
		}
	}
	if (!good)
	{
		puts("Impossible");
	}
	else
	{
		putchar('\n');
	}
	return 0;
}