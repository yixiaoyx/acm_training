#include <stdio.h>
#include <stdlib.h>

int isInArray(int a[], int size, int val) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] == val) return 1; 
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int numRk;
    long long numSq;
    scanf("%lli %d", &numSq, &numRk);
    int *row = (int *)calloc(numRk, sizeof(int));
    int *col = (int *)calloc(numRk, sizeof(int));
    int i, r, c, attkdR = 0, attkdC = 0;
       
    long long notAttkd = numSq*numSq;
    for (i = 0; i < numRk; i++) {
        scanf("%d %d", &r, &c);
        if (isInArray(row, i ,r)) {
            // if c is in col array, nothing to do
            if (!isInArray(col, i, c)) {
                notAttkd -= numSq - attkdR;
                attkdC++;
            }
        } else {
            if (isInArray(col, i, c)) {
                notAttkd -= numSq - attkdC;
                attkdR++;
            } else {
                notAttkd -= 2*numSq-1 - attkdR - attkdC;
                attkdR++;
                attkdC++;
            }
        }
        row[i] = r;
        col[i] = c;
            
        printf("%lli ", notAttkd);
    }

    printf("\n");
    free(row);
    free(col);
    return 0;
}
