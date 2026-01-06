//#include <stdlib.h>
#include <inttypes.h>
#include <strings.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv) {
  FILE* fp = fopen(argv[1], "r");
  char map[150][150];
  int row = 0;
  while (fgets(map[row], 150, fp) != NULL) {
    row++;
  }
  
  int valid = 0;
  int removed = 1;

while(removed != 0){
    removed = 0;
    bool toRemove[150][150] = {false};
  for(int i = 0; i < 140; i++){
    for(int j = 0; j < 140; j++){
        if(map[i][j] == '\n') continue;
        if(map[i][j] == '@'){
            int nextTo = 0;
            if(map[i+1][j] == '@' || map[i+1][j] == 'x') nextTo++;
            if(map[i-1][j] == '@' || map[i-1][j] == 'x') nextTo++;
            if(map[i][j+1] == '@' || map[i][j+1] == 'x') nextTo++;
            if(map[i][j-1] == '@' || map[i][j-1] == 'x') nextTo++;
            if(map[i-1][j+1] == '@' || map[i-1][j+1] == 'x') nextTo++;
            if(map[i-1][j-1] == '@' || map[i-1][j-1] == 'x') nextTo++;
            if(map[i+1][j+1] == '@' || map[i+1][j+1] == 'x') nextTo++;
            if(map[i+1][j-1] == '@' || map[i+1][j-1] == 'x') nextTo++;
;            if(nextTo < 4){
               // printf("Next To: %d, i: %d, j: %d\n", nextTo, i, j);
                toRemove[i][j] = true;
                removed++;
                valid++;
            }
        }
    }
  }
  for(int i = 0; i < 140; i++){
    for(int j = 0; j < 140; j++){
        if(toRemove[i][j]){
            map[i][j] = '.';
        }
    }
  }
}
  printf("%d", valid);
}