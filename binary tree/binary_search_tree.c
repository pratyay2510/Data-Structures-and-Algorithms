#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SPACE 10

//Defining a node
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node snode;

//Function prototypes
int count(snode *root);                             //To count the number of nodes in a tree
snode* newNode(int );                               //To create a new node
snode* insert(snode *, int );                       //To insert a node to the tree
snode* inorder_next(snode *root);                    //To find inorder successor
snode* del(snode *, int);                           //To delete a node
void inorder(snode *);                              //To visualise the tree in inorder traversal
void display_util(snode *root, int space);          //Utility function to display the tree
void display(snode *root);                          //Display the tree

void main(){
int n=1,d,f;
    snode *root;
    root = NULL;
    while(n){
        printf("\n\nWhat do you want to do ?");
        printf("\n0 -> Exit");
        printf("\n1 -> Insert");
        printf("\n2 -> Delete");
        printf("\n3 -> Display");
        printf("\nYour choice : ");
        scanf("%d", &n);
        switch(n){
            case 0:break;
            case 1: printf("Enter the number you want to insert:");
                    scanf("%d", &d);
                    root = insert(root,d);
                    break;
            case 2: printf("Enter the number you want to delete:");
                    scanf("%d", &f);
                    root = del(root, f);
                    break;
            case 3: printf("Displaying the contents of the tree in inorder method : ");
                    inorder(root);
                    printf("\nThe tree : \n");
                    display(root);
                    break;
            default: printf("\nChoice Invalid!!"); break;
        }
    }

    printf("\n\nNumber of nodes in the tree is : %d", count(root));
    printf("\nDisplaying the tree in 2D: \n");
    display(root);
    printf("\n\nInorder traversal of tree : ");
    inorder(root);
}




//To count number of nodes in a tree
int count(snode *root){
    if(root == NULL)                                        //Base case
        return 0;
    return (1 + count(root->left) + count(root->right));    //recursion for left and right sub trees
}

//To create a node
snode* newNode(int data){
  snode* node = (snode*)malloc(sizeof(snode));          //Size of snode allotted to the variable node
  node->data = data;                                    //Data stored in the new node to be created
  node->left = NULL;
  node->right = NULL;
  return(node);
}

//To insert en element into the binary search tree
snode *insert(snode *root, int d){
    snode *getnode, *current;
    if(root == NULL){                                   //If the root in question is empty, value inserted at the root
        root = newNode(d);
        return root;
    }
    else{
        if(d < root->data){                             //If data is less than the data of the current root, we recursively
            root->left = insert(root->left,d);          //call insert on the left subtree
        }

        else{
            root->right = insert(root->right, d);       //If data is more than the data of the current root, we recursively
        }                                               //call insert on the right subtree
    }
    return root;
}

//To find inorder successor
snode* inorder_next(snode* root){
    snode* current = root;
    while (current && current->left != NULL)            //Loops until we find the leftmost leaf
        current = current->left;
    return current;
}

//For deleting a node
snode *del(snode *root, int d){
    snode *temp;
    if (root == NULL)                                   //Base case
        return root;

    if (d < root->data)
        root->left = del(root->left, d);                //If value is less that current node, go left
    else if (d > root->data)
        root->right = del(root->right, d);       //If value is more than current node, go right

    else{                                               //If value equals current node, then this node is to be deleted

        if(!root->left){                                //If no left node, we delete the node and return the node on the right
            temp = root->right;                         //to the place which we deleted
            free(root);
            return temp;
        }
        else if(!root->right){                          //If no right node, we delete the node and return the node on the right
            temp = root->left;                          //to the place which we deleted
            free(root);
            return temp;
        }
        else{                                           //If both left and right nodes present
            temp = inorder_next(root->right);           //We find the inorder successor to the present root
            root->data = temp->data;                    //Allocates the value of the inorder successor to the present root
            root->right = del(root->right,temp->data);  //Deletes the inorder successor
        }
    }
    return root;
}

//For inorder traversal of the tree. Used for displaying the contents of the tree
void inorder(snode *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

//As a utility function to display a tree
void display_util(snode *root, int space){
    if (root == NULL)
        return;
    space += SPACE;

    display_util(root->right, space);

    printf("\n");
    for (int i = SPACE; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    display_util(root->left, space);
}

//Displaying the tree
void display(snode *root){
    display_util(root,0);
}
