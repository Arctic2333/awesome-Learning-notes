#include <stdio.h>

#include <math.h>

int main() {
	int a[100];
	int i, n, k;
	double avg = 0, c;
	freopen("MaxDiff.in", "r", stdin);
	freopen("MaxDiff.out", "w", stdout);
	//*********************************
	c = 0;
	int Max = -999, Min = 999;
	scanf("%d", & n);
	for (i = 0; i < n; i++) {
		scanf("%d", & a[i]);
		c += a[i];
		if (Max < a[i]) Max = a[i];
		if (Min > a[i]) Min = a[i];
	}
	avg = c / n;
	if ((Max - avg) >= (avg - Min)) {
		printf("%d", Max);
	} else {
		printf("%d", Min);
	}
	//=================================
	return 0;
}