//#include <stdlib.h>
#include <inttypes.h>
#include <strings.h>
#include <stdio.h>

int main(int argc, char** argv) {
  FILE* fp = fopen(argv[1], "r");
  char map[150][150];
  int row = 0;
  while (fgets(map[row], 150, fp) != NULL) {
    row++;
  }
  
  int valid = 0;

  for(int i = 0; i < 140; i++){
    for(int j = 0; j < 140; j++){
        if(map[i][j] == '\n') continue;
        if(map[i][j] == '@'){
            int nextTo = 0;
            if(map[i+1][j] == '@') nextTo++;
            if(map[i-1][j] == '@') nextTo++;
            if(map[i][j+1] == '@') nextTo++;
            if(map[i][j-1] == '@') nextTo++;
            if(map[i-1][j+1] == '@') nextTo++;
            if(map[i-1][j-1] == '@') nextTo++;
            if(map[i+1][j+1] == '@') nextTo++;
            if(map[i+1][j-1] == '@') nextTo++;
            if(nextTo < 4){
                valid++;
            }
        }
    }
  }
  printf("%d\n", valid);
  
}