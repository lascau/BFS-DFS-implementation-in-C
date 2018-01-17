#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[1000];
    int i;
    FILE *fp = fopen("data.txt", "r");
    for (i = 0; i < 1000; i++)
        fscanf(fp, "%d", &arr[i]);
    int medie = 0;
    for (i = 0; i < 1000; i++)
        medie += arr[i];
    medie /= 1000;
    int nr = 0;
    for (i = 0; i < 1000; i++)
        if (arr[i] > medie)
            nr++;
    printf("%d", nr);
    return 0;
}
