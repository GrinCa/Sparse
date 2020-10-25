#include "mathsr.h"

//Rapid sort implementation
void permute(TYPE *a, TYPE *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void rapid_sort(TYPE *tab, int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permute(&tab[i], &tab[j]);
            }
        }
        permute(&tab[pivot], &tab[j]);
        rapid_sort(tab, first, j - 1);
        rapid_sort(tab, j + 1, last);
    }
}
//END Rapid sort implementation
