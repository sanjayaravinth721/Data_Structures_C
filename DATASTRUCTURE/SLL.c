#include<stdio.h>
#include<stdlib.h>

//BOX
struct NODE
{
   int data;
   struct NODE* next;
};

//displaying

void display(struct NODE* temp){
   while(temp!=NULL){

      printf("%d ",temp->data);
      temp=temp->next;
   }

}

void max(struct NODE* temp);
void sum(struct NODE* temp);

struct NODE* insert(struct NODE* temp,int pos);
void search(struct NODE* temp);

struct NODE* delete(struct NODE* temp);
void chechsortedornot(struct NODE* temp);
void Sduplicate(struct NODE* temp);
int count(struct NODE* temp);
void reverseElements(struct NODE* temp);
struct NODE* reverseLinkedList(struct NODE* temp);
void Unsorteddup(struct NODE* temp);


//createnode
void create(){
   struct NODE *newnode,*last;
   newnode=(struct NODE*)malloc(sizeof(struct NODE)); //100

   int x;
   scanf("%d",&x); //2

   newnode->data=x; //2
   last=newnode; //100
   last->next=NULL;

   scanf("%d",&x); //3 //4 //-1
   while(x!=-1){  //(3!=-1) //(4!=-1) //(-1==-1)
      struct NODE* temp=(struct NODE*)malloc(sizeof(struct NODE)); //200 //300
      temp->data=x; //3 //4
      last->next=temp; //200 //300
      last=temp; //200 //300
      last->next=NULL; //null //null
      scanf("%d",&x); //4 //-1
   }
   //return newnode;
   display(newnode);
   printf("\n");
   sum(newnode);

   printf("\n");
   max(newnode);

   printf("\n");
   display(newnode);

   printf("\nEnter the position to be inserted:");
   int n;
   scanf("%d",&n);
   newnode=insert(newnode,n);
   display(newnode);

   search(newnode);

   printf("\n");
   newnode=delete(newnode);

   display(newnode);
   chechsortedornot(newnode);

   Sduplicate(newnode);
   display(newnode);
    
   int c=count(newnode);
   printf("\ncount is = %d",c);

   printf("\n");
   printf("Reversing elements: ");
   reverseElements(newnode);
   display(newnode);

   printf("\nReversing using linked list: ");
   newnode=reverseLinkedList(newnode);
   display(newnode);

   Unsorteddup(newnode);
   display(newnode);


}
//max
void max(struct NODE* temp){

   int max = temp->data;
   while(temp->next!=NULL){

      if(max < temp->next->data){
         max = temp->next->data;
      }
      temp = temp->next;

   }
   printf("maximum is = %d ",max);
}

//sum
void sum(struct NODE* temp){
   int sum=0;
   while (temp!=NULL)
   {
      sum=sum+(temp->data);
      temp=temp->next;
   }
   printf("sum = %d",sum);
}
//insert
struct NODE* insert(struct NODE* temp ,int pos){
   struct NODE* t=temp;   //100
   for(int i=0;i<pos-1;i++){
      t=t->next;
   }

   struct NODE* i;
   i=(struct NODE*)malloc(sizeof(struct NODE)); //600
   printf("Enter the number to be inserted :");
   int n;
   scanf("%d",&n);
   if(pos==0){          //for first node
      i->data=n;
      i->next = temp;
      temp=i;
   }
   else{                //for inbetween node
        i->data=n;
        i->next = t->next;
        t->next=i;
   }
   return temp;
}

//searching
void search(struct NODE* temp){
   printf("\nenter the element to searched :");
   int n;
   scanf("%d",&n);
   while(temp!=NULL){
      if(temp->data!=n){
         temp=temp->next;
      }
      else if(temp->data==n){
         printf("element %d is found :)",n);
         break;
      }
      if(temp==NULL){
         printf("element %d is not found :)",n);
         break;
      }
   }

}



//duplicate for sorted linked list
void Sduplicate(struct NODE* temp){
   printf("\nWithout dup..");
   struct NODE* p,*q;
   p=temp;
   q=temp->next;
   while(q!=NULL){
      if(p->data==q->data){
         p->next=q->next;
         free(q);
         q=p->next;
      }
      else{
         p=p->next;
         q=q->next;
      }
   }
}

void Unsorteddup(struct NODE* temp){
   printf("\nUnsorted duplicates...");
   struct NODE *ptr1, *ptr2, *duplicate;
ptr1 = temp;

while (ptr1 != NULL && ptr1->next != NULL)
{
ptr2 = ptr1;


while (ptr2->next != NULL)
{
if (ptr1->data == ptr2->next->data)
{
duplicate = ptr2->next;
ptr2->next = ptr2->next->next;
free(duplicate);
}
else
ptr2 = ptr2->next;
}
ptr1 = ptr1->next;
}
   
}


//checking
void chechsortedornot(struct NODE* temp){
   printf("checking...");
   struct NODE* p = temp;
   int min=0;
   int f=0;
   while(temp->next!=NULL){

      if(temp->data>min){
         min=temp->data;
         f=0;
         temp=temp->next;
      }
      else{
          f=1;
          break;
      }

   }
   if(f==1){
      printf("Not sorted");
      return;
   }
   else{
    printf("All sorted");
    return;
   }

}




//deletion
struct NODE* delete(struct NODE* temp){
   struct NODE* last=temp;
   struct NODE* p= temp;
   //struct NODE* current=temp;
   printf("Enter the element to deleted:");
   int n;
   scanf("%d",&n);


