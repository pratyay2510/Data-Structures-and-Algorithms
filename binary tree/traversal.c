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
snode* newNode(int data);                               //To create a new node
snode *sample();                                        //To create  a sample tree
snode *create_tree();                                   //To create a tree from inputs by the user
void preorder(snode *);
void inorder(snode *);
void postorder(snode *);
void display_util(snode *root, int space);          //Utility function to display the tree
void display(snode *root);                          //Display the tree

int main(){
    int n;
    snode *root;
    printf("\n\nWhat tree do you want to make ?");
    printf("\n1 -> Sample");
    printf("\n2 -> According to user");
    printf("\nYour choice : ");
    scanf("%d", &n);
    switch(n){
        case 1: root = sample(); break;
        case 2: root = create_tree(); break;
        default: printf("\nChoice Invalid!!"); break;
    }
    printf("\n----------------Tree has been created---------------\n");
    printf("\n\nTRAVERSALS:");
    printf("\nPreorder traversal :\t");
    preorder(root);
    printf("\nInorder traversal :\t");
    inorder(root);
    printf("\nPostorder traversal :\t");
    postorder(root);
    printf("\n\nThe tree is:\n");
    display(root);
}


//To create a new node
snode* newNode(int data)
{
  snode* node = (snode*)malloc(sizeof(snode));   //Size of snode allotted to the variable node
  node->data = data;                             //Data stored in the new node to be created
  node->left = NULL;
  node->right = NULL;
  return(node);
}

//To create a sample tree
snode *sample(){
    snode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    /*
     The created tree is:

            1
           / \
          2   3
         / \   \
        4   5   6

    */
    return root;
}

//Create a tree by the user
snode *create_tree(){
    snode *getnode;
    int r,w;
    printf("\nEnter value of  node(If you want no node, enter -1): ");
    scanf("%d", &r);
    if(r== -1)
        return NULL;
    getnode = newNode(r);
    printf("\nDo you want children to node %d?(-1 for no, 1 for yes)", getnode->data);
    scanf("%d", &w);
    if(w==1){
        printf("Enter left child of %d",r);
        getnode->left = create_tree();
        printf("Enter right child of %d", r);
        getnode->right = create_tree();
    }


    return getnode;
}

//Preorder traversal
void preorder(snode *root){
    if (root == NULL)
        return;
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

//Inorder traversal
void inorder(snode *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

//Postorder traversal
void postorder(snode *root){
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
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
