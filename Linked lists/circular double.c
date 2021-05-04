# include <stdio.h>
# include <stdlib.h>


typedef char data;

struct node{
    data d;
    struct node *next;
    struct node *prev;
};
typedef struct node snode;

snode *head=NULL, *temp, *newnode, *tail = NULL, *y;


//Creating a node
snode* getnode(data d){
    newnode = (snode*)malloc(sizeof(snode));
    newnode->d = d;
    newnode->next = NULL;
    newnode->prev = NULL;
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
        printf("List is empty!!!");
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
    printf("\nEnter the data you want to insert at beginning:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list created yet so creating list..\n");
        head = tail = newnode;
        head->next = tail->next = head;
        head->prev = tail->prev = tail;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        head->prev = tail;
        tail->next = head;
    }
    printf("\nValue %c inserted at beginning of list.\n", d);
    return 0;
}


//Inserting node at end
int insert_end(){
    char d,t;
    printf("\nEnter the data you want to insert at the end:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list created yet so creating list..\n");
        head = tail = newnode;
        head->next = tail->next = head;
        head->prev = tail->prev = tail;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        head->prev = tail;
        tail->next = head;
    }
    printf("\nValue %c inserted at end of list.\n", d);
    return 0;
}


//Insert node at any position
int insert(){
    char d,t;
    printf("\nEnter the data you want to insert:\t");
    scanf("%c", &d);
    scanf("%c", &t);
    newnode = getnode(d);
    if(isEmpty()){
        printf("No list created yet so creating list..\n");
        head = tail = newnode;
        head->next = tail->next = head;
        head->prev = tail->prev = tail;
    }
    else{
        int x,i;
        int cnt = count();
        printf("\nEnter the position where you want to insert the data %c:", d);
        scanf("%d", &x);
        if(x==1){
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            head->prev = tail;
            tail->next = head;
        }
        else{
                if(x>1 && x<=cnt){
                    temp = head;
                    for(i = 1; i<x; i++){
                        y = temp;
                        temp = temp->next;
                    }
                    y->next = newnode;
                    newnode->prev = y;
                    newnode->next = temp;
                    temp->prev = newnode;
                }
                else{
                    printf("\nSORRY! OUT OF BOUNDS!!\n");
                }
            }
            printf("\nValue %c inserted at position %d\n", d, x);
        }
    }


//Delete node from beginning
int del_begin(){
    int i;
    int cnt = count();
    char u;
    if(isEmpty()){
        printf("Nothing to delete !! List is empty!!");
    }
    else{
        if (cnt == 1){
            temp = head;
            u = temp->d;
            head = tail = NULL;
            free(temp);
        }
        else{
            temp = head;
            u = temp->d;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            free(temp);
        }
    }
    printf("\nValue %c deleted from the beginning of the list\n", u);
    return 0;
}


//Delete from end of list
int del_end(){
    int i;
    int cnt = count();
    char u;
    if(isEmpty()){
        printf("Nothing to delete !! List is empty!!");
    }
    else{
        if (cnt == 1){
            temp = tail;
            u = temp->d;
            head = tail = NULL;
            free(temp);
        }
        else{
            temp = tail;
            u = temp->d;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            free(temp);
        }
    }
    printf("\nValue %c deleted from the end of the list\n", u);
    return 0;
}

//Deleting element at any place
int del(){
    int p,i;
    int cnt = count();
    char u;
    printf("\n\nEnter the position of the node you want to delete:");
    scanf("%d", &p);

    if(isEmpty()){
        printf("Nothing to delete !! List is empty!!");
    }
    else{
        if (cnt == 1){
            temp = head;
            head = NULL;
            free(temp);
        }
        else{
            if(p==1){
                del_begin();
            }
            else{
                if(p==cnt){
                    del_end();
                }
                else{
                    if (p>1 && p<cnt){
                        temp = head;
                        for(i = 1; i<p; i++){
                            temp = temp->next;
                        }
                        u = temp->d;
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        printf("\nValue %c deleted from position %d\n", u, p);
                        free(temp);
                    }
                }
            }
        }
    }
}



//Displaying nodes in forward direction
int display_front(){
    temp = head;
    int i = 1;
    if (isEmpty()){
        printf("Linked list is empty!!");
    }
    else{
        printf("\n\nForward\n-----------------------------");
        while(1){
            printf("\nData in %d th node is %c", i, temp->d);
            if(temp == tail){
                break;
            }
            else{
                temp = temp->next;
                i++;
            }
        }
        printf("\n------------------------------");
    printf("\n");
    }
    return 0;
}


//Displaying nodes in backward direction
int display_back(){
    temp = tail;
    int i = count();
    if (isEmpty()){
        printf("Linked list is empty!!");
    }
    else{
        printf("\n\nBackward\n-----------------------------");
        while(1){
            printf("\nData in %d th node is %c", i, temp->d);
            if(temp == head){
                break;
            }
            else{
                temp = temp->prev;
                i--;
            }
        }
        printf("\n-----------------------------");
        printf("\n");
    }
    return 0;
}


int main(){
    insert_beginning();
    insert_end();
    insert();
    del();
    display_front();
    display_back();
    printf("\n\nNo of nodes = %d", count());
    printf("\n\nThe data in the head is:%c", head->d);
    printf("\n\nThe data in the tail is:%c\n\n", tail->d);
}
