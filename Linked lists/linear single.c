# include <stdio.h>
# include <stdlib.h>


typedef char data;

struct node{
    data d;
    struct node *next;
};

typedef struct node snode;

snode *head=NULL, *temp, *newnode, *tail = NULL, *prev;


//To check if list is empty or not. Checking for underflow.
int isEmpty(){
    if((head == NULL)){
        return 1;
    }
    else{
        return 0;
    }
}


//Count the number of nodes
int count(){
    int cnt = 0;
    temp = head;
    if(isEmpty()){
        printf("List is empty!!!");
    }
    else{
        while(temp!= NULL){
            cnt++;
            temp = temp->next;
        }
    }
    return cnt;
}


//Creating a node
snode* getnode(data d){
    newnode = (snode*)malloc(sizeof(snode));
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}



//Inserting node at beginning
int insert_beginning(){
    char d,t;
    printf("\n\nEnter the data you want to insert at beginning:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list created yet so creating list..\n");
        head = tail = newnode;
        head->next = tail->next = NULL;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    printf("\nValue %c inserted at the beginning",d );
    return 0;
}



//Inserting node at end
int insert_end(){
    char d,t;
    printf("\n\nEnter the data you want to insert at end:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list created yet so creating list..\n");
        head = tail = newnode;
        head->next = tail->next = NULL;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
    printf("\nValue %c inserted at the end",tail->d );

}



//Insert node at any position
int insert(){
    char d,t;
    printf("\n\nEnter the data you want to insert:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list previously present so creating list..\n");
        head = tail = newnode;
        head->next = tail->next = NULL;
    }
    else{
        int x,i;
        int cnt = count();
        printf("Enter the position where you want to insert the data %c:", d);
        scanf("%d", &x);

        //We could have called the insert_begninning() function here but since that function also asks for user input so,
        //to avoid that we used the insertion part of the code alone.
        if(x==1){
            newnode->next = head;
            head = newnode;
        }

        else{
                if(x>1 && x<=cnt){
                    temp = head;
                    for(i=1;i<x-1;i++){
                        temp = temp->next;
                    }
                    newnode->next = temp->next;
                    temp->next = newnode;
                }

                else{
                    printf("SORRY! OUT OF BOUNDS!!\n");
                }
            }
            printf("\nValue %c inserted at position %d",d,x );
        }
    }



//Delete node from any position
int del(){
    int p,i;
    int cnt = count();
    printf("\n\nEnter the position of the node you want to delete:");
    scanf("%d", &p);
    if(isEmpty()){
        printf("Nothing to delete!!!");
    }
    else{
        if(p==1){
        temp = head;
        head = temp->next;
        printf("\nValue %c deleted from beginning",temp->d,p );
        free(temp);

    }
    else{

        if(p>1 && p<=cnt){
            temp = head;
            for(i=1;i<p;i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            printf("\nValue %c deleted from position %d",temp->d,p );
            free(temp);
        }
        else{
            printf("Out of bounds!!!");
        }
    }
    }
}



//Printing nodes
int display(){
    temp = head;
    int i = 1;
    if (isEmpty()){
        printf("Linked list is empty!!");
    }
    else{
        printf("\n--------------------------------------------");
        while(temp!= NULL){
            printf("\nData in %d th node is %c", i, temp->d);
            temp = temp->next;
            i+=1;
        }
        printf("\n--------------------------------------------");
    }
    return 0;
}



int main(){

    insert_beginning();
    insert_end();
    insert_end();
    insert_beginning();
    insert();
    del();
    display();
    printf("\n\nThe value in the head node is %c", head->d);
    printf("\nTotal number of nodes : %d", count());
    return 0;
}
