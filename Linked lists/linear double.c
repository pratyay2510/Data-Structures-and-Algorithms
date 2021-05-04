# include <stdio.h>
# include <stdlib.h>


typedef char data;

struct node{
    data d;
    struct node *next;
    struct node *prev;
};

typedef struct node snode;

snode *head=NULL, *tail=NULL, *temp, *newnode, *y;


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
        head->next = tail->prev = NULL;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    printf("\nValue %c inserted in the beginning", d);
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
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    printf("\nValue %c inserted in the end", d);
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
        head = tail = newnode;
        head->next = tail->prev = NULL;
    }
    else{
        int x,i;
        int cnt = count();
        printf("\n\nEnter the position where you want to insert the data %c:", d);
        scanf("%d", &x);

        if(x==1){
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }

        else{
                if(x>1 && x<=cnt){
                    temp = head;
                    for(i=1;i<x;i++){
                        y = temp;
                        temp = temp->next;
                    }
                    y->next = newnode;
                    newnode->next = temp;
                    temp->prev = newnode;
                    newnode->prev = y;
                }
                else{
                    printf("SORRY! OUT OF BOUNDS!!\n");
                }
            }
            printf("\nValue %c inserted at position %d", d, x);
        }
    }



//Delete node from any position
int del(){
    int p,i;
    int cnt = count();
    printf("\nEnter the position of the node you want to delete:");
    scanf("%d", &p);
    if(isEmpty()){
        printf("Nothing to delete!!!");
    }
    else{
            if(cnt==1){
                temp = head;
                tail = NULL;
                head = temp->next;
                printf("\nValue %c deleted", temp->d);
                free(temp);
                }

            else{
                    if(p==1){
                    temp = head;
                    head->next->prev = NULL;
                    head = temp->next;
                    printf("\nValue %c deleted from the beginning", temp->d);
                    free(temp);
                    }
                    else{

                        if(p>1 && p<cnt){
                            temp = head;
                            for(i=1;i<p;i++){
                                y = temp;
                                temp = temp->next;
                            }
                            y->next = temp->next;
                            temp->next->prev = y;
                            printf("\nValue %c deleted from position %d", temp->d, p);
                            free(temp);
                        }
                        else{
                                if(p==cnt){
                                    temp = tail;
                                    tail->prev->next = NULL;
                                    tail = temp->prev;
                                    printf("\nValue %c deleted from the end", temp->d);
                                    free(temp);
                                }
                            else{
                                printf("OUT OF BOUNDS!!!");
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
        printf("\n\nForward\n--------------------------------------------");
        while(temp!= NULL){
            printf("\nData in %d th node is %c", i, temp->d);
            temp = temp->next;
            i+=1;
        }
        printf("\n--------------------------------------------");
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
        printf("\n\nBackward\n--------------------------------------------");
        for(temp = tail; temp!=NULL; temp = temp->prev){
                printf("\nData in %d th node is %c", i, temp->d);
                i--;
        }
        printf("\n--------------------------------------------");
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
    printf("\n\nTotal number of nodes : %d", count());
    printf("\nThe head node has value : %c", head->d);
    printf("\nThe tail node has value : %c", tail->d);
    return 0;

}
