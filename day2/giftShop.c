#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isRepeated(long long n) {
  char s[60];
  sprintf(s, "%lld", n);
  int len = strlen(s);
  if (len % 2 != 0) {
    return false;
  }
  int mid = len / 2;
  return strncmp(s, s + mid, mid) == 0;
}

int main(int argc, char** argv) {
  long long total = 0;
  FILE* fp = fopen(argv[1], "r");
  char buff[600];
  fgets(buff, 600, fp);
  int i = 0;

  while (buff[i] != EOF && buff[i] != '\0' && buff[i] != '\n') {
    int j = 0;
    char firstNumBuff[50];
    while (buff[i] != '-' && buff[i] != ',') {
      firstNumBuff[j] = buff[i];
      i++;
      j++;
    }
    firstNumBuff[j] = '\0';
    if (buff[i] == '-') i++;
    char secondNumBuff[50];
    int k = 0;
    while (buff[i] != ',' && buff[i] != EOF && buff[i] != '\n' &&
           buff[i] != '\0') {
      secondNumBuff[k] = buff[i];
      i++;
      k++;
    }
    secondNumBuff[k] = '\0';
    if (buff[i] == ',') {
      i++;
    }
    long long num1 = atoll(firstNumBuff);
    long long num2 = atoll(secondNumBuff);
    while (num1 <= num2) {
      if (isRepeated(num1)) {
        total += num1;
        num1++;
      } else {
        num1++;
      }
    }
  }

  printf("%lld\n", total);
  fclose(fp);
}