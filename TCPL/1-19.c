#include <stdio.h>
#define MAXLINE 10

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int reverseLine (char words1[], char words2[], int len);

int main () {
  int len;
  int max;
  char line[MAXLINE];
  
  while ((len = getLine(line, MAXLINE)) > 0) {
    char longest[MAXLINE];
    printf("len is %d", len);
    reverseLine(line, longest, len);
    printf("reverse line is %s\n", longest);

  }
  return 0;
}

int getLine (char s[], int lim) {
  int i;
  int c;
  /* 
  输入 abc\n
  在输入\n前没有任何反应
  输入\n后执行3次循环
   */
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0') {
    i++;
  }
}

int reverseLine (char words1[], char words2[], int len) {
  for (int i = len - 1; i >=0; i--) {
    words2[i] = words1[len - 1 - i];
  }
  return 0;
}
