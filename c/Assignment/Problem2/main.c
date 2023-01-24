#include <stdio.h>
int main()
{
	double h = 0.00001; // taking a small value for h
	double sum = 0.0;

	printf("Enter range: ");
	double l, r;
	scanf("%lf %lf", &l, &r);

	/* Setting the Interval*/
	double x = l;	  // leftmost point
	double y = l + h; // just next to the leftmost point

	int op = (int)((r - l) / h);
	for (int i = 1; i <= op; i++)
	{
		double x = (x + y) / 2;								// average of points
		double fun = 4 * x * x * x - 2 * x * x + 3 * x + 5; // f(x)=4x^3-2x^2+3x+5

		sum += fun;

		// moving to next points
		x += h;
		y += h;
	}
	sum *= h;
	printf("%.2lf", sum);

	return 0;
}