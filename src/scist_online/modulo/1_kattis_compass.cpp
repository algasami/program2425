#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);

	int delta = n2 - n1;
	if (abs(delta) > 180)
	{
		if (delta < 0)
			delta += 360;
		else
			delta -= 360;
	}
	else if (abs(delta) == 180)
	{
		delta = abs(delta);
	}
	printf("%d\n", delta);
	return 0;
}