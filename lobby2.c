#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

int main(int argc, char** argv) {
  FILE* fp = fopen(argv[1], "r");
  char buff[110];
  char number[13];
  long long total = 0;
  while (fgets(buff, 110, fp) != NULL) {
    int len = strlen(buff);
    if(buff[len-1] == '\n'){
        buff[len-1] = '\0';
        len--;
    }
    number[12] = '\0';
    int i = 0;
    for(int pos = 0; pos < 12; pos++){
        int end = len - (12 - pos - 1) - 1;
        char maxChar = '0';
        int maxId = i;

        for(int j = i; j <= end; j++){
            if(buff[j] > maxChar){
                maxChar = buff[j];
                maxId = j;
            }
        }
        number[pos] = maxChar;
        i = maxId + 1;
    }
    total += atoll(number);
}

   printf("%lld", total);
  fclose(fp);
  return 0;
}