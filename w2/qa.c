#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long long power[11] = {0};
    long long a = 1378;
    long long x = 1;
    int n;
    scanf("%d", &n);

    int i;
    for (i = 1; i <= 10; i++) {
        power[i] = a;
        a *= a;
    }

    for (i = 0; i<10; i++) {
        if (n & (1<<i)) {
            x *= power[i+1];
        }
        x = x%10;
    }
    printf("%lli\n", x%10);
    return 0;
}
