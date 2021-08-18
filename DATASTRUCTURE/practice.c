#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE* next;
};

void display(struct NODE* temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

}


struct NODE* Insert(struct NODE* head,int data){
    struct NODE* newnode=(struct NODE*)malloc(sizeof(struct NODE));
    struct NODE* temp;
    if(head==NULL){
        newnode->data=data;
        newnode->next=NULL;
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;
        temp->data=data;
        temp->next=NULL;
    }
    return head;

}


int main(){
    int a;
    scanf("%d",&a);
    struct NODE* head=NULL;

    struct NODE* k;
    while(a!=-1){
        k= Insert(head,a);
        head=k;
        scanf("%d",&a);
    }
    display(k);
}
