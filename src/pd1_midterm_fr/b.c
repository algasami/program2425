#include <stdio.h>

// + = crop = 1
// . = empty = 0
int n, m;
int current_pos;
int state[11];

int main()
{
	scanf("%d %d", &n, &m);
	getchar(); // remove \n
	for (int i = 0; i < n; i++)
	{
		char c;
		scanf("%c", &c);
		switch (c)
		{
		case '+':
			state[i] = 1;
			break;
		case '.':
			state[i] = 0;
			break;
		case 'V':
			current_pos = i;
			state[i] = 0; // destroys
			break;
		}
	}
	getchar(); // eat '\n'
	for (int step = 0; step < m; step++)
	{
		char op;
		int offset;
		scanf(" %c", &op);
		scanf("%d", &offset);
		if (op == 'L')
		{
			offset = -offset;
		}
		int next_pos = offset + current_pos;
		if (next_pos < 0 || next_pos >= n)
		{
			puts("Out of range");
			continue;
		}
		state[next_pos] = 0;
		current_pos = next_pos;
		for (int i = 0; i < n; i++)
		{
			if (i == current_pos)
			{
				putchar('V');
				continue;
			}
			putchar(state[i] ? '+' : '.');
		}
		putchar('\n');
	}
	return 0;
}