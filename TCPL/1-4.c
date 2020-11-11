#include<stdio.h>

int main () {
  float fahr, celsius;
  int lower, upper, step;
  lower = -17;
  upper = 70;
  step = 10;

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius * 9 / 5 + 32;
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    celsius += step;
  }

  return 0;
}