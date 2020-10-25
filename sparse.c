#include <stdio.h>
#include <stdlib.h>

#include "mathsr.h"
#include "sparse.h"
#include "iolib.h"


SR SR_INIT(size_t n_rows, size_t n_columns){
  SR sr;
  sr.n_rows = n_rows; sr.n_columns = n_columns;
  return sr;
}

void SR_ALLOC(SR* sr, int size){
  unsigned long long *index_arr = calloc(size, sizeof(unsigned long long));
  TYPE *values = calloc(size,sizeof(TYPE));
  sr->index_arr = index_arr;
  sr->values = values;
}

void SR_FREE(SR* sr){
  free(sr->index_arr);
  free(sr->values);
}

TYPE SR_GET(SR sr, unsigned long long i, unsigned long long j){
  unsigned long long idx = i << 32 | j;
  size_t a = 0;
  size_t b = sr.dimension - 1;
  size_t c = 0;
  while (a != b) {
    c = (b+a)/2;
    if (idx < sr.index_arr[c]) {
      b = c;
    }else if (idx > sr.index_arr[c]) {
      a = c;
    }else if (idx == sr.index_arr[c]) {
      break;
    }
  }
  if (idx == sr.index_arr[c]) {
    return sr.values[c];
  }else{
    return ZERO;
  }
}

void SR_LOAD_FROM_FILE(const char* filename, SR* sr){
  LOAD_FROM_FILE(filename, sr, "", 1);
}


void SR_DISPLAY(SR sr){
  printf("Sparse matrix with [n=%d,m=%d,dimension=%d]\n", sr.n_rows, sr.n_columns, sr.dimension);
}
