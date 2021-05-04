# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef int data;

//Defining a node
struct Node{
	data d;
	struct Node *next;
};
typedef struct Node node;

node *p, *newnode, *temp;

//Defining a stack
struct Stack{
	int cnt;
	node *top;
};
typedef struct Stack stack;


//Check underflow
int isEmpty(stack* stk){
	return (stk->cnt==0);
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


//Pushing data
void push(stack* stk, data d){
    p = getnode(d);
    if(isEmpty(stk)){
        stk->top = p;
        p->next = NULL;
        stk->cnt = 1;
    }
    else{
        p->next = stk->top;
        stk->top = p;
        stk->cnt++;
    }
}

//Popping data
int pop(stack* stk){
    if(isEmpty(stk)){
        return NULL;
    }
    else{
        data d;
        p = stk->top;
        d = p->d;
        stk->top = stk->top->next;
        stk->cnt--;
        return d;
    }
}


//To display stack
void display(stack* stk){
    int i=1;
    if(isEmpty(stk)){
        printf("\nStack is empty.\n");
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
    printf("Enter a postfix expression of not more than 30 characters. Type $ to end:\n");
    char exp[30];
    int c=0, n1, n2, n3, i = 0;
    char ch='.';
    while(ch!='\n')
    {
        scanf("%c",&ch);
        exp[c]=ch;
        c++;
    }
    stack *operandstack;
    operandstack->top=NULL;
    operandstack->cnt=0;

    while(exp[i]!='$')
    {
        // if the character is an operand ,push it to the stack
        if (isdigit(exp[i]))
            push(operandstack, exp[i]-'0' );
        else if (exp[i]==',')
        {
            i++;
            continue;
        }

        // if the character is an operator, pop two elements from stack apply the operator
        else
        {
            n1 = pop(operandstack);
            n2 = pop(operandstack);
            switch (exp[i])
            {
            case '+': push(operandstack, (n2+n1)); break;
            case '-': push(operandstack, (n2-n1)); break;
            case '*': push(operandstack, (n2*n1)); break;
            case '/': push(operandstack, (n2/n1)); break;
            case '^': push(operandstack, pow(n2,n1)); break;
            }
        }
        display(operandstack);
        i++;
    }
    printf("\n\nResult is: %d \n",pop(operandstack));
    return 0;
}

