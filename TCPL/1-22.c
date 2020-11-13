#include <stdio.h>

#define BREAK_POS 8
#define MAXLINE 1000

int getLine (char s[], int len);
int breakLine (char s[], int len, char s1[]);
void resetArray (char s[], int len);

int main () {
  char line[MAXLINE];
  int curLen;

  while ((curLen = getLine(line, MAXLINE)) > 0) {
    printf("oldabcd line is ---- > :%s\n", line);
    char newStrs[MAXLINE];
    breakLine(line, curLen, newStrs);
    printf("replace line is ---- >:%s\n", newStrs);
    resetArray(line, curLen);
  }
  return 0;
}

int getLine (char s[], int len) {
  int c;
  int i;
  for (i = 0; i < len && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] += '\n';
    i++;
  }
  s[i] += '\0';
  
  return i;
}

int breakLine (char s[], int len, char s1[]) {
  int breakPos = -1;
  int count = 1;
  for (int i = 0; i < len; i++) {
    if (s[i] == '\40') {
      breakPos = i;
      printf("break pos is %d\n", breakPos);
    }
    if (count > BREAK_POS) {
      printf("count > break pos\n");
      if (breakPos != -1 && breakPos > (i - BREAK_POS)) {
        printf("replace break pos\n");
        s1[breakPos] = '\n';
      }
      count = i - breakPos;
    }
    s1[i] = s[i];
    count++;
  }
  return breakPos;
}

void resetArray(char s[], int len) {
  for (int i = 0; i < len; i++) {
    s[i] = '\0';
  }
}