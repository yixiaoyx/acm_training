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

void hcreate(int size) {
    htable = (ENTRY *)calloc(size, sizeof(ENTRY));
    hsize = size;
}

int main (void) {
    hcreate(2);
    if (htable[0].data==0) printf("is empty\n");    
    return 0;
}
