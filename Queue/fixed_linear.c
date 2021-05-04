#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];   //The queue
int head = -1;  //The head variable
int tail = -1;  //The tail variable
typedef int data;

//Function prototypes
int isfull();        //To check if queue is full
int isempty();        //To check if queue is empty
void enqueue();       //To add data to the queue
void dequeue();       //To remove data from the queue
void display();       //To display the queue
int peek();           //To get the first vale entered into the queue
int count();          //To count the number of elements in the queue


void main(){
    int s=1;
    while(s){
        printf("\n\nWhat do you want to do ?");
        printf("\n0 -> Exit");
        printf("\n1 -> Insert");
        printf("\n2 -> Delete\n");
        scanf("%d", &s);
        switch(s){
         case 0: break;
         case 1: enqueue(); break;
         case 2: dequeue(); break;
         default: printf("\nChoice Invalid!!"); break;
        }
        display();
    }
    printf("\n\n\n\nThe Data at the top of the queue : %d", peek());
    printf("\nThe number of elements in the queue : %d", count());
}

//To check if queue is full
int isfull(){
    return(tail == N-1);
}

//To check if queue is empty
int isempty(){
    return ((head>tail) || (tail==-1));
}

//To add data
void enqueue(){
    data d;
    if(isfull())
        printf("\nOverflow!!");
    else{
            printf("\nEnter the data you want to push into the queue:");
            scanf("%d", &d);
            if(head == -1)
                head = 0;
            tail++;
            queue[tail] = d;
            printf("Value %d inserted in queue", d);
        }
}


//To remove data
void dequeue(){
    if(isempty()){
        printf("Underflow!!");
        head = -1;
        tail = -1;
    }

    else{
        printf("\nValue %d deleted from queue", queue[head]);
        queue[head] = NULL;
        head++;
    }
    return;
}


//To display the queue
void display(){
    int i;
    if(isempty())
        printf("\nEmpty Queue!!");
    else{
        printf("\n\n\n---------THE QUEUE---------");
        printf("\n--------------------------------------------");
        for(i = head; i<=tail; i++){
            printf("\nData in position %d is %d", i+1, queue[i]);
        }
        printf("\n--------------------------------------------");
    }
}


//The first value entered into the queue
int peek(){
    return (queue[head]);
}


//To count the number of elements present in the queue
int count(){
    if(isempty())
        return 0;
    else
        return (tail-head+1);
}




