#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int priority(char x){
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    return 0;
}

int main(){
    char exp[50];
    int i=0;
    
    printf("Enter infix expression: ");
    scanf("%s",exp);

    while(exp[i]!='\0'){
        
        if(isalnum(exp[i]))   // operand
            printf("%c",exp[i]);

        else{                 // operator
            while(top!=-1 && priority(stack[top])>=priority(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }

        i++;
    }

    while(top!=-1)
        printf("%c",pop());

    return 0;
}