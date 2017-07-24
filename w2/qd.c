#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, ch, i, nut = 0, count = 1, buffer = 0;
    long long total = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ch);
        if (ch==0 && nut==0) continue;
        if (ch==1) {
            nut++;
            count += buffer;
            total *= count;
            buffer = 0;
            count = 1;
        } else {
            buffer++;
        }
    }

    if (nut==0) total = 0;
    printf("%lli\n", total);

    return 0;
}
