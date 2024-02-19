#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* next;
};
typedef struct Node node;

node* top = NULL;

node *newnode(int val)
{
    node*p;
    p=(node*)malloc(sizeof(node));
    p->info=val;
    p->next=NULL;
    return(p);
}

int is_empty()
{
    if (top == NULL)
      return 1;
    return 0;
}
void push(int val)
{
    node* p = newnode(val);
    p->next = top;
    top=p;
}

int pop()
{
  if (!is_empty())
  {
    int ele = top->info;
    node* old = top;
    top = top->next;
    free(old);
    return ele;
  }
  return -1;
}

int peek()
{
if (!is_empty())
  return top->info;
return -1;
}

void display()
{
  node* curr = top;
  while (curr != NULL)
  {
    printf("%d ", curr->info);
    curr = curr->next;
  }
  printf("\n");
}

void main()
{
int ch,ele;

do
{
  printf("Enter your option: ");
  printf("\n1.Push\n2.Pop\n3.Peek\n4.Display Stack\n5.Is Empty?\n6.Exit\n");
  scanf("%d", &ch);

  switch(ch)
  {
    case 1:printf("Enter the element to push: ");
           scanf("%d", &ele);
           push(ele);
           break;
    case 2:if(is_empty())
           {
             printf("Stack is empty\n");
           }
           else
           {
             int p = pop();
             printf("%d popped successfully\n", p);
           }
           break;
    case 3:if (is_empty())
            {
            printf("Stack is empty!!\n");
            }
            else
            {
            int q = peek();
            printf("%d peeked successfully\n", q);
            }
            break;
    case 4:if (is_empty())
             printf("Stack is empty!!\n");
           else
             display();
           break;
    case 5:if (is_empty())
             printf("Stack is Empty!!\n");
           else
             printf("Stack is not Empty!\n");
           break;
    case 6:break;
    default:printf("Invalid choice\n");
   }
   printf("\n\n");
 }while (ch != 6);
}

