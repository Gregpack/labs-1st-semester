#include <stdio.h>
#include <string.h>
int rabin (char *str, char *templ){
    int alpha=36;
    int p=7, nmb3=1;
    int i, j=0;
    int nmb1=0, nmb2=0;
    //int a;
    int len1=strlen (str);
    int len2=strlen (templ);
    for (i=1; i<len2; i++){
        nmb3=(nmb3*alpha)%p;
    }
    for (i=0; i<len2; i++) {
        nmb1=(nmb1*alpha+str[i])%p;
        nmb2=(nmb2*alpha+templ[i])%p;
    }
    for (i=0; i <= len1 - len2; i++){
        if (nmb1==nmb2){
            j=0;
            while (str[i+j]==templ[j]&&(i+j)<len1){
                j++;
            }
            if (j==len2)
                return i+1;
        }
        //if (i!=(len1+len2))
           // a=str[i+len2];
        nmb1=(alpha*(nmb1-nmb3*str[i])+str[i+len2])%p;
        if (nmb1<0) nmb1=nmb1+p;
    }
    return -1;
}
int main() {
    char templ[100], str[1000];
    gets (str);
    gets (templ);
    printf ("%d", rabin (str, templ));
    return 0;
}