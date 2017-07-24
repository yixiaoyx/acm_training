#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int houses[3] = {0};

    int i;
    for (i = 0; i < 3; i++)
        scanf("%d", &houses[i]);

    int min = houses[0], max = houses[0];
    for (i = 1; i < 3; i++) {
        if (houses[i] > max)
            max = houses[i];
        else if (houses[i] < min)
            min = houses[i];
    }
    printf("%d\n", max-min);

    return 0;
}
