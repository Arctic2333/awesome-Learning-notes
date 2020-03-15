#include <stdio.h>
#include <math.h>
double fun(double x) {
  //*********************************
  if (x < 10)
    return (sqrt(2.5 + cos(x))) / (x * sin(x) + 3);
  else
    return pow(x, 2);
  //=================================
}
int main() {
  double x;
  freopen("PWFunc.in", "r", stdin);
  freopen("PWFunc.out", "w", stdout);
  scanf("%lf", &x);
  //**********************************
  printf("%.3lf", fun(x));
  //==================================
  return 0;
}