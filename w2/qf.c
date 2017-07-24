#include <stdio.h>
#include <stdlib.h>

#define swap(A,i,j) \
            {long long t; t = A[i]; A[i] = A[j]; A[j] = t;}

/*
void pa(long long a[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%lli ", a[i]);

    printf("\n");
}

void medofthree(long long a[], int lo, int hi) {
   int mid = (lo+hi)/2;
   if (a[mid] > a[lo]) swap(a, lo, mid);
   if (a[hi] > a[mid]) swap(a, hi, mid);
   if (a[mid] > a[lo]) swap(a, lo, mid);
   swap(a, lo+1, mid);
}

int partition(long long a[], int lo, int hi) {
   long long v = a[lo];
   int  i = lo+1, j = hi;
   while(1) {
         while (a[i]>=v && i < j) i++;
         while (v>=a[j] && j > i) j--;
         if (i >= j) break;
         //printf("swapping #%d and #%d\n", i, j);
         swap(a,i,j);
   }
   j = (a[i]>=v)? i : i-1;
   swap(a,lo,j);
   return j;
}


void qselect(long long a[], int lo, int hi, int k) {
    if (hi <= lo) return;
    medofthree(a, lo, hi);
    pa(a, hi+1);
    int i = partition(a, lo+1, hi-1);
    if (k-1 < i) qselect(a, lo, i-1, k);
    else if (k-1 > i) qselect(a, i+1, hi, k-i-1);
    else return;
}
*/

int cmpfunc (const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}

int main(int argc, char *argv[]) {
    int n, i, count=0;
    long long product = 1;
    scanf("%d", &n);
    long long *array = calloc(n*n, sizeof(long long));
    long long *dup = calloc(n+1, sizeof(long long));
    long long *fac = calloc(n+1, sizeof(long long));
    for (i = 0; i < n*n; i++) {
        scanf("%lli", &array[i]);
    }

    qsort(array, n*n, sizeof(long long), cmpfunc);

    fac[0] = array[0];
    for (i = 0, count = 0; i < n*n-1; i++) {
        dup[count]++;
        if (array[i]!=array[i+1]) {
            fac[++count] = array[i+1];
        }
    }
    dup[count]++;

    for(i = 0; i < count; i++) {
        if (*(array+dup[i]) % *array == 0) dup[i]--;
    }


    for (i = n*n-1, count = 0; i >=0 && count < n; i--) {
        printf("%lli ", array[i]);
        count++;
        while (array[i]==array[i-1]) {
            i--;
        }
    }
    printf("\n");

    return 0;
}
