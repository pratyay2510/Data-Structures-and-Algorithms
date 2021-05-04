#include<stdio.h>
#include<stdlib.h>

typedef int data;

//Defining a node
struct Node{
	data d;
    int p;                  //The priority of the node
	struct Node *next;
};
typedef struct Node node;
node *newnode, *n, *temp;   //Global variables

//Defining the queue
struct Queue{
	int cnt;
	node *head;
	node *tail;
};
typedef struct Queue queue;

//Function prototypes
void initialise(queue *q);        //To initialise the queue
node* getnode(data d, int p);     //To create a node
int isempty(queue *q);            //To check for underflow
void enqueue(queue *q);           //To add data to the queue
node *peek(queue *q);             //To get the node with the minimum priority
void extract_min(queue *q);           //To remove data from the queue
void display(queue *q);           //To display the queue


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
         case 2: extract_min(&q); break;
         default: printf("\nChoice Invalid!!"); break;
        }
        display(&q);
    }
    printf("\n\n\n\nThe Data with the lowest priority : %d", peek(&q)->d);
    printf("\nThe number of elements in the queue : %d", q.cnt);
}


//Initialise the queue
void initialise(queue *q){
	q->cnt = 0;
	q->head = NULL;
	q->tail = NULL;
}

//Create a node
node* getnode(data d, int p){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->d = d;
    newnode->p = p;
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
    int p;
    printf("\nEnter the data you want to push into the queue:\t");
    scanf("%d", &d);
    printf("Enter the priority of the node:\t");
    scanf("%d", &p);
    n = getnode(d,p);
    temp = q->head;
    if(isempty(q))
        q->head = n;
    else{
        q->tail->next = n;
    }
    q->tail = n;
    q->tail->next = NULL;
    q->cnt++;
    printf("Value %d of priority %d inserted in queue", d, p);
}

//The value with least priority
node* peek(queue *q){
   int lowest = 10;                     //To keep track of the minimum priority
   node *small = q->tail;               //To keep track of the node with the lowest priority
   temp = q->head;
   while(temp!=NULL){                   //To search through the queue to find node with least priority
        if(temp->p < lowest){
            lowest = temp->p;
            small = temp;
        }
        else if(temp->p == lowest){
            if(temp->d > small->d){     //If priority same, the one with higher value given upper priority.
                lowest = temp->p;
                small = temp;
            }
        }
        temp = temp->next;
   }
   return small;                        //Returns node with lowest priority
}

//To remove data
void extract_min(queue *q){
    node *temp1;
    if(isempty(q)){
        printf("Underflow!!  Cannot delete from an empty queue!!");
        q->tail = NULL;
    }
    else{
        node* small = peek(q);                  //Gets the node with the lowest priority
        temp1 = q->head;
        if(small==q->head){                     //If the head is the one with the minimum priority
            q->head = q->head->next;
        }
        else if(small == q->tail){              //If tail is the one with minimum priority, it gets assigned to the node before the last node
            node* temp2 = q->head;
            while(temp2->next != q->tail){
                temp2 = temp2->next;
            }
            q->tail = temp2;
            q->tail->next = NULL;
        }
        else{
            while(temp1->next != small){
                temp1 = temp1->next;
            }
            temp1->next = temp1->next->next;    //Queue traversal till it reaches the node previous to the one with lowest priority
        }
        q->cnt--;                               //Decrease the count of the queue
        printf("\nValue %d removed from the queue", small->d);
        free(small);
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
            printf("\n%d. Data-->%d\tPriority-->%d ", i, n->d, n->p);
            n = n->next;
            i++;
        }
        printf("\n--------------------------------------------");
    }
}

