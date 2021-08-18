#include<stdio.h>
#include<stdlib.h>
struct NODE
{
   struct NODE* prev;
   int data;
   struct NODE* next;
};
void display(struct NODE* temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void create(){
    struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE* last;
    int x;
    scanf("%d",&x);
    newnode->data=x;
    newnode->prev=NULL;
    last=newnode;
    last->next=NULL;

    scanf("%d",&x);
    while(x!=-1){
        struct NODE* temp = (struct NODE*)malloc(sizeof(struct NODE));
        temp->data=x;
        temp->prev=last;
        last->next=temp;
        last=temp;
        last->next=NULL;
        scanf("%d",&x);
    }
    display(newnode);
}
int main(){
    create();
}


































/*void display(struct NODE* head){
    //struct node* current = *head;
    while(head==NULL){
        printf("List is empty");
        return;
    }
    while(head!=NULL){
      printf("%d ",head->data);
      head=head->next;
   }
    printf("\n");
}

//APPENDING
void append(struct NODE **head,int element){
  
   struct NODE* newnode=(struct NODE*)malloc(sizeof(struct NODE));
   newnode->data=element;
   newnode->next=NULL;
   newnode->prev=NULL;

     if(*head==NULL){
        *head=newnode;
         return;
     }
     else{
        struct NODE* current=*head;
        while(current->next!=NULL){
           current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
     }
}

void duplicate(struct NODE* head){
    struct NODE* current;
    struct NODE* index = current->next;
    struct NODE* temp;

    if(head == NULL){
        return;
    }
    else{
        for(current=head ; current!=NULL ; current=current->next){
            while(index!=NULL){
                if(current->data == index->data){
                    temp = index;
                    index->prev->next=index->next;
                    if(index->next!=NULL){
                        index->next->prev=index->prev;
                    }
                    temp=NULL;
                }
            }
        }
    }
}

int main(){
   struct NODE* head=NULL;
   int input;
     while(1){
         scanf("%d",&input);
         if(input==-1){
            break;
         }
        append(&head,input);
     }
    display(head);
    duplicate(&head);
    display(head);
}*/