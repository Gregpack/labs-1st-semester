#include <stdio.h>
#include <string.h>
void swapbiggest(int count, char *nmb) {
    int i=count+1,  mini;
    char min=127;
    char min1=nmb[count];
    int n=strlen(nmb);
    for (i; i<n; i++){
        if (nmb[i]<min && nmb[i]>min1){
          min=nmb[i];
            mini=i;
        }
    }
    int t;
    t = nmb[count];
    nmb[count] = min;
    nmb[mini] = t;
}
void swaptail (int count, char *nmb) {
    int n;
    n=strlen(nmb)-1;
    while (count<n) {
        int t;
        t = nmb[count];
        nmb[count] = nmb[n];
        nmb[n] = t;
        n--;
        count++;
    }
}
int algo (char *nmb)
{
    int i;
    i=strlen(nmb)-2;
    for (i; i>-1; i--) {
        if (nmb[i] < nmb[i + 1]) {
            swapbiggest (i, nmb);
            swaptail(i + 1, nmb);
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[]) {
    char nmb[11];
    if (argc<2)
        scanf("%s", nmb);
    else
        strcpy (nmb, argv [1]);
    while (algo(nmb)!=1)
        puts(nmb);
    printf ("end");
    return 0;
}