# include <stdio.h>
# include <stdlib.h>

#define N 5

int stack[N];
int top = -1, temp;

int push(){
    int d;
    if (top == (N-1)){
        printf("\n\nThe stack is full. OVERFLOW");
    }
    else{
        if(top == -1){
            printf("The stack is empty. Pushing first item into stack...");
            printf("\nEnter the data you want to push into the stack:");
            scanf("%d", &d);
            top += 1;
            stack[top] = d;
        }
        else{
            printf("\nEnter the data you want to push into the stack:");
            scanf("%d", &d);
            top += 1;
            stack[top] = d;
        }
        printf("\nData %d pushed into the stack", d);
    }
    return 0;
}


int pop(){
    if(top == -1){
        printf("\nStack is empty!! Nothing to pop. UNDERFLOW!");
    }
    else{
        temp = stack[top];
        stack[top] = NULL;
        top -= 1;
    }
    printf("\nData %d popped from the stack.", temp);
    return 0;
}


int peek(){
    return(stack[top]);
}


int display(){
    int i;
    if(top == -1){
        printf("\n\nStack is empty\n");
    }
    else{
        printf("\n\n\n---------THE STACK---------");
        printf("\n--------------------------------------------");
        for(i=top;i>-1;i--){
            printf("\nData in node %d is %d", i+1, stack[i]);
        }
        printf("\n--------------------------------------------");
    }
}



int main(){

push();
push();
push();
push();
push();
push();
pop();
pop();
pop();
display();
printf("\nThe Data at the top of the stack : %d", peek());
printf("\nThe number of elements in the stack : %d", top+1);

}
