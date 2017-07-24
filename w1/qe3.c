#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int numRk;
    long long numSq;
    scanf("%lli %d", &numSq, &numRk);
    char *row = (char *)calloc(numSq, sizeof(char));
    char *col = (char *)calloc(numSq, sizeof(char));
    int i, r, c, attkdR = 0, attkdC = 0;
       
    long long notAttkd = numSq*numSq;
    for (i = 0; i < numRk; i++) {
        scanf("%d %d", &r, &c);
        if (row[r-1]) {
            // if c is also visited, nothing to do
            if (!col[c-1]) {
                notAttkd -= numSq - attkdR;
                attkdC++;
            }
        } else {
            if (col[c-1]) {
                notAttkd -= numSq - attkdC;
                attkdR++;
            } else {
                notAttkd -= 2*numSq-1 - attkdR - attkdC;
                attkdR++;
                attkdC++;
            }
        }
        row[r-1] = 1;
        col[c-1] = 1;
            
        printf("%lli ", notAttkd);
    }

    printf("\n");
    free(row);
    free(col);
    return 0;
}
