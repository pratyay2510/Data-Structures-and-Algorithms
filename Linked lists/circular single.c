# include <stdio.h>
# include <stdlib.h>

typedef char data;

struct node{
    data d;
    struct node *next;
};

typedef struct node snode;

snode *head=NULL, *temp, *newnode, *y, *prev;
//Implemented the last program with a head and a tail hence implementing this with just the head.


//Creating a node
snode* getnode(data d){
    newnode = (snode*)malloc(sizeof(snode));
    newnode->d = d;
    newnode->next = NULL;
    return newnode;
}


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
    int cnt = 1;
    temp = head;
    if(isEmpty()){
        printf("\nList is empty!!!");
    }
    else{
        while(temp->next != head){
            cnt++;
            temp = temp->next;
        }
    }
    return cnt;
}


//Inserting node at beginning
int insert_beginning(){
    char d,t;
    printf("\n\nEnter the data you want to insert at beginning:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("\nNo list created yet so creating list..\n");
        head = newnode;
        head->next = head;
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    printf("\nValue %c inserted at the beginning",head->d );
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
        head = newnode;
        head->next = head;
    }
    else{
        temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    printf("\nValue %c inserted at the end",newnode->d );
    return 0;
}


//Insert node at any position
int insert(){
    char d,t;
    printf("\n\nEnter the data you want to insert:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list created yet so creating list..\n");
        head = newnode;
        head->next = head;
    }
    else{
        int x,i;
        int cnt = count();
        printf("\nEnter the position where you want to insert the data %c:\t", d);
        scanf("%d", &x);

        if(x==1){
            temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = newnode;
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
            printf("\nValue %c inserted at position %d",newnode->d, x);
        }
    }


//Deleting element at beginning
int del_begin(){
    int i;
    int cnt = count();

    if(isEmpty()){
        printf("Nothing to delete !! List is empty!!");
    }
    else{
        if (cnt == 1){
            temp = head;
            head = NULL;
            printf("\nValue %c deleted", temp->d);
            free(temp);
        }
        else{
            temp = head;
            y = head;
            while(temp->next != head){
                temp = temp->next;
            }
            head = y->next;
            temp->next = head;
            printf("\nValue %c deleted from beginning",y->d );
            free(y);
        }
    }
    return 0;
}


//Deleting element at any place
int del(){
    int p,i;
    int cnt = count();
    printf("\nEnter the position of the node you want to delete:");
    scanf("%d", &p);

    if(isEmpty()){
        printf("Nothing to delete !! List is empty!!");
    }
    else{
        if (cnt == 1){
            temp = head;
            head = NULL;
            printf("\nValue %c deleted", temp->d);
            free(temp);
        }
        else{
            if(p==1){
                del_begin();
            }
            else{
                if(p>1 && p<=cnt){
                    temp = head;
                    for(i=1;i<p;i++){
                        prev = temp;
                        temp = temp->next;
                        }
                    prev->next = temp->next;
                    printf("\nValue %c deleted from position %d", temp->d, p);
                    free(temp);
                }
                else{
                    printf("OUT OF BOUNDS!!!");
                }
            }
        }
    }
}

//Displaying the list
int display(){
    temp = head;
    int i=1;
    if (isEmpty()){
        printf("Linked list is empty!!");
    }
    else{
        printf("\n--------------------------------------------");
        while(temp->next!= head){
            printf("\nData in %d th node is %c", i, temp->d);
            temp = temp->next;
            i+=1;
        }
        printf("\nData in %d th node is %c", i, temp->d);
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
    printf("\n\nThe data in the head is:%c", head->d);
    printf("\n\nTotal number of nodes : %d", count());
    return 0;
}
