#include <bits/stdc++.h>

using namespace std;

int n, currencies[3], min_val = INT_MAX;

// change making
// complexity: [n / min{currency}]^3, worst case [10^9]^3 = 10^27
// consider the last coin must be deducted, we can do a constant time check
// on it, so it has been reduced to n^2, around 10^18.
// then we also memorize the "minimum value" as we traverse through different options
// so we don't have to check as many cases as it theoretically requires.

bool coin_making(int numbers[3], int i, int left)
{
	if (i == 0 || left == 0)
	{
		// i == 0: last resort, if it can't make left = 0 then impossible
		// left == 0: it's a solution!
		if (left % currencies[i] == 0)
		{
			int sum = numbers[0] + numbers[1] + numbers[2] + left / currencies[i];
			if (min_val > sum)
			{
				min_val = sum;
			}
			return true;
		}
		return false;
	}
	// see if we can allocate this currency at pointer
	for (int j = left / currencies[i]; j >= 0; j--)
	{
		numbers[i] += j;
		int sum = numbers[0] + numbers[1] + numbers[2];
		if (sum < min_val)
		{
			coin_making(numbers, i - 1, left - j * currencies[i]);
		}
		// if we are already bigger or equal to the minimum value just give up :)

		// backtracks
		numbers[i] -= j;
	}
	return false;
}

int main()
{
	scanf("%d %d %d %d", &n, currencies, currencies + 1, currencies + 2);
	sort(currencies, currencies + 3);

	int numbers[3] = {0};
	coin_making(numbers, 2, n);
	printf("%d\n", min_val);

	return 0;
}