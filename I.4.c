#include <stdio.h>
#include <stdlib.h>

int CharacterCounter(char *namefile){
    FILE *fp = fopen(namefile, "r");
    char ch;
    int nr = 0;
    while (!feof(namefile))){
        fscanf(fp, "%", &ch);
        nr++;
    }
    return nr;
}

int main()
{
   printf("%d", CharacterCounter("data.txt"));
    return 0;
}
