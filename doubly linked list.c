#include<stdio.h>
#include<stdlib.h>
                struct Node
                {
                  int info;
                  struct Node*prev;
                  struct Node*next;
                };
                typedef struct Node node;

                node *head=NULL;
                node *tail=NULL;
                node *curr=NULL;

                node *newnode(int val)
                {
                 node*p;
                 p=(node*)malloc(sizeof(node));
                 p->info=val;
                 p->prev=NULL;
                 p->next=NULL;
                 return(p);
                }

                void insertfirst(int val)
                {
                  node*p=newnode(val);
                  
                  if(head==NULL)
                  {
                   head=p;
                   tail=p;
                  }
                  else
                  {
                    head->prev=p;
                    p->next=head;
                    p->prev=NULL;
                    head=p;
                  }
                }

                void insertlast(int val)
                {
                  node*p=newnode(val);
                  if(head==NULL)
                  {
                    head=p;
                    tail=p;
                  }
                  else
                  {
                    tail->next=p;
                    p->prev=tail;
                    tail=p;
                  }
                }

                void insertafter(int val,int ele)
                {
                  curr=head;
                  while(curr!=NULL&&curr->info!=ele) 
                   {
                     curr=curr->next;
                   }
                  if(curr==NULL)
                   {
                     printf("Element is not found");
                     return;
                   }
                  node*p=newnode(val);
                  p->prev=curr;
                  p->next=curr->next;
                  if(curr->next==NULL)
                  {
                    tail=p;
                    curr->next=p;}
                  else
                   {
                    curr->next->prev=p;
                    curr->next=p;
                   }
                }
                
                void insertbefore(int val,int ele)
                {
                  curr=head;
                  while(curr!=NULL&&curr->info!=ele)
                  {
                    curr=curr->next;
                  }
                  if(curr==NULL)
                   {
                     printf("Element is not found");
                     return;}
                  node*p=newnode(val);
                  p->prev=curr->prev;
                  p->next=curr;
                  if(curr->prev==NULL)
                   {
                      head=p;
                      curr->prev=p;}
                  else{
                   curr->prev->next=p;
                   curr->prev=p;}
                }

                void deletenode(int ele)
                {
                  curr=head;
                  while(curr!=NULL&&curr->info!=ele)
                  {
                    curr=curr->next;
                  }
                  if(curr==NULL)
                   {
                     printf("Element is not present");
                     return;}
                  else
                  {
                    if(curr->prev==NULL)
                       head=curr->next;
                    else
                       curr->prev->next=curr->next;
                    if(curr->next==NULL)     
                      tail=curr->prev;
                    else
                      curr->next->prev=curr->prev;
                   }
                   free(curr);
                }

                void display()
                {
                printf("The linked list is:\n");
                for(curr=head;curr!=NULL;curr=curr->next)
                printf("%d\t",curr->info);
                }

                void main()
                {
                int ch,ele,val;
                do
                {
                printf("1.Insert first\n2.Insert last\n3.Insert after\n4.Insert before\n5.Delete a particularnode\n6.Display\n7.Exit\n");
                printf("\nEnter your choice");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("\nEnter the value to be inserted");
                        scanf("%d",&val);
                        insertfirst(val);
                        break;
                        case 2: printf("\nEnter the value to be inserted ");
                        scanf("%d",&val);
                        insertlast(val);
                        break;
                        case 3: printf("\nEnter the value to be inserted");
                        scanf("%d",&val);
                        printf("\nEnter the element after which value is inserted");
                        scanf("%d",&ele);
                        insertafter(val,ele);
                        break;
                        case 4: 
                          printf("\nEnter the element before which value is inserted");
                        scanf("%d",&ele);
                        printf("\nEnter the value to be inserted");
                        scanf("%d",&val);
                     
                        insertbefore(val,ele);
                        break;
                        case 5: printf("\nEnter the element to be deleted");
                        scanf("%d",&ele);
                        deletenode(ele);
                        break;
                        case 6: display();
                        break;
                        case 7:printf("\nProgram terminated");
                        break;
                        default: printf("\n Invalid choice!!!");
                }
                } while (ch!=7);
                }
                    
                      







