#include<stdio.h>
// 这也太人难以理解了吧
int main () {
  int c;
  c = getchar(); // 等待用户输入，这里可以理解为监听事件注册，每一次触发都会从这里开始执行后面的代码，比如输入abcde
  printf("%d\n", c); // a的asc2码
  while (c != EOF) {
    putchar(c); // 相当于printf("%c\n", (char)c);
    c = getchar(); // 让c的字符串的指针后移，没有它的话会成为死循环
    if (c == EOF) {
      printf("C == EOF\n");
    }
  }
  // 这里不会执行
  printf("END\n");
  return 0;
}