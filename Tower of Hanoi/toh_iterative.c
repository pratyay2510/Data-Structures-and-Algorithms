#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int data;


//Defining a node
typedef struct Node{
	data d;
	struct Node *next;
}node;

node *p, *newnode;

//Defining a stack
 typedef struct Stack{
    int cnt;
    node *top;
 }stack;


 //Function prototypes
 stack* create();
 node* getnode(data d);
 int isempty(stack* stk);
 int push(stack* stk, data d);
 int pop(stack* stk);
 void movement(char from, char to, int disk);
 int move_between_two(stack *src, stack *dest, char s, char d);
 void iterative_toh(stack *src, stack *aux, stack *dest, int no );


 int main(){
    int no;
    stack *src, *aux, *dest;

    printf("Enter the number of disks : \t");
    scanf("%d", &no);

    //creating the stacks
    src = create();
    aux = create();
    dest = create();

    iterative_toh(src,aux,dest,no);
    return 0;
}


//Creating a stack
stack* create(){
    stack* stk;
    stk = (stack*)malloc(sizeof(stack));
    stk->cnt = 0;
    stk->top = NULL;
    return stk;
}

//Creating a node
node* getnode(data d){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}

//To check for underflow
int isempty(stack* stk){
	return (stk->cnt==0);
}

//Push data into the top of the stack
int push(stack* stk, data d){
    if(isempty(stk)){
        p = getnode(d);
        stk->top = p;
        p->next = NULL;
        stk->cnt = 1;
    }
    else{
        p = getnode(d);
        p->next = stk->top;
        stk->top = p;
        stk->cnt++;
    }
	return 0;
}

//Pop data out of the stack
int pop(stack* stk){
    data d;
    if(isempty(stk)){
       return NULL;
    }
    else{
        p = stk->top;
        d = p->d;
        stk->top = stk->top->next;
        stk->cnt--;
    }
	return d;
}

//Function to show movement
void movement(char from, char to, int disk){
    printf("\nDisk %d moved from peg %c to peg %c", disk, from, to);
}


//Function to set ground rules for movement of disks
int move_between_two(stack *src, stack *dest, char s, char d){
    int top_1 = pop(src);               //top disk of source stack
    int top_2 = pop(dest);              //top disk of destination stack

    //if either stack is empty, the popped disk from the other stack will always go into the empty stack
    if(top_1 == NULL){
        push(src, top_2);
        movement(d, s, top_2);
    }
    else if(top_2 == NULL){
        push(dest, top_1);
        movement(s,d,top_1);
    }
    //if the top disk in one stack larger than the top disk in other stack, then the smaller disk goes on top of the larger disk
    else if(top_1>top_2){
        push(src, top_1);
        push(src, top_2);
        movement(d,s,top_2);
    }

    else if(top_1<top_2){
        push(dest, top_2);
        push(dest, top_1);
        movement(s,d,top_1);
    }
}


//Function to implement TOH logic. According to the logic, if no of moves is:
//a. gives remainder 1 on divided by three: top disk moves between source and destination
//b. gives remainder 2 on divided by three: top disk moves between source and auxiliary
//c. gives remainder 0 on divided by three: top disk moves between destination and auxiliary

void iterative_toh(stack *src, stack *aux, stack *dest, int no ){
    int i, no_of_moves;
    char temp;
    char s = 'A';
    char a = 'B';
    char d = 'C';
    //If no of disks is even, the auxiliary and destination stacks are interchanged
    if (no%2 == 0){
        temp = a;
        a = d;
        d = temp;
    }
    no_of_moves = pow(2,no) - 1;

    //pushing the disks into the source stack. Larger disks pushed first
    for (i= no; i>=1; i--){
        push(src, i);
    }
    for(i=1; i<= no_of_moves; i++){
        if(i%3 == 1)
        move_between_two(src, dest, s, d);

        else if(i%3 == 2)
        move_between_two(src, aux, s,a);

        else if(i%3 == 0)
        move_between_two(aux, dest, a,d);
    }
}


