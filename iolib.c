#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sparse.h"

#define STR_LENGTH 10

void LOAD_FROM_FILE(const char* filename, SR* sr, const char* format, int header_size){
  FILE* fid = fopen(filename, "r");
  if (fid == NULL) {
    printf("ERROR::SR_LOAD_FROM_FILE -> FILE returned a NULL pointer\n");
    exit(1);
  }
  int eol_counter = 0;
  int incr=0;
  int depth = 0;
  int n_line = 0;
  int str_counter = 0;
  unsigned long long n = 0;
  unsigned long long m = 0;
  char c;
  char line[STR_LENGTH];
  while (!feof(fid)) {
    c = fgetc(fid);
    if (c=='\n') {
      incr=0;
      eol_counter++;
      if (eol_counter <= header_size) {
        depth = atoi(line);
        SR_ALLOC(sr, depth);
      }
      memset(line,'\0',STR_LENGTH*sizeof(char));
      break;
    }
    else if(c=='\t'){
      incr=0;
      str_counter%=3;
      if (str_counter == 0) {
        n = atoi(line);
      }else if (str_counter == 1) {
        m = atoi(line);
      }else{
        sr->values[n_line] = strtod(line, NULL);
        sr->index_arr[n_line] = n << 32 | m;
        n_line++;
      }
      str_counter++;
      memset(line,'\0',STR_LENGTH*sizeof(char));
      break;
    }
    line[incr] = c;
    incr++;
  }
  fclose(fid);
}
