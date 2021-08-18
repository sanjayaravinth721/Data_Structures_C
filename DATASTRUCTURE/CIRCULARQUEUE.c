#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
int Cqueue[CAPACITY];
int front=-1;
int rear = -1;


void CEnque(int ele){
    if(rear==CAPACITY-1){
        printf("\nCQueue is full");
    }
    else if(front==-1 && rear==-1){
        front=0;
        Cqueue[rear]=ele;
    }
    else if(rear==CAPACITY-1){
        rear=0;
        Cqueue[rear]=ele;
    }
    else{
        rear++;
        Cqueue[rear]=ele;
    }
}

void CDeque(){
    int ele;
    if(front==-1 && rear==-1){
        printf("\nCQueue is empty");
    }
    else if(front==rear){
        ele=Cqueue[front];
        front = rear-1;
        printf("\n%d is deleted",ele);
    }
    else if(front==CAPACITY-1){
        ele=Cqueue[front];
        front=0;
        printf("\n%d is deleted",ele);
    }
    else{
        ele=Cqueue[front];
        front++;
        printf("\n%d is deleted",ele);
    }
}
void display(){
    if(front==0 && CAPACITY==rear+1){
        for(int i=0;i<=rear;i++){
            printf("%d ",Cqueue[i]);
        }

    }
    else if(front == rear+1){
        for(int i=0;i<=rear;i++){
            printf("%d ",Cqueue[i]);
        }
        for(int i=0;i<CAPACITY;i++){
            printf("%d ",Cqueue[i]);
        }
    }
}

int main(){
    int a;
    int element;
    while(1){
        printf("\n1: circular enque");
        printf("\n2: circular deque");
        printf("\n3: circular enque display");
        printf("\n4: Enter your choice");
        scanf("%d",&a);

        switch(a){
            case 1:
              printf("\nEnter the element to be inserted");
              scanf("%d",&element);
              CEnque(element);
              break;

            case 2:
               CDeque();
               break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
               printf("\nenter a valid number");
               break;
        }

    }
}