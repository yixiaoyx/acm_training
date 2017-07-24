#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
int isPower(long long num, int k) {
    if (k==1)
        return num==1;
    else if (k==-1)
        return num==1 || num==-1;

    if (num == 0) return 0;

    double p = log(abs(num))/log(abs(k));
    if (pow(k, (int)p)==num || pow(k, (int)p+1)==num) return 1;
    return 0;
}
*/


int isPower(long long num, int k) {
    if (k==1)
        return num==1;
    else if (k==-1)
        return num==1 || num==-1;
    
    if (num==0) return 0;

    while (num % k == 0) {
        num /= k;
    }
    return num==1;
}


int main(int argc, char *argv[]) {
    
    int size, k, i, j;
    long long input;
    scanf("%d %d", &size, &k);
    long long *array = (long long *)calloc(size+1, sizeof(long long));
    /*for (i = 0; i < size; i++)
       scanf("%d", &array[i]); */
    array[0] = 0;
    for (i = 1; i <= size; i++) {
        scanf("%lli", &input);
        array[i] = array[i-1]+input;
    } 

    int count = 0;
    for (i = size; i > 0; i--) {
        for (j = i; j <= size; j++) {
            count += isPower(array[j]-array[i-1], k);
        }
    }

    printf("%d\n", count);     
    free(array);
    
    return 0;
}
