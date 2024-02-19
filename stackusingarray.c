#include <stdio.h>
#define size 50
int top = -1, stack[size];

void push(int ele)
{
    if (top == size - 1)
    {
        printf("Stack is full");
    }
    else
    {
        top = top + 1;
        stack[top] = ele;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        int item = stack[top];
        top = top - 1;
        return item;
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        return stack[top];
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}

void main()
{
    int ch, ele, a, b;
    do
    {
        printf("Enter your choice:");
        printf("1.push\n2.pop\n3.peek\n4.display\n5.break\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be pushed:");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            a = pop();
            printf("The popped element is %d", a);
            break;
        case 3:
            b = peek();
            printf("Element at the top is %d", b);
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (ch != 5);
}