#ifndef HEADER_SPARSE

#define HEADER_SPARSE
#define TYPE double
#define ZERO 0.0

typedef struct SR{
  int n_rows,n_columns;
  int dimension;
  unsigned long long *index_arr;
  TYPE *values;
} SR;

SR   SR_INIT(int , int);
TYPE SR_GET(SR, unsigned long long, unsigned long long);
void SR_DISPLAY(SR);
void SR_LOAD_FROM_FILE(const char*, SR*);
void SR_ALLOC(SR*, int);
void SR_FREE(SR*);

#endif
