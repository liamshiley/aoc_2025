#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  FILE* fp = fopen(argv[1], "r");
  char buff[110];
  char number[3];
  int total = 0;
  int lineNum = 0;
  while (fgets(buff, 110, fp) != NULL) {
    number[2] = '\0';
    number[1] = '\0';
    number[0] = '0';
    int i = 0;
    char* secondLargest = &number[1];
    char* largest = &number[0];
    int li = 0;
    while (buff[i] != '\0' && buff[i] != '\n' && buff[i] != EOF) {
      if(buff[i] > *largest){
        *largest = buff[i];
        li = i;
      }
      i++;
    }
    li++;
    if(buff[li] != '\0' && buff[li] != '\n'){
      *secondLargest = '0';
    while (buff[li] != '\0' && buff[li] != '\n' && buff[li] != EOF) {
      if(buff[li] > *secondLargest){
        *secondLargest = buff[li];
      }
      li++;
    }
  }else {
    li--;
    *secondLargest = buff[li];
    *largest = '0';
    for(int j = 0; j < li; j++){
      if(buff[j] > *largest){
        *largest = buff[j];
      }
    }
  }
    printf("%d + %d | %d\n", atoi(number), total, lineNum);
    total += atoi(number);
    lineNum++;
  }
  printf("%d", total);
  fclose(fp);
  return 0;
}