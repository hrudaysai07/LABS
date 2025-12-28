#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

struct node* create (struct node *head) {
  struct node *create(struct node *head) {
    struct node *temp, *newnode;
    int n,i,val;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for (i=0;i<n;i++) {
      newnode = (struct node*)malloc(sizeof(struct node));
      printf("Enter data:");
      scanf("%d",&val);
      newnode->data = val;
      newnode->next = NULL;
      if (head == NULL) {
        head = temp = newnode;
      } 
      else {
        temp=head;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = newnode;
      }
    }
    return head;
  }
}

void display(struct node *head) {
  struct node *temp;
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  while(temp!= NULL) {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

struct node *sort(struct node *head) {
  struct node *i, *j;
  int temp;
  for (i=head; i!=NULL; i=i->next) {
    for (j=i->next; j!=NULL; j=j->next) {
      if (i->data > j->data) {
        temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
    }
  }
  return head;
}

struct node* reverse(struct node *head) {
  struct node *prev = NULL, *current = head, *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

struct node *concatenate(struct node *head1, struct node *head2) {
  struct node *temp;
  if (head1 == NULL) return head2;
  temp = head1;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = head2;
  return head1;
}

int main() {
  int choice;
  while (1) {
    printf("1. Create List 1\n2. Create List 2\n3. Display List 1\n4. Display List 2\n5. Sort List 1\n6. Sort List 2\n7. Reverse List 1\n8. Reverse List 2\n9. Concatenate Lists\n10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        head1 = create(head1);
        break;
      case 2:
        head2 = create(head2);
        break;
      case 3:
        printf("List 1: ");
        display(head1);
        break;
      case 4:
        printf("List 2: ");
        display(head2);
        break;
      case 5:
        head1 = sort(head1);
        printf("List 1 sorted.\n");
        break;
      case 6:
        head2 = sort(head2);
        printf("List 2 sorted.\n");
        break;
      case 7:
        head1 = reverse(head1);
        printf("List 1 reversed.\n");
        break;
      case 8:
        head2 = reverse(head2);
        printf("List 2 reversed.\n");
        break;
      case 9:
        head1 = concatenate(head1, head2);
        head2 = NULL;
        printf("Lists concatenated.\n");
        break;
      case 10:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }  return 0;
}
