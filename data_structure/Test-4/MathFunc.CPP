#include <math.h>
#include <stdio.h>
double fun(double x) {
  //*********************************
  double y;
  y = (3 * x * sin(x) + tan(x)) / (1.5 + fabs(x));
  return y;
  //=================================
}
int main() {
  double x;
  freopen("MathFunc.in", "r", stdin);
  freopen("MathFunc.out", "w", stdout);
  scanf("%lf", &x);
  //**********************************
  printf("%.3lf", fun(x));
  //==================================
  return 0;
}