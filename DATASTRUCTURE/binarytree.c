#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE* left;
    struct NODE* right;
};

struct NODE* create(int element){
    struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE)); //200 //300 //400 //500
    newnode->data=element;                                            //15  //10  //20  //8
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct NODE* insert(struct NODE* temp){
    struct NODE* root = temp;
    printf("Enter the elements to be inserted\n..");
    int element;
    scanf("%d",element);
    
   
    if(temp==NULL){                             
        temp=create(element);
    }
    do{
        int new;
        scanf("%d",new);
    if(new<=temp->data){                                                 
        temp->left=create(new);  
         temp=temp->left;                                          
    }
   
    else{                                       
        temp->right=create(new);
        temp=temp->right;
    }
   
    
    }while(temp->left!=NULL && temp->right!=NULL);
    
    return root;
    
}

void display(struct NODE* temp){
    printf("Printing...");
     printf("%d ",temp->data);
    do{
        temp=temp->left;
        printf("%d ",temp->data);
        temp=temp->right;
        
    }while(temp->left!=NULL && temp->right!=NULL);
}


    
   

    


int main(){
    struct NODE* head=NULL;
    struct NODE* root=insert(head);
    display(root);
}





/*struct NODE* root = NULL;  //root=200
    struct NODE* n1=create(15);
    struct NODE* n2=create(10);
    struct NODE* n3=create(12);
    struct NODE* n4=create(8);
    struct NODE* n5=create(20);

    n1->left=n2;
    n1->right=n5;

    n2->left=n4;
    n2->right=n3;

    void print(struct NODE* temp){
    if(temp==NULL){
        printf("-----");
        return;
    }
     printf("%d ",temp->data);
    printf("\nleft...\n");
    printf("%d",temp->left->data);
    printf("\nRight...\n");
    printf("%d",temp->right->data);
    
    print(n1);*/