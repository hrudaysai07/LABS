#include<stdio.h>
#include<string.h>
char infix[20],stack[20],postfix[20],symbol,temp;
int index=0,top=-1,pos=0,len;
void push(char element);
void infixtopostfix();
char pop();
int precedence(char operator);
void push(char element)
{
    if(top==19)
    {
        printf("overflow stack");
    }
    else
    {
        top++;
        stack[top]=element;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("UNDERFLOW STACK");
    }
    else
    {
        return stack[top--];
    }
}
int precedence(char operator)
{
    switch(operator)
    {
        case'^': return(3);break;

        case'/':
        case'*': return(2);break;

        case'+':
        case'-': return(1);break;

        default:return(0);break;
    }
}
void infixtopostfix()
{
    push('#');
    len=strlen(infix);
    while(index<len)//for(index=o,index<len,index++);
    {
        symbol=infix[index];
        switch(symbol)
        {
            case'(': push(symbol);break;

            case')':temp=pop();
                     while(temp!='(')
                      {
                          postfix[pos++]=temp;//postfix[pos]=temp;pos++;
                          temp=pop();
                      }
                      break;

            case'+':
            case'-':
            case'/':
            case'*':
            case'^':while(precedence(stack[top])>=precedence(symbol))
                    {
                        postfix[pos++]=pop();
                   }
                   push(symbol);
                   break;
        default:postfix[pos++]=symbol;break;
        }
        index++;
    }
        while(top>=0)
        {
            temp=pop();
            postfix[pos++]=temp;
        }
}

void main()
{
    printf("Enter the infix notation\n");
    scanf("%s",infix);//gets(infix);
    infixtopostfix();
    printf("postfix notation\n");
    printf("%s",postfix);
}


