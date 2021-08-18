#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE* next;
};

void display(struct NODE* temp){
    struct NODE *new = temp;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=new);
}

struct NODE* create(){
    struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE)); //100
    struct NODE* last = newnode;
    int x;
    scanf("%d",&x);
    newnode->data=x;
    last=newnode;
    last->next=NULL;
  
    scanf("%d",&x);
    while(x!=-1){
        struct NODE* temp = (struct NODE*)malloc(sizeof(struct NODE));  //200
        temp->data=x;
        last->next=temp; //200
        last=temp;
        last->next=NULL;
        scanf("%d",&x);
    }
    last->next=newnode;
    return newnode;
}

//insertion
struct NODE* inserion(struct NODE* temp,int pos){
    struct NODE* first=temp;
    struct NODE* p,*s;
    s=temp;
    printf("\nEnter the number to be insert: ");
    int x;
    scanf("%d",&x);
    for(int i=0;i<pos-1;i++){
        p=temp;
        temp=temp->next;
    }
    if(pos==0){
        struct NODE* new= (struct NODE*)malloc(sizeof(struct NODE));
        
        new->data=x;
        temp=new;
        temp->next=first;
        
        
    }
    else{
        struct NODE* newnode=(struct NODE*)malloc(sizeof(struct NODE));
        newnode->data=x;
        newnode->next=temp;
        p->next=newnode;
        return first;
    }
    
}

void delete(struct NODE* temp){
    struct NODE* first =temp;
    printf("Enter the element to be deleted: ");
    int x;
    scanf("%d",&x);
    struct NODE*last=temp;
    struct NODE*p=temp;

    
    if(temp->data==x){

        while(last->next!=temp){
        last=last->next; //400
        }
        last->next=temp->next; 
        free(temp); 
        temp=last->next;
        return;
    }
    else{
        while(temp->next!=first && temp->data!=x){
            p=temp;
            temp=temp->next;
        }
        if(temp->data==x){
            p->next=temp->next;
            free(temp);
        }
    }
    
}
int count(struct NODE* temp){
    struct NODE* last=temp;
    int count=1;
    while(temp->next!=last){
        count++;
        temp=temp->next;
    }
    return count;
}

struct NODE* rotate(struct NODE* temp){
    struct NODE* first=temp;
    int c=count(temp);
    int a[c];
    int k;
    struct NODE* last=temp;
    scanf("%d",&k);
    for(int i=0;i<k-1;i++){
        last=last->next;
    }
    temp=last;
    int i=0;
    while(temp->next!=last){
        a[i]=temp->data;
        i++;
        temp=temp->next;
    }
    if(temp->next==last){
        a[i]=temp->data;
    }
    for(int i=0;i<c;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    temp=first;
    for(int i=0;i<c;i++){
        first->data=a[i];
        first=first->next;
    }
    return temp;

}

int main(){
    struct NODE* first = create();
    display(first);
    //printf("\nEnter the pos to be inserted: ");
    //int x;
    //scanf("%d",&x);
    //struct NODE* second = inserion(first,x);
    //delete(first);
    int a=count(first);
    printf("\ncount= %d ",a);
    struct NODE* rot=rotate(first);
    display(first);
}