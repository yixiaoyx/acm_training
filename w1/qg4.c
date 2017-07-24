#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include <string.h>

gint compare (gconstpointer a, gconstpointer b) {
    return *(long long *)a-*(long long *)b;
}

int main(int argc, char *argv[]) {
    
    int size, k, i;
    long long input;
    scanf("%d %d", &size, &k);
    
    long long *array = (long long *)calloc(size+1, sizeof(long long));
    long long range = 0;
    GTree *tree = g_tree_new(compare);
    // read input, store sums-so-far in array
    array[0] = 0;
    for (i = 1; i <= size; i++) {
        scanf("%lli", &input);
        array[i] = array[i-1]+input;
        range += abs(array[i]);
        g_tree_insert(tree, &array[i], (gpointer)i);
    } 
        
    int count = 0;
    long long power = 1, key;
    gpointer found = NULL;
    // for each sum but last, search for sum+power in succeeding subarray
    for (i = size; i > 0; i--) {
        if (abs(k) == 1) {
            key = array[i-1]+1;
            found = g_tree_lookup(tree, &key);
            if (found && (int)found >= i) count++;
            if (k == -1) {
                key = array[i-1]-1;
                found = g_tree_lookup(tree, &key);
                if (found && (int)found >= i) count++;
            }
        } else {
            for (power = 1; ; ) {
                key = array[i-1]+power;
                found = g_tree_lookup(tree, &key);
                if (found && (int)found >= i) count++;
                if (abs(power) <= abs(range/k)) power *= k;
                else break;
            }
        }
    }

    printf("%d\n", count);     
    free(array);
    g_tree_destroy(tree);
    return 0;
}