   if(temp->data==n){
      p=p->next;
      free(temp);
      temp=p;
      return temp;
   }
   else{
      while(temp->data!=n && temp!=NULL){
         p=temp;
         temp=temp->next;
      }
       if(temp->data==n){
         p->next=temp->next;
         free(temp);
      }
   }
   return last;

   }
   int count(struct NODE* temp){
      int count=0;
      while(temp!=NULL){
         count=count+1;
         temp=temp->next;
      }
      return count;
   }

   //reversing with elements
   void reverseElements(struct NODE* temp){
      int n = count(temp);
      struct NODE* first=temp;
      int a[n];
     
      for(int i=0;i<n;i++){
         a[i]=temp->data; //12 24 13 45 32
         temp=temp->next; //200 //300 //400 //500
      }
      
      
         temp=first;
         for(int i=n-1;i>=0;i--){
            temp->data=a[i]; //32 //45 //13 //24 //12
            temp=temp->next;
         }
   }
      
   //reversing using address
      struct NODE* reverseLinkedList(struct NODE* temp){
         struct NODE* p,*q,*r;
         p=temp;
         q=r=NULL;
         while(p!=NULL){
         r=q;
         q=p;
         p=p->next;
         q->next=r;
         }
         temp=q;
         return temp;
   }
     
   //concatinate two linked list
   void concatenation(struct NODE* first,struct NODE* second){
      printf("\nconcatinating...");
      struct NODE* temp=first;
      while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next=second;
      display(first);
   }


   //merging two sorted linked list
   struct NODE* merging(struct NODE* first,struct NODE* second){
      printf("\nMerging 2 sorted linked list.... ");
      struct NODE* third,*last;
      if(first->data<second->data){
         third=last=first;
         first=first->next;
         last->next=NULL;
      }
      else{
         third=last=second;
         second=second->next;
         last->next=NULL;
      }

      while(first!=NULL && second!=NULL){
         if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
         }
      else{
         last->next=second;
         last=second;
         second=second->next;
         last->next=NULL;
      }
   }
      if(first!=NULL){
         last->next=first;
      }
      else{
         last->next=second;
      }
      return third;
      
   }

   struct NODE* rotation(struct NODE* temp){ //2 4 7 8 9
      int n=count(temp);
      printf("Count is =%d",n);
      struct NODE* last= temp;
      struct NODE* first=temp;
      struct NODE* p;
      printf("\nEnter the number of rotation to be rotated: ");
      int k;  //k=3
      scanf("%d",&k);
      int a[n];
      for(int i=0;i<k-1;i++){
         p=last;
         last=last->next;
      }
      temp=last;
      int i=0;
      while(temp->next!=last){
         if(temp->next==NULL ){
            temp->next=first;
            a[i]=temp->data;    //2 
         }
         else{
            a[i]=temp->data; //8 //9 //4
         }
         i=i+1;
         temp=temp->next;
      
      }
      if(temp->next==last){
         a[i]=temp->data;
      }
      //a[++i]=p->data;
      //last->next=NULL;
     
      for(int i=0;i<n;i++){
         printf("%d ",a[i]);
      }
      printf("\n");
      temp=first;
      for(int i=0;i<n;i++){
         first->data=a[i];
         first=first->next;
      }
         
     
      return temp;

   }




int main(){
   //struct NODE* first=create();
   create();
   //struct NODE* second=create();
   //concatenation(first,second);
  // struct NODE* third = merging(first,second);
  //display(third);
  //struct NODE* rot=rotation(first);
  //display(first);
   

   printf("\n");
}







/* 2  200  3  300  4  null
    100     200     300     */

/*//APPENDING
void append(struct NODE *head,int element){

   struct NODE* newnode=(struct NODE*)malloc(sizeof(struct NODE)); //1000
   newnode->data=element;
   newnode->next=NULL;

     if(head==NULL){
        head=newnode;
         return;
     }
     else{
        struct NODE* current=head;
        while(current->next!=NULL){
           current=current->next;
        }
        current->next=newnode;
     }
}


//reverse
void reverse(struct NODE** head)
{
   struct NODE* current = *head; //1000......//5000
   struct NODE* first= *head; //1000
   struct NODE* slow;
   struct NODE* prev;
   while(current->next!=NULL){
      prev=current; //1000 //2000 //3000 //4000
      slow=current->next;  //2000 //3000 //4000 //5000
      current=current->next;  //1000 //2000 //3000 //4000 //5000
      slow->next=prev; //1000 //2000 //3000 //4000
   }
   *head=slow;

   // while(slow!=NULL){
   //    slow=slow->next;
   // }

}







//DELETION
void delete(struct NODE** head ,int input){
   struct NODE* current=*head,*prev;
   //for deleting first element
   if(current->data==input){
      *head=current->next;
      free(current);
      return;
   }
   while(current->data!=input && current!=NULL) {
      prev=current;
      current=current->next;
   }
   prev->next=current->next;
   free(current);

}


//COUNTING
int getcount(struct NODE* head){
   int count=0;
   struct NODE* current=head;
   while(current!=NULL){
      current=current->next;
      count++;
   }
   return count;
}


//DISPLAYING
void display(struct NODE* head){
   while(head!=NULL){
      printf("%d ",head->data);
      head=head->next;
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
        append(head,input);
     }

     display(head);
     printf("\n");

      printf("%d ",getcount(head));
      printf("\n");

     delete(&head,1);
     //printf("\n");
     display(head);
     printf("\n");

   //   reverse(&head);
   //   display(head);
     return 0;

}
*/
