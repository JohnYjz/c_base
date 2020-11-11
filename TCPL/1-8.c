#include<stdio.h>
int main () {
  int c, spacel, tl, nl;
  spacel = 0;
  tl = 0;
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      nl++;
    }
    if (c == '\t') {
      tl++;
    }
    if (c == '\40') {
      spacel++;
    }
  }
  printf("空格：%d\n", spacel);
  printf("制表符：%d\n", tl);
  printf("回车：%d\n", nl);
  return 0;
}