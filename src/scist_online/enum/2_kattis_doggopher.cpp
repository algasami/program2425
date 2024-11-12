#include <bits/stdc++.h>

using namespace std;

double gx, gy, dx, dy;
int n = 0;

double dist_sqr(double x1, double y1, double x2, double y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy);
	double hx, hy;
	while (scanf("%lf %lf", &hx, &hy) != EOF)
	{
		double dist_gh = dist_sqr(gx, gy, hx, hy);
		double dist_dh = dist_sqr(dx, dy, hx, hy);
		if (dist_dh > dist_gh * 4.0)
		{
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", hx, hy);
			return 0;
		}
	}
	puts("The gopher cannot escape.");
	return 0;
}