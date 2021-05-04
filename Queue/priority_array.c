#include<stdio.h>
#include<stdlib.h>

#define N 100
struct item{
    int value;
    int priority;
};
typedef struct item Item;

Item q[N];
int tail = -1;

//Function prototypes
int isfull();         //To check if queue is full
int isempty();        //To check if queue is empty
void enqueue();       //To add data to the queue
int peek();           //To get the first vale entered into the queue
void dequeue();       //To remove data from the queue
void display();       //To display the queue


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
    printf("\n\n\n\nThe Data at the top of the queue according to priority: %d", q[peek()]);
    printf("\nThe number of elements in the queue : %d", tail+1);
}


//To check if full
int isfull(){
    return(tail == N-1);
}

//To check if empty
int isempty(){
    return(tail == -1);
}

//To add data
void enqueue(){
    int d;
    int p;
    if(isfull())
    printf("\nOverflow!! Cannot input.");
    else{
        printf("\nEnter the data you want to push into the queue:");
        scanf("%d", &d);
        printf("Enter the priority:");
        scanf("%d", &p);
        tail++;
        q[tail].value = d;
        q[tail].priority = p;
        printf("Value %d inserted in queue", d);
    }
}

//to get the element with lowest priority
int peek(){

    int lowest = N;
    int h = N,i;
    for(i=0;i<=tail;i++){

        if (lowest > q[i].priority){
            lowest = q[i].priority;
            h = i;
        }
        //If priority is same then we chose the item with highest value
        else if(lowest == q[i].priority){
            if(q[i].value > q[h].value){
                lowest = q[i].priority;
                h = i;
            }
        }
    }
    return h;
}


//To remove data
void dequeue(){
    if(isempty())
        printf("Underflow!! Cannot delete from empty queue");
    else{
        int h = peek();
        printf("\nValue %d deleted from queue", q[h]);
        for(int i = h; i<tail; i++){
            q[i] = q[i+1];
        }
        tail--;
    }
}

//To display the queue
void display(){
    int i;
    if(isempty())
        printf("\nEmpty Queue!!");
    else{
        printf("\n\n\n---------THE QUEUE---------");
        printf("\n--------------------------------------------");
        for(i = 0; i<=tail; i++){
            printf("\nData in position %d is %d. Priority --> %d", i+1, q[i].value, q[i].priority);
        }
        printf("\n--------------------------------------------");
    }
}


