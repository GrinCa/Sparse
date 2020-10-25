#include <stdio.h>
#include <stdlib.h>

#include "sparse.h"


int main(int argc, char const *argv[]) {
  SR matrix;
  SR_LOAD_FROM_FILE("Data/SR.txt", &matrix);
}
