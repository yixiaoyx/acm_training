#include <stdio.h>
#include <stdlib.h>

//char board[100000][100000] = {{'\0'}};

int main(int argc, char *argv[]) {
    int numRk;
    long long numSq, attkd = 0;
    scanf("%lli %d", &numSq, &numRk);
    int i, j, r, c;
    long long total = numSq*numSq;
    char **board = (char **)calloc(total, sizeof(char));

    for (i = 0; i < numRk; i++) {
        scanf("%d %d", &r, &c);
        for (j = 0; j < numSq; j++) {
            if (board[r-1][j]==0) {
                board[r-1][j] = 1;
                attkd++;
            }
            if (board[j][c-1]==0) {
                board[j][c-1] = 1;
                attkd++;
            }
        }
        printf("%lli ", total-attkd);
    }

    printf("\n");
    free(board);
    return 0;
}
