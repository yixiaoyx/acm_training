#include <stdio.h>
#include <stdlib.h>

int getLast(long long n) {
    if (n==0) return 1; 
    int digit[] = {8, 4, 2, 6};
    return digit[(n-1)%4];
}

int main(int argc, char *argv[]) {
    long long n;
    scanf("%lli", &n);
    
    n = getLast(n);

    printf("%lli\n", n);
    return 0;
}
