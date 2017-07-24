#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char name[101];
    scanf("%s", name);

    int len = strlen(name);
    int cur = 0, pre = 0, i, diff, count = 0;
    for (i = 0; i < len; i++) {
        pre = cur;
        cur = name[i]-'a';
        diff = abs(cur - pre);
        count += (diff > 13)? 26-diff : diff;

    }

    printf("%d\n", count);



    return 0;
}
