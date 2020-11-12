#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main () {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    printf("word len is %d\n", len);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("%s", longest);
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
    printf("for loop\n");
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  printf("after for loop\n");

  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0') {
    i++;
  }
}