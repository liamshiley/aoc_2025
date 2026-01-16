//#include <stdlib.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

struct Range{
    long long firstRange;
    long long secondRange;
}typedef Range;

int main(int argc, char** argv){
    FILE* fp = fopen(argv[1], "r");
    //Array of ranges
    Range* range_array;
    range_array = malloc(sizeof(Range) * 200);
    //Curretnt line buff
    char buff[150];
    //Range index tracker
    int x = 0;
    while (fgets(buff, 150, fp) != NULL){      
        //Store two numbers in range in two different strings
        int j = 0;
        char numBuff[100];
        char secondBuff[100];
        while(buff[j] != '-'){
            numBuff[j] = buff[j];
            j++;
        }
        numBuff[j] = '\0';
        j++;
        int k = 0;
        while (buff[j] != '\n' && buff[j] != '\0'){
            secondBuff[k] = buff[j];
            j++, k++;
        }
        secondBuff[k] = '\0';
        Range newRange;
        newRange.firstRange = atoll(numBuff);
        newRange.secondRange = atoll(secondBuff);
        range_array[x] = newRange;
        x++;
    }
    fclose(fp);
    //All ranges filled and file one is closed
    int count = 0;
    FILE* fpTwo = fopen(argv[2], "r");
    while (fgets(buff, 150, fpTwo)) {
        long long num = atoll(buff);
        for(int i = 0; i < x; i++){
            printf("%d: %lld < %lld, < %lld " , i, range_array[i].firstRange, num, range_array[i].secondRange);
            if(num > range_array[i].firstRange && num < range_array[i].secondRange){
                count++;
                printf("True | Count: %d\n", count);
                break;
            }
            printf("Count: %d\n", count);
        }    
    }
    printf("%d", count);

    fclose(fpTwo);
    free(range_array);
}