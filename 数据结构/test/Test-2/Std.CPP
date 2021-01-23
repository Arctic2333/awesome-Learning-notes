#include <stdio.h>

#include <math.h>

#define N 100
int main() {
	int a[N] = { 0 };
	int i, n;
	double avg, sum, d;
	freopen("Std.in", "r", stdin);
	freopen("Std.out", "w", stdout);
	/*********************************************************/
	scanf("%d", & n);
	avg = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", & a[i]);
		avg += a[i];
	}
	avg /= n;
	for (i = 0; i < n; i++) {
		sum += pow((a[i] - avg), 2);
	}
	d = sqrt( sum / (n - 1));
	printf("%.3lf", d);
	/*********************************************************/
	return 0;
}