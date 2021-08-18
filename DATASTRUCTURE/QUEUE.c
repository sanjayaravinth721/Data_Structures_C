#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int queue[CAPACITY];
int front=0;
int rear=0;

void enque(int element){
    if(rear==CAPACITY){
        printf("\nqueue is full");
    }
    else{
        queue[rear++]=element;
    }
}

void deque(){
    if(rear==front){
        printf("\nqueue is empty");
    }
    else{
        int a = queue[front];
        for(int i=0;i<rear-1;i++){
            queue[i]=queue[i+1];
        }
        rear--;
        printf("\n%d is deleted",a);
    }
}

void display(){
    if(front==rear){
        printf("\nqueue is empty");
    }
    else{
        for(int i=0;i<CAPACITY;i++){
            printf("%d ",queue[i]);
        }
    }
}

int main(){
    int a;
    int ele;
    while(1){
        printf("\n1: Insert");
        printf("\n2: delete");
        printf("\n3: display");
        printf("\nEnter u r choice:");
        scanf("%d",&a);

        switch(a){
            case 1:
               printf("\nEnter the element to be inserted");
               scanf("%d",&ele);
               enque(ele);
               break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter the valid number");
                break;
        }
    }
}