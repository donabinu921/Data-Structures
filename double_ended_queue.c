#include <stdio.h>
#define size 50
int front = -1, rear = -1, q[size];

void enqueuerear(int ele)
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

int dequeuefront()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        int item = q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return item;
    }
}

void enqueuefront(int ele)
{
    if (front == (rear + 1) % size)
    {
        printf("Queue is full");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1) % size;
        }
        q[front] = ele;
    }
}

int dequeuerear()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        int item = q[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1) % size;
            ;
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
        for (int i = front; i <= rear; i = (i + 1) % size)
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
        printf("1.enqueuerear\n2.dequeuefront\n3.enqueuefront\n4.dequeuerear\n5.display\n6.break\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted:");
            scanf("%d", &ele);
            enqueuerear(ele);
            break;
        case 2:
            a = dequeuefront();
            printf("The deleted element is %d", a);
            break;
        case 3:
            printf("Enter the element to be inserted:");
            scanf("%d", &ele);
            enqueuefront(ele);
            break;
        case 4:
            b = dequeuerear();
            printf("The deleted element is %d", b);
            break;
        case 5:
            display();
        case 6:
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (ch != 6);
}