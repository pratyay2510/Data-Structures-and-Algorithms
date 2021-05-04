#include<stdio.h>
#include<stdlib.h>

typedef int data;

//Defining a node
struct Node{
	data d;
	struct Node *next;
};
typedef struct Node node;
node *newnode, *n;          //Global variables

//Defining the queue
struct Queue{
	int cnt;
	node *head;
	node *tail;
};
typedef struct Queue queue;

//Function prototypes
void initialise(queue *q); //To initialise the queue
node *getnode(data d);     //To create a node
int isempty(queue *q);     //To check for underflow
void enqueue(queue *q);    //To add data to the queue
void dequeue(queue *q);    //To remove data from the queue
void display(queue *q);    //To display the queue
int peek(queue *q);        //To get the first vale entered into the queue


void main(){
    queue q;
    initialise(&q);
    int s=1;
    while(s){
        printf("\n\nWhat do you want to do ?");
        printf("\n0 -> Exit");
        printf("\n1 -> Insert");
        printf("\n2 -> Delete\n");
        scanf("%d", &s);
        switch(s){
         case 0: break;
         case 1: enqueue(&q); break;
         case 2: dequeue(&q); break;
         default: printf("\nChoice Invalid!!"); break;
        }
        display(&q);
    }
    printf("\n\n\n\nThe Data at the top of the queue : %d", peek(&q));
    printf("\nThe number of elements in the queue : %d", q.cnt);
}


//Initialise the queue
void initialise(queue *q){
	q->cnt = 0;
	q->head = NULL;
	q->tail = NULL;
}

//Create a node
node* getnode(data d){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}

//Check for underflow
int isempty(queue *q){
    return (q->head == NULL);
}

//To add data
void enqueue(queue *q){
    data d;
    printf("\nEnter the data you want to push into the queue:");
    scanf("%d", &d);
    n = getnode(d);
    if(isempty(q))
        q->tail = q->head = n;
    else{
        q->tail->next = n;
        q->tail = n;
    }
    q->cnt++;
    printf("Value %d inserted in queue", d);
}

//To remove data
void dequeue(queue *q){
    n = q->head;
    if(q->head == NULL){
        printf("Underflow!!");
        q->head = NULL;
        q->tail = NULL;
    }
    else{
        printf("\nValue %d deleted from queue", n->d);
        q->head = q->head->next;
        free(n);
        q->cnt--;
    }
    return;
}

//To display the queue
void display(queue *q){
    int i=1;
    n = q->head;
    if(isempty(q))
        printf("\nEmpty Queue!!");
    else{
        printf("\n\n\n---------THE QUEUE---------");
        printf("\n--------------------------------------------");
        while(n != NULL){
            printf("\nData in position %d is %d", i, n->d);
            n = n->next;
            i++;
        }
        printf("\n--------------------------------------------");
    }
}

//The first value entered into the queue
int peek(queue *q){
    if(isempty(q))
        return NULL;
    else
        return (q->head->d);
}








