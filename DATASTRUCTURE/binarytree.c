#include<stdio.h>
#include<stdlib.h>




struct Node{
    int a;
    struct Node *left;
    struct Node *right;
};

struct Node* create(struct Node* temp,int ele){
    
    if(temp==NULL){
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->a=ele;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else{
        if(ele<temp->a){
            temp->left=create(temp->left,ele);
        }
        if(ele>temp->a){
            temp->right=create(temp->right,ele);
        }
    }
    
    return(temp);
}
struct Node* minValue(struct Node* root){
    struct Node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    printf("minimum is : %d",temp->a);
    return temp;
}

void inorder(struct Node* temp){
    if(temp!=NULL){
    inorder(temp->left);
    printf("%d ",temp->a);
    inorder(temp->right);
    }
   
}
struct Node* delete(struct Node* temp,int data){
    if(temp==NULL){
        return temp;
    }
    else if(temp->a > data){
        temp->left=delete(temp->left,data);
    }
    else if (temp->a < data){
        temp->right=delete(temp->right,data);
    }
    else{
        if(temp->left==NULL && temp->right==NULL){
           
            free(temp);
            temp=NULL;
            return temp;
        }
        else if(temp->left!=NULL && temp->right==NULL){
            struct Node* t = temp;
            temp=temp->left;
            free(temp);
            temp=NULL;
            return t;
        }
        else if(temp->left==NULL && temp->right!=NULL){
            struct Node* t = temp;
            temp=temp->right;
            free(temp);
            temp=NULL;
            return t;
        }
        else{
            struct Node* t = minValue(temp->right);
            temp->a=t->a;
            temp->right=delete(temp->right,data);
            return temp;
        }
    }

}

int main(){
    struct Node* root = NULL;

    int x=1;
    while(x){
        printf("\n 1->insert");
        printf("\n 2->display");
        printf("\n 3->find minimum");
        printf("\n 4->delete");
        printf("\n 0->exit\n");
        int a;
        scanf("%d",&a);
        
        int data;
        switch(a){
            case 1:
                printf("Enter the number: ");
                scanf("%d",&data);
                root=create(root,data);
                printf("%d\n",root->a);
                break;
            case 2:
                 inorder(root);
                 break;
            case 3:
                minValue(root);
                break;
            case 4:
               
                printf("Enter the element to be deleted :");
                int p;
                scanf("%d",&p);
                root= delete(root,p);
                break;
            case 0:
                x=0;
                printf("Exiting..");
                break;
        }
    }
  
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
