#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

int main(int argc, char *argv[]) {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int *array = (int *)calloc(n, sizeof(int));
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    int sum = 0, greatest = INT_MIN;
/*    for (i = 0; i < n && greatest < m; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            if (sum + array[j] > m)
                break;
            sum += array[j];
        }
        greatest = max(greatest, sum);
    
    }
*/
    for (i = 0, j = 0; i < n && j < n && greatest < m; j++) {
        sum += array[j];
        while (sum > m)
            sum -= array[i++];
      
        greatest = max(greatest, sum);
        
    }
    
    printf("%d\n", greatest);

    free(array);
    return 0;
}
