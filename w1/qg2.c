#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <search.h>
#include <string.h>

//#define __USE_GNU 1

int main(int argc, char *argv[]) {
    
    int size, k, i;
    long long input;
    scanf("%d %d", &size, &k);
    
    long long *array = (long long *)calloc(size+1, sizeof(long long));
    long long range = 0;
    hcreate(size * 3 / 2);
    ENTRY e, *found;
    char key[15];
    // read input, store sums-so-far in array
    array[0] = 0;
    for (i = 1; i <= size; i++) {
        scanf("%lli", &input);
        array[i] = array[i-1]+input;
        range += abs(array[i]);
        sprintf(key, "%lli", array[i]);
        e.key = strdup(key);
        e.data = (void *)i;
        hsearch(e, ENTER);
    } 
        
    int count = 0;
    long long power = 1;
    // for each sum but last, search for sum+power in succeeding subarray
    for (i = size; i > 0; i--) {
        if (abs(k) == 1) {
            sprintf(key, "%lli", array[i-1]+1);
            e.key = key;
            found = hsearch(e,FIND);
            if (found && (int)found->data >= i) count++;
            if (k == -1) {
                sprintf(key, "%lli", array[i-1]-1);
                e.key = key;
                found = hsearch(e,FIND);
                if (found && (int)found->data >= i) count++;
            }
        } else {
            for (power = 1; ; ) {
                sprintf(key, "%lli", array[i-1]+power);
                e.key = key;
                found = hsearch(e,FIND);
                if (found && (int)found->data >= i)
                    count++;
                if (abs(power) <= abs(range/k)) power *= k;
                else break;
            }
        }
    }

    printf("%d\n", count);     
    free(array);
    hdestroy();
    return 0;
}
