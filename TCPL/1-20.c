#include <stdio.h>
#define MAXLINE 100
#define SPACE_AS_TAB 8;

int getLine (char s[], int len);
int replaceTab(char s[], int len, char newline[]);
int findNextTabPos(int index);
void resetArray(char s[], int len);

int main () {
  char line[MAXLINE];
  int curLen;

  while ((curLen = getLine(line, MAXLINE)) > 0) {
    printf("oldabcd line is:%s\n", line);
    char newLine[MAXLINE];
    int newLen = replaceTab(line, curLen, newLine);
    printf("replace line is:%s\n", newLine);
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

int replaceTab(char s[], int len, char newline[]) {
  int index1 = 0;
  int index2 = 0;
  while (s[index1] != '\0') {
    if (s[index1] == '\t') {
      int tabEndPosition = findNextTabPos(index2);
      for (int i = index2; i < tabEndPosition; i++) {
        newline[index2] = '\40';
        index2++;
      }
    } else {
      newline[index2] = s[index1];
      index2++;
    }
    index1++;
  }
  index2++;
  newline[index2] = '\0';
  return index2;
}

int findNextTabPos(int index) {
  // printf("cur index is: %d\n", index);
  if (index % 8 == 0) return index + 8;
  index++;
  while(index % 8 != 0) index++;
  // printf("next tab pos is: %d\n", index);
  return index;
}
void resetArray(char s[], int len) {
  for (int i = 0; i < len; i++) {
    s[i] = '\0';
  }
}