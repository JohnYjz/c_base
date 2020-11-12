#include<stdio.h>

int main () {
  int c;
  int isInWord = 1;
  int counts[10];
  for (int i; i < 10; i++) {
    counts[i] = 0;
  }
  int countOne = 0;
  int index = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == '\t' || c == '\40') {
      isInWord = 0;
      counts[index] = countOne;
      countOne = 0;
      index++;
    } else if (isInWord) {
      countOne ++;
    } else {
      isInWord = 1;
      countOne++;
    }
  }
  for (int k = 0; k < 10; k++) {
    printf("index %d is: ", k);
    for (int j = 0; j < counts[k]; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}