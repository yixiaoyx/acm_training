// still slow when multiple sums are equal 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ENTER 1
#define FIND 0
#define P 196613

typedef struct _entry {
    char *key;
    int data;
} ENTRY;

ENTRY *htable = NULL;
int hsize = 0;
int count = 0;

void hcreate(int size) {
    htable = (ENTRY *)calloc(size, sizeof(ENTRY));
    //assert(htable != NULL);
    hsize = size;
}

ENTRY *hsearch(ENTRY e, int action) {
    long long key = atoll(e.key);
    long long idx = key%P;
    ENTRY *ret = NULL;
    if (idx < 0) idx += P;
    if (idx >= hsize) idx = idx%hsize;
    int i;
    //printf("index = %lli, hsize = %d, e.key=%s\n", idx, hsize, e.key);
    if (htable[idx].key == NULL) {
        if (action == ENTER) {
            htable[idx].key = e.key;
            htable[idx].data = e.data;
            return &htable[idx];
        } else {
            return NULL;
        } 
    } else if (strcmp(htable[idx].key, e.key)==0) {
        if (action == ENTER && htable[idx].data==e.data)
            return &htable[idx];
        if (action == FIND)
            ret = &htable[idx];
    }
        for (i = (idx+1)%hsize; i != idx; i = (i+1)%hsize) {
            if (htable[i].key == NULL) {
                if (action == ENTER) {
                    htable[i].key = e.key;
                    htable[i].data = e.data;
                    return &htable[i];
                } else {
                    return ret;
                } 
            }
            if (strcmp(htable[i].key, e.key)==0) {
                if (action == ENTER && htable[i].data==e.data)
                    return &htable[i];
                if (action == FIND) {
                    count++;
                    ret = &htable[i];
                } 
            } 
        }
        return ret;
}

void hdestroy(void) {
    if (htable == NULL) return;
    int i;
    for (i = 0; i < hsize; i++) {
        if (htable[i].key) free(htable[i].key);
    }
    free(htable);    
}

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
        e.data = i;
        hsearch(e, ENTER);
    } 
    
    long long power = 1;
    // for each sum but last, search for sum+power in succeeding subarray
    for (i = size; i > 0; i--) {
        if (abs(k) == 1) {
            sprintf(key, "%lli", array[i-1]+1);
            e.key = key;
            found = hsearch(e,FIND);
            if (found && found->data >= i) count++;
            if (k == -1) {
                sprintf(key, "%lli", array[i-1]-1);
                e.key = key;
                found = hsearch(e,FIND);
                if (found && found->data >= i) count++;
            }
        } else {
            for (power = 1; ; ) {
                sprintf(key, "%lli", array[i-1]+power);
                e.key = key;
                found = hsearch(e,FIND);
                if (found && found->data >= i)
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
