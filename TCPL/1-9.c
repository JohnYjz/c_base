#include<stdio.h>
int main () {
  int c;
  int spaceStart = 1;
  while ((c = getchar()) != EOF) {
    if (c != '\40') {
      spaceStart = 1;
      putchar(c);
    } else {
      if (spaceStart == 1) {
        putchar(c);
        spaceStart = 0;
      }
    }
  }
  return 0;
}