#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;
node *newnode(int val)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = NULL;
    return p;
}
void insertfirst(int val)
{
    node *p = newnode(val);
    if (head == NULL)
        head = p;
    else
    {
        p->next = head;
        head = p;
    }
}
void insertlast(int val)
{
    node *p = newnode(val);
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    if (curr->next == NULL)
    {
        curr->next = p;
        p->next = NULL;
    }
}
void insertafter(int val, int ele)
{
    node *p = newnode(val);
    node *curr = head;
    while (curr->data != ele)
    {
        curr = curr->next;
    }
    if (curr->data = ele)
    {
        p->next = curr->next;
        curr->next = p;
    }
}
void insertbefore(int val, int ele)
{
    node *p = newnode(val);
    node *prev = NULL;
    node *curr = head;
    while (curr->data != ele)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == ele)
    {
        prev->next = p;
        p->next = curr;
    }
}
void deletenode(int ele)
{
    node *prev = NULL;
    node *curr = head;
    if (head == NULL)
        printf("List is empty");
    else
    {
        while (curr->data != ele && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr->data == ele)
        {
            prev->next = curr->next;
        }
    }
}
void displaylist()
{
    node *curr = head;
    for (curr = head; curr != NULL; curr = curr->next)
    {
        printf("%d\t", curr->data);
    }
}
void main()
{
    int ch, ele, val;
    do
    {
        printf("\n1.insertfirst\n2.insertlast\n3.insertafter\n4.insertbefore\n5.deletenode\n6.displaylist\n7.exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to be inserted:");
            scanf("%d", &val);
            insertfirst(val);
            break;
        case 2:
            printf("Enter element to be inserted:");
            scanf("%d", &val);
            insertlast(val);
            break;
        case 3:
            printf("Enter value to be inserted:");
            scanf("%d", &val);
            printf("Enter element after which the value is to be inserted:");
            scanf("%d", &ele);
            insertafter(val, ele);
            break;
        case 4:
            printf("Enter value to be inserted:");
            scanf("%d", &val);
            printf("Enter element before which the value is to be inserted:");
            scanf("%d", &ele);
            insertbefore(val, ele);
            break;
        case 5:
            printf("Enter element to be deleted:");
            scanf("%d", &val);
            deletenode(val);
            break;
        case 6:
            displaylist();
            break;
        case 7:
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 7);
}
