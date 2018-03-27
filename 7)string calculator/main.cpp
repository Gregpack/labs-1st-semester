#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

int priority (char elem){
    if (elem == '(' || elem == ')')
        return 0;
    if (elem == '+' || elem == '-')
        return 1;
    if (elem == '*' || elem == '/')
        return 2;
    if (elem == '^')
        return 3;
}
int power (int a, int b) {
    int c=1;
    for (int i=0; i<b; i++){
        c=c*a;
    }
    return c;
}

struct list {
    double value;
    struct list *next;
};

typedef struct stack {
    struct list *top;
} stack;

void makeNull (stack *stk) {
    struct list *lst;
    while (stk->top) {
        lst = stk->top;
        stk->top=lst->next;
        free(lst);
    }
}

stack *create () {
    stack * stk;
    stk = (stack *) malloc (sizeof(stack));
    stk->top = NULL;
    return stk;
}

double peek (stack *stk) {
    if (stk->top)
        return (stk->top->value);
    else
        return 0;
}

double pop (stack *stk) {
    double elem;
    struct list *lst;
    lst=stk->top;
    elem=lst->value;
    stk->top=lst->next;
    free (lst);
    return elem;
}

void push (stack *stk, double elem) {
    struct list *lst;
    lst=(struct list*) malloc (sizeof (struct list));
    lst->value = elem;
    lst->next = stk->top;
    stk->top=lst;
}

double ifEmpty (stack *stk) {
    return (stk->top == NULL);
}


double calc (char *polska, unsigned int size) {
    int i = 0;
    double temp=0, temp1, temp2;
    stack *stk;
    stk = create ();
    for (i = 0; i<size; i++) {
        if (polska[i] == '[') {
            i++;
            while (polska[i]!=']') {
                temp=10*temp+(polska[i]-'0');
                i++;
            }
            push(stk, temp);
            temp=0;
        }
        else {
            switch (polska[i]) {
                case '+' :
                    push(stk, pop(stk)+pop(stk));
                    break;
                case '-' :
                    temp1=pop(stk);
                    temp2=pop(stk);
                    push (stk, temp2-temp1);
                    break;
                case '*' :
                    push (stk, pop(stk)*pop(stk));
                    break;
                case '/' :
                    temp1=pop(stk);
                    temp2=pop(stk);
                    if (temp1==0){
                        printf ("DO NOT DIVIDE BY ZERO \n");
                        return 666;
                    }
                    push (stk, temp2/temp1);
                    break;
                case '^' :
                    temp1=pop(stk);
                    temp2=pop(stk);
                    push (stk, power (temp2, temp1));

            }
        }
    }
    return pop (stk);
}
double opz (char *str, char *out){
    struct stack *stk;
    stk = create ();
    int i = 0;
    unsigned int j = 0;
    for (i = 0; i < strlen (str); i++) {
        if (str[i]<= '9' && str[i] >= '0') {
            out[j]='[';
            j++;
            while (str[i]<= '9' && str[i] >= '0') {
                out[j] = str[i];
                i++;
                j++;
            }
            i--;
            out[j]=']';
            j++;
        }
        else {
            if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^') {
                while (priority(str[i]) <= priority ((char)(peek(stk)))) {
                    out[j] = (char)pop(stk);
                    j++;
                }
                push(stk, (double)str[i]);
            }
            else {
                if (str[i] == '(')
                    push (stk, (double)str[i]);
                else {
                    if (str[i] == ')')
                        while (((char)peek (stk)) != '(') {
                            out[j]=(char)pop(stk);
                            j++;
                        }
                    pop(stk);
                }
            }
        }
    }
    while(ifEmpty(stk) != 1) {
        out[j] = (char)pop(stk);
        j++;
    }
    out[j]=0;
    puts (out);
    return calc (out, j);
}

int main (void) {
    char str [MAX];
    char out [MAX];
    unsigned i=0;
    gets (str);
    printf ("%f", opz (str, out));
    return 0;
}