#include<stdio.h>   
#include<stdlib.h>  

struct Node
{
    int info;
    struct Node* next;
};
typedef struct Node node;

node* front=NULL;  
node* rear=NULL;  

node *newnode(int val)
{
    node* p;
    p=(node*)malloc(sizeof(node));
    p->info=val;
    p->next=NULL;
    return(p);
}

void insert()  
{  
        int ele;
        printf("\nEnter value to be inserted:\n");  
        scanf("%d",&ele);  
        node* p=newnode(ele); 
        if(front == NULL)  
        {  
            front = p;  
            rear = p;   
            front->next = NULL;  
            rear->next = NULL;  
        }  
        else   
        {  
            rear -> next = p;  
            rear = p;  
            rear->next = NULL;  
        }   
}     

void delete()  
{  
    node *ptr;  
    if(front == NULL)  
    {  
        printf("\nQueue is empty\n");  
        return;  
    }  
    else   
    {  
        ptr=front;  
        front = front->next;  
        free(ptr);  
    }  
}  

void display()  
{  
    node*ptr=front;        
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {     
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr->info);  
            ptr = ptr->next;  
        }  
    }  
}  
 
void main ()  
{  
    int ch;   
    do   
    {     
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice:");  
        scanf("%d",& ch);  
        switch(ch)  
        {  
            case 1:insert();  
                   break;  
            case 2:delete();  
                   break;  
            case 3:display();  
                   break;  
            case 4:break;  
            default:printf("\nInvalid choice\n");  
        }  
    }while(ch!=4);
}  
