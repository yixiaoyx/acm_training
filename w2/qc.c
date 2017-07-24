#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    int board[1001][1001] = {{0}};
    int row, col, count = 0;
    int linecount1 = 0, linecount2 = 0, linecount3 = 0, linecount4 = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &row, &col);
        board[row][col] = 1;
    }

    for (i = 2; i <= 1001; i++) {
        linecount1 = 0;
        linecount2 = 0;
        linecount3 = 0;
        linecount4 = 0;
        for (j = i-1; j >= 1; j--) {
            if (board[j][i-j]==1) {
                linecount1++;        
            }
            if (i < 1001 && board[1001-i+j][1001-j]==1) {
                linecount2++;
            }
            if (board[j][1001-i+j]==1) {
                linecount3++;
            }
            if (i < 1001 && board[1001-i+j][j]==1) {
                linecount4++;
            }
        }
        count += (linecount1==0||linecount1==1)? 0:linecount1*(linecount1-1)/2;
        count += (linecount2==0||linecount2==1)? 0:linecount2*(linecount2-1)/2;
        count += (linecount3==0||linecount3==1)? 0:linecount3*(linecount3-1)/2;
        count += (linecount4==0||linecount4==1)? 0:linecount4*(linecount4-1)/2;
    }

    printf("%d\n", count);

    return 0;
}
