#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = "15 12 11 9 6 4";
  int num = 0;
  int i = 0;
  while (str[i] != '\0') {
    while (str[i] == ' ') {
      i++;
    }
    // printf("Before atoi - str[%d]: %c\n", i, str[i]);
    num = atoi(&str[i]);
    i++;
    while (isdigit(str[i]) && str[i] != '\0') {
      i++;
    }
    printf("num: %d\n", num);
    // str++
    if (str[i] != '\0') {
      i++;
    }
  }
}