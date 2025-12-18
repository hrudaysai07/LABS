#include<stdio.h>
#define size 5
int a[size],top=-1;
void pop();
void push(int value);
void display();
void main()
{
int n,value;
while(1)
{
printf("\n\n MENU \n\n");
printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
printf("\nENTER YOUR CHOICE ");
scanf("%d",&n);
switch(n)
{
case 1:
    printf("\nEnter the value to be instered \n");
    scanf("%d",&value);
    push(value);
    break;
case 2:
    pop();
    break;
case 3:
    display();
    break;
case 4:
    exit(0);
default:
    printf("\nINVALID INPUT\n\n");
    break;
}
}
}
void push(int value)
{
    if(top==size-1)
        printf("\n\nOVERFLOW STACK\n\n");
    else
    {
        top++;
        a[top]=value;
        printf("\nValue pushed \n");
    }
}
void pop()
{
    if(top==-1)
        printf("\n\nUNDERFLOW STACK\n\n");
    else
    {
        printf("\ndeleted element is %d\n",a[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
        printf("\n\nEMPTY STACK\n\n");
    else
    {
        printf("\nSTACK ELEMENTS: \nTOP TO BOTTOM\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",a[i]);
        }
    }
}


