#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE* fp = fopen(argv[1], "r");
  char buff[10];
  int lock = 50;
  int count = 0;
  while (fgets(buff, 10, fp) != NULL) {
    printf("%s", buff);
    int i = 1;
    int k = 0;
    char numBuff[5];
    while (buff[i] != '\n' && buff[i] != EOF && buff[i] != '\0' &&
           k < (int)sizeof(numBuff) - 1) {
      numBuff[k++] = buff[i++];
    }
    numBuff[k] = '\0';
    int num = atoi(numBuff);

    if (buff[0] == 'R') {
      int passes = (lock + num) / 100;
      lock = (lock + num) % 100;
      count += passes;
    } else {
      if (num >= lock && lock > 0) {
        int remaining = num - lock;
        int passes = 1 + remaining / 100;
        count += passes;
      } else if (lock == 0 && num >= 100) {
        int passes = num / 100;
        count += passes;
      }

      lock = ((lock - num) % 100 + 100) % 100;
    }
  }
  fclose(fp);
  printf("Hit %d times", count);
  return 0;
}