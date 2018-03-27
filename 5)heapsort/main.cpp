#include <stdio.h>  // 0 1 2 3 4
#include <stdlib.h> // 5 4 3 2 1
void smallleaf (int *arr, int big, int small){  //если у элемента только один лист
    if (arr[big]< arr[small]) {                 //сравниваем лист с элементом, меняем местами если надо
        int t=arr[big];
        arr[big]=arr[small];
        arr[small]=t;
    }
}
void leaf (int *arr, int big, int size){ //если у элемента 2 листа
    int small1;
    int small2;
    while (true){
        small1 = big*2+1;
        small2 = big*2+2;
        if (arr[big]<arr[small1] || arr[big]<arr[small2]){
            if (arr[small1]<arr[small2]){
                int t=arr[big];
                arr[big]=arr[small2];
                arr[small2]=t;
                if (small2*2+1<=size-1) {
                    if (small2*2+2<=size-1) {
                        big = small2;
                    }
                    else {
                        smallleaf (arr, small2, small2*2+1);
                        break;
                    }
                }
            }
            else
            {
                int t=arr[big];
                arr[big]=arr[small1];
                arr[small1]=t;
                if (small1*2+1<=size-1) {
                    if (small1*2+2<=size-1) {
                        big = small1;
                    }
                    else {
                        smallleaf (arr, small1, small1*2+1);
                        break;
                    }
                }
            }
        }
        else
            break;
    }
}
void heapsort (int *arr, int n){
    do {
        int t=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=t;
        n--;
        if (n>2)
            leaf (arr, 0, n);
        if (n==2)
            smallleaf(arr, 0, 1);
    } while(n>=2);

}
void buildheap (int *arr, int n) {
        for (int i = (n - 2) / 2; i >= 0; i--) {
            if (i * 2 + 1 <= n - 1) {
                if (i * 2 + 2 <= n - 1)
                    leaf(arr, i, n);
                else
                    smallleaf(arr, i, i * 2 + 1);
            }
        }
}

int main() {
    int n, i;
    int * arr;
    scanf ("%d", &n);
    arr = (int *)malloc (n*sizeof(n));
    for (i=0; i<n; i++){
        scanf ("%d", &arr[i]);
    }
    buildheap (arr, n);
    heapsort (arr, n);
    for (i=0; i<n; i++){
        printf ("%d ", arr[i]);
    }
    return 0;
}