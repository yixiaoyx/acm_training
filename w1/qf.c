#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

/*
void printMatrix(int m[][100], int size) {
    printf("matrix is:\n");
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

}
*/

int main(int argc, char *argv[]) {
    
    int size, i, val;
    scanf("%d", &size);
    int matrix[100][100] = {{0}};
    // store row sums instead of original vals in matrix
    for (i = 0; i < size*size; i++) {
        scanf("%d", &val);
        matrix[i/size][i%size] = (i%size==0)? val : val+matrix[i/size][i%size-1];
    }
    //printMatrix(matrix, size);
    
    int lC, rC, uR, lR, sum, largest = INT_MIN;
    for (lC=0; lC<size; lC++) {
        for (rC=lC; rC<size; rC++) {
            // apply max subarray sum algo on row sums
            sum = 0;
            for (uR = 0, lR = 0; uR < size && lR < size; ) {
                sum += matrix[lR][rC] - ((lC==0)? 0:matrix[lR][lC-1]);
                //printf("lc=%d rC=%d uR=%d lR=%d sum=%d ", lC, rC, uR, lR, sum);
                if (sum < 0) {
                    uR = lR+1;
                    lR = uR;
                    sum = 0;
                } else {
                    largest = max(largest, sum);
                    lR++;
                }
                //printf("largest=%d\n", largest);
            }
        }
    }

    printf("%d\n", largest);
   
    return 0;
}
