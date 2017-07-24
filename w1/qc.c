#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

int main(int argc, char *argv[]) {
    
    int ch;
    scanf("%d", &ch);
    
    while (ch != 0) {
        int *array = (int *)calloc(ch, sizeof(int));
        int i;
        for (i = 0; i < ch; i++)
           scanf("%d", &array[i]); 
        
        int start, end, sum = 0, largest = INT_MIN;
        for (start = 0, end = 0; start < ch && end < ch; ) {
            sum += array[end];
            if (sum < 0) {
                start = end+1;
                end = start;
                sum = 0;
            } else {
                largest = max(largest, sum);
                end++;
            }
        }

        if (largest <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", largest);
        
        free(array);
        scanf("%d", &ch);
    }
    return 0;
}
