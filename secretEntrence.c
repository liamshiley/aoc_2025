#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE* fp = fopen(argv[1], "r");
  char buff[10];
  int lock = 50;
  int count = 0;
  while (fgets(buff, 10, fp) != NULL) {
    // for(int j = 0; j < 10; j++){
    //   fgets(buff, 10, fp);
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
      int start = lock;
      int end = lock + num;
      int base = (end / 100) - (start / 100);
      if (end > 0 && end % 100 == 0 && base > 0) {
        count += (end / 100) - (start / 100) - 1;
      } else {
        count += (end / 100) - (start / 100);
      }
      lock = end % 100;
    } else {
      int start = lock;
      int end = lock - num;
      int base = (start / 100) - (end / 100);

      if (end == 0 && base > 0) {
        count += (start / 100) - (end / 100) - 1;
      } else {
        count += (start / 100) - (end / 100);
      }
      lock = (end % 100 + 100) % 100;
    }
    if (lock == 0) count++;
  }
  fclose(fp);
  printf("Hit %d times", count);
  return 0;
}