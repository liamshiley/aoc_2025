#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE *fp = fopen(argv[1], "r");
    char buff[10];
    int lock = 50;
    int count = 0;
    while(fgets(buff, 10, fp) != NULL){
    //for(int j = 0; j < 10; j++){
      //  fgets(buff, 10, fp);
        int i = 1;
        int k = 0;
        char numBuff[5];
        while(buff[i] != '\n' && buff[i] != EOF && buff[i] != '\0' && k < (int) sizeof(numBuff) - 1){
            numBuff[k++] = buff[i++];
        }
        numBuff[k] = '\0';
        int num = atoi(numBuff);
        if(buff[0] == 'R'){
            lock = (lock + num) % 100;
        }else{
            lock = (lock - num + 100) % 100;
        }
        if(lock == 0){
            count++;
        }
    }
    printf("Hit %d times", count);
}