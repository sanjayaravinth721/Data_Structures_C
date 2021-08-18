#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5
int top=-1;
int stack[CAPACITY];
int isEmpty();
int isfull(){
    if(top==CAPACITY-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int ele){
    if(isfull()){
        printf("\nstack is full");
    }
    else{
        top++;
        stack[top]=ele;
    }
}
void pop(){
    int element;
    if(isEmpty()){
        printf("\ncan't be deleted");
    }
    else{
        top=top-1;
    }
}
void peek(){
    if(top==-1){
        printf("\nThere is no top");
    }
    else{
        printf("\nTop is %d ",stack[top]);
    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void display(){

    if(isEmpty()){
        printf("\nEnd of Stack");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
    }
}


int main(){
       int ch, item;
        while(1)
            {
            printf("Different choices are:\n");
            printf("1.push\n");
            printf("2.pop\n");
            printf("3.peek\n");
            printf("4.traverse\n");
            printf("5.exit\n");
            printf("enter your choice: ");
            scanf("%d",&ch);
            printf("your choice was: %d\n",ch);
                switch(ch)
                    {
                        case 1:
                                printf("enter element for push:");
                                scanf("%d",&item);
                                push(item);
                                break;
                        case 2: printf("pop command is given\n");
                                pop();
                                break;
                        case 3: peek();
                                break;
                        case 4: display();
                                break;
                        case 5: exit(0);
                        default: printf("invalid input\n");
                    }
                printf("\n");
            }
                
}