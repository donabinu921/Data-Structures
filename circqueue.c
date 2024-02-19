#include <stdio.h>
#define size 50
int front = -1, rear = -1, q[size];

void enqueue(int ele)
{
    if (front == (rear + 1) % size)
    {
        printf("Queue is full");
    }
    else
    {
        if (rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        q[rear] = ele;
    }
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        int item = q[front];
        if (front == 0 && rear == 0)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        return item;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
    }
}

void main()
{
    int ch, ele, a, b;
    do
    {
        printf("\nEnter your choice:");
        printf("1.enqueue\n2.dequeue\n3.display\n4.break\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            a = dequeue();
            printf("The popped element is %d", a);
            break;
        case 3:
            display();
        case 4:
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (ch != 4);
}