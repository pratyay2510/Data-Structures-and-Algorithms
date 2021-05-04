# include <stdio.h>
# include <stdlib.h>

typedef int data;

//Defining a node
struct Node{
	data d;
	struct node *next;
};
typedef struct Node node;

//Defining the stack
struct Stack{
	int cnt;
	node *top;
};
typedef struct Stack stack;

node *p, *newnode, *temp;
stack *stk;

//Initialise the stack.
//Useful for keeping a count for the number of nodes as calling a function to count
//the nodes is computationally a bit more expensive. (O(n))
void initialise(stack *stk){
	stk->cnt = 0;
	stk->top = NULL;
}

//Create a node
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
int push(stack* stk){
    int d,t;
    if(isempty(stk)){
        printf("\nStack is empty hence pushing the first data...");
        printf("\n\nEnter the data you want to push into the stack:\t");
        scanf("%d", &d);
        p = getnode(d);
        stk->top = p;
        p->next = NULL;
        stk->cnt = 1;
    }
    else{
        printf("\n\nEnter the data you want to push into the stack:\t");
        scanf("%d", &d);
        p = getnode(d);
        p->next = stk->top;
        stk->top = p;
        stk->cnt++;
    }
	printf("\nData %d pushed into the stack", d);
	return 0;
}

//Pop data out of the stack
int pop(stack* stk){
    if(isempty(stk)){
        printf("\nStack is empty hence nothing to pop..");
    }
    else{
        data d;
        p = stk->top;
        d = p->d;
        stk->top = stk->top->next;
        stk->cnt--;
        printf("\nData %d popped out of the stack.", d);
    }
	return 0;
}

//To look at the data at the top of the stack.
data peek(stack* stk){
    if(isempty(stk)){
        printf("\nSTACK IS EMPTY!!");
        return NULL;
    }
    else{
        return (stk->top->d);
    }
}

//To display stack
display(stack* stk){
    int i=1;
    if(isempty(stk)){
        printf("\nStack is empty.");
    }
    else{
        printf("\n\n\n---------THE STACK---------");
        printf("\n--------------------------------------------");
        for(temp=stk->top;temp!=NULL;i++){
            printf("\nData in node %d is %d", i, temp->d);
            temp = temp->next;
        }
        printf("\n--------------------------------------------");
    }
}

int main(){

    stack s;
    initialise(&s);
    push(&s);
    push(&s);
    push(&s);
    push(&s);
    pop(&s);
    pop(&s);
    display(&s);
    printf("\nThe Data at the top of the stack is %d", peek(&s));
    printf("\nThe number of nodes in the stack are : %d", s.cnt);
    return 0;
}
