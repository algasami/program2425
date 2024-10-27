#include <bits/stdc++.h>

#define MAXSIZE 300001

using namespace std;

int main()
{
	char buffer[MAXSIZE];
	unsigned int leftmin[MAXSIZE], rightmin[MAXSIZE];
	memset(leftmin, -1, sizeof(leftmin));
	memset(rightmin, -1, sizeof(rightmin)); // -1 here would make unsigned int max value
	scanf("%s", buffer);
	int buffer_length = strlen(buffer);
	int lastindex = -1;
	// find closest of 0 to 1. first find left, second find right.
	for (int i = 0; i < buffer_length; i++) // left to right
	{
		if (buffer[i] == '1')
		{
			lastindex = i;
			continue;
		}
		if (lastindex >= 0)
			leftmin[i] = i - lastindex;
	}
	lastindex = -1;
	for (int i = buffer_length - 1; i >= 0; i--) // right to left
	{
		if (buffer[i] == '1')
		{
			lastindex = i;
			continue;
		}
		if (lastindex >= 0)
			rightmin[i] = lastindex - i;
	}

	int longest = 0;
	for (int i = 0; i < buffer_length; i++)
	{
		int val = min<unsigned int>(leftmin[i], rightmin[i]); // min here would be comparing uint max instead of -1
		if (val > longest)									  // val would automatically be the right value
		// if l = r = uint max, val = -1
		// if one of them is not, val is that value because -1 there is uint max
		{
			longest = val;
		}
	}
	printf("%d\n", longest);
	return 0;
}