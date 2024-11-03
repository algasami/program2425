#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

deque<char> memory; // max three
int char_hash[256] = {0};

void counter(char in)
{
	switch (in)
	{
	case 'R':
		putchar('S');
		break;
	case 'B':
		putchar('K');
		break;
	case 'L':
		putchar('H');
		break;
	default:
		break;
	}
}

int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		memory.push_back(c);
		char_hash[c]++;
		if (memory.size() == 3)
		{
#ifdef DEBUG
			puts("----\n");
			for (char c : memory)
			{
				putchar(c);
			}
			puts("\n----\n");
#endif
			if (char_hash['R'] && char_hash['B'] && char_hash['L'])
			{
				putchar('C');
				memory.clear();
				char_hash['R']--;
				char_hash['B']--;
				char_hash['L']--;
			}
			else
			{
				counter(memory.at(0));
				char_hash[memory.at(0)]--;
				memory.pop_front();
			}
		}
	}
	for (char c : memory)
	{
		counter(c);
	}
	putchar('\n');
	return 0;
}