#include<stdio.h>

int main () {
  int c;
  int isInWord = 1;
  while ((c = getchar()) != EOF) {
    if (c == '\40' || c == '\n' || c == '\t') {
      if (isInWord) {
        printf("\n");
      }
      isInWord = 0;
    } else {
      isInWord = 1;
      putchar(c);
    }
  }
  return 0;
}