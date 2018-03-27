#include <stdio.h>
#include <stdlib.h>

void sort (int *arr, int first, int last) {
    unsigned int a;
    int temp, i, j;
    while (last-first > 1) {
        a=arr[(last-1+first)/2];
        i=first, j=last;
         {
            do {
                while (arr[i]<a)
                    i++;
                while (a<arr[j])
                    j--;

                if (i<=j){
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    i++;
                    j--;
                }
            } while (i<j);
            if (j-first > last - i){
                sort (arr, i, last);
                last=j;
            }
            else {
                sort (arr, first, j);
                first=i;
            }
        }
    }
}

int main() {
   long long int i, n;
    int * arr;
    scanf("%lld", &n);
    arr= (int *) malloc(n*sizeof(int));
   for (i=0; i<n; i++) {
        scanf ("%d", &arr[i]);
    }
    sort (arr, 0, n);
    for (i=0; i<n; i++) {
        printf ("%d ", arr[i]);
    }
    free (arr);
    return 0;
}