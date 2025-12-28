#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
};
struct node *top=NULL;

struct node *front=NULL, *rear=NULL;

void push(){
  struct node *newnode;
  int value;
  newnode=(struct node*)malloc(sizeof(struct node));
  if (newnode==NULL){
    printf("Memory allocation failed\n");
    return;
  }
  printf("Enter value to push: ");
  scanf("%d",&value);
  newnode->data=value;
  newnode->next=top;
  top=newnode;
  printf("%d pushed to stack\n",value);
}

void pop(){
  struct node *temp;
  if (top==NULL){
    printf("Stack underflow\n");
    return;
  }
  temp=top;
  printf("%d popped from stack\n",top->data);
  top=top->next;
  free(temp);
}

void display_stack(){
  struct node *temp;
  if (top==NULL){
    printf("Stack is empty\n");
    return;
  }
  temp=top;
  printf("Stack elements: ");
  while (temp!=NULL){
    printf("%d -> ",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

void enqueue(){
  struct node *newnode;
  int value;
  newnode=(struct node*)malloc(sizeof(struct node));
  if (newnode==NULL){
    printf("Memory allocation failed\n");
    return;
  }
  printf("Enter value to enqueue: ");
  scanf("%d",&value);
  newnode->data=value;
  newnode->next=NULL;
  if (rear==NULL){
    front=rear=newnode;
  }
  else{
    rear->next=newnode;
    rear=newnode;
  }
  printf("%d enqueued to queue\n",value);
}

void dequeue(){
  struct node *temp;
  if (front==NULL){
    printf("Queue underflow\n");
    return;
  }
  temp=front;
  printf("%d dequeued from queue\n",front->data);
  front=front->next;
  if (front==NULL){
    rear=NULL;
  }
  free(temp);
}

void displayQueue() {
  struct node *temp = front;
  if (front == NULL) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main(){
  int choice;
  printf("1. Push to Stack\n2. Pop from Stack\n3. Display Stack\n4. Enqueue to Queue\n5. Dequeue from Queue\n6. Display Queue\n7. Exit\n");
  while(1){
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        display_stack();
        break;
      case 4:
        enqueue();
        break;
      case 5:
        dequeue();
        break;
      case 6:
        displayQueue();
        break;
      case 7:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}
