#include<stdio.h>
#include<stdlib.h>

#define N 5

int queue[N];  //The queue
int head = -1;
int tail = -1;  //The head and tail variables of the queue

typedef int data;

int isfull();         //To check is queue is full
int isempty();        //To check if queue is empty
void enqueue();       //To add data to the queue
void dequeue();       //To remove data from the queue
void display();       //To display the queue
int peek();           //To get the first vale entered into the queue
int count();          //To count the number of elements in the queue


void main(){
    int s=1;
    while(s){
        printf("\n\n\nWhat do you want to do ?");
        printf("\n0 -> Exit");
        printf("\n1 -> Insert");
        printf("\n2 -> Delete\n");\
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


//To check if full
int isfull(){
    return((head == 0 && tail == N-1) || (head==tail+1));
}

//To check if empty
int isempty(){
    return(head == -1);
}

//To add data
void enqueue(){
    data d;
    if(isfull())
        printf("\nOverflow!!");

    else{
        printf("\nEnter the data you want to push into the queue:");
        scanf("%d", &d);
        if(head == -1){
            head = 0;
            tail = 0;
        }
        else if(tail == N-1)
            tail = 0;        //Since this queue is circular, if the tail reaches the end of the queue, it reverts back to the first position.
        else
            tail++;
        queue[tail] = d;
        printf("Value %d inserted in queue", d);
        }
}

//To remove data
void dequeue(){
    if(isempty())
        printf("Underflow!!");
    else{
        printf("\nValue %d deleted from queue", queue[head]);
        if(head == tail){  //Queue has only 1 element
            head = -1;
            tail = -1;
        }
        else if(head == N-1)
            head = 0;    //Head circles back.
        else
            head++;
    }
    return;
}

//To display the queue
void display(){
    int front = head, rear = tail;
    if(isempty())
        printf("\nEmpty Queue!!");
    else{
        printf("\n---------THE QUEUE---------");
        printf("\n--------------------------------------------");
        if(head<=tail){
            while(front<=rear){
                printf("\nData in position %d is %d", front+1, queue[front]);
                front++;
            }
        }
        else{
            while(front<=N-1){
                printf("\nData in position %d is %d", front+1, queue[front]);
                front++;
            }
            front=0;
            while(front<=rear){
                printf("\nData in position %d is %d", front+1, queue[front]);
                front++;
            }
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
    int cnt = 0;
    if(tail>head)
        cnt = tail - head+1;
    else if(head>tail)
        cnt = N - (head-tail) + 1;
    return cnt;
}



