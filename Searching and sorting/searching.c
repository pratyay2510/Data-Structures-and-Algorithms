#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function Prototypes
void sort(int arr[], int n);
int sequential(int arr[], int e, int n);
int binary(int arr[], int e, int n);
void display(int arr[], int n);

int main(){
    int n,i,element;
    printf("Enter the number of elements in the array:\t");
    scanf("%d", &n);
    int array[n];

    //Randomly allocating values to the array
    for(i=0;i<n;i++){
        array[i] = rand()%100;
    }

    //Sorting array
    sort(array,n);

    //Printing the array
    printf("\n-------------------ARRAY-------------\n");
    display(array, n);
    printf("---------------------------------------------\n");

    //Asking for the required element
    printf("\nEnter the number you want to find:\t");
    scanf("%d", &element);

    //Searching
    int seq = sequential(array, element, n);
    int bin = binary(array,element,n);

    //Displaying the result
    printf("\n\nResult:\t");
    if(seq==1 && bin==1){
        printf("Element Found.\n\n");
    }
    else if (seq!=bin){
        printf("Something is wrong.\n\n");
    }
    else{
        printf("Element not found.\n\n");
    }
}

//Insertion sort
void sort(int arr[], int n){
    int i, value, position;
    for(i=1;i<n;i++){                                       //Goes through the loop.
        value = arr[i];                                     //Value of present index
        position = i;

        while((position>0) && (arr[position-1]>value)){     //This sees if the preceeding element is smaller than current value
            arr[position] = arr[position-1];                //If yes then the preceeding element goes one place to the right
            position -= 1;                                  //Checks for all positions preceeding current position moves elements accordingly.
        }
        arr[position] = value;                              //The current value is then inserted at the place which is empty after
    }                                                       //its value is moved to the right. Else it remains at same place.
}

//Sequential search
int sequential(int arr[], int element, int n){
    int pos=0;
    int found = 0;
    int len = n;
    printf("\n\nFor Sequential search:\n");
    while((pos<len)&&(found!=1)){                           //Checks every element from the start
        printf("\nChecking element %d", arr[pos]);          //Prints the element that the algorithm is checking right now
        if(arr[pos]== element){
            found = 1;                                      //Found becomes 1 and loop ends if there is a match
        }
        else{
            pos+=1;                                         //Moves ahead if the present element not a match
        }
    }
    return found;
}

//Binary search
int binary(int arr[], int element,int n){
    int first = 0;                                          //Keeps track of first element
    int last = n-1;                                         //Keeps track of last element
    int found = 0;
    int mid;                                                //Middle element, the element that gets checked at every iteration
    printf("\n\n\n\nFor Binary search:\n");
    while((found!=1)&&(last>=first)){
        mid = (last+first)/2;
        printf("\nChecking element %d", arr[mid]);          //Prints the element the algorithm is checking right now
        if(arr[mid]==element){
            found = 1;
        }
        else if(element<arr[mid]){                          //If the required element is lesser than the current element,
            last = mid-1;                                   //the last variable becomes the one before the current element
        }
        else{                                               //If the required element is greater than the current element,
            first = mid+1;                                  //the first variable becomes the one after the current element
        }
    }
    return found;
}

//Displaying the array
void display(int arr[], int n){
    int i;
    printf("[");
    for(i=0;i<n-1;i++){
        printf("%d,", arr[i]);
    }
    printf("%d", arr[n-1]);
    printf("]\n");
}
