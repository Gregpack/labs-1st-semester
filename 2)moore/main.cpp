#include <stdio.h>
#include <string.h>
void alphabet (int *alphabet, char *templ) {
    int i;
    int tplen=strlen(templ);
    for (i=0; i<256; i++)
        alphabet[i]=tplen;
    for (i=0; i<tplen-1; i++) {
        alphabet[templ[i]] = tplen - i - 1;
    }
}
int moore (char *str, char *templ, int *alphabet)
{
    int j, l;
    int tplen=strlen (templ);
    int strl=strlen (str);
    int i=tplen-1;
    if (tplen>strl) return -1;
    do {
        j=tplen-1;
        l=i;
        printf ("%d ",l+1);
        while (j>=0 && templ[j]==str[l]) {
            j--;
            l--;
            if (j>=0)
                printf ("%d ", l+1);
        }
        if (j<0)
            break;
        i=i+alphabet[str[i]];
    } while(i<strl);
    if (j>=0) return -1;
    else return (l+2);
}
int main (int argc, char *argv[]) {
    char str[100000], tpl[16];
    int ent[256];
    if (argc>2){
        strcpy (tpl, argv[2]);
        for (int i=3; i<argc; i++){
            strcat(str, ' ' + argv[i]);
        }
    }
    else {
    gets(tpl);
    gets(str);
    }
    alphabet (ent, tpl);
    printf ("\n%d", moore (str, tpl, ent));
    return 0;
}
