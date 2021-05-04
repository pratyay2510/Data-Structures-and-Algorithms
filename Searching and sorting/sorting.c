#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function prototypes
void swap(int arr[], int i, int j);
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int l, int h);
void display(int arr[], int n);

int main(){
    clock_t t1,t2,t3,t4,t5;                                                 //Used to calculate time required for each sorting method.
    int n,i;
    printf("Enter the number of elements in the array:\t");
    scanf("%d", &n);
    int arr_1[n],arr_2[n],arr_3[n],arr_4[n],arr_5[n],len;                   //Creates 5 similar arrays used for sorting using
                                                                            //the 5 techniques
    //Creating arrays
    for(i=0;i<n;i++){
        arr_1[i] = arr_2[i] = arr_3[i] = arr_4[i] = arr_5[i] = rand()%100;
    }

    //Creating nearly sorted data
    int arr1[n],arr2[n],arr3[n],arr4[n],arr5[n];                            //Creates 5 similar arrays
    for(i=0;i<n;i++){
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = i+1;
    }
    for(i=0;i<n-1;i+=4){                                                    //Picks elements at intervals of 4
        int r = rand()%(n);                                                 //and swaps them with some random value in the array
        swap(arr1,i,r);
        swap(arr2,i,r);
        swap(arr3,i,r);
        swap(arr4,i,r);
        swap(arr5,i,r);
    }                                                                       //arrays are now nearly sorted

    //Displaying unsorted array. All 5 arrays are the same.
    /*printf("\n\n-------------------UNSORTED ARRAY-------------\n");
    display(arr_1, n);
    printf("---------------------------------------------\n\n");*/

    //Displaying nearly sorted array
    /*printf("\n\n-------------------NEARLY SORTED ARRAY-------------\n");
    display(arr1, n);
    printf("---------------------------------------------\n\n");*/

    //Sorting
    t1 = clock();
    //bubble_sort(arr_1,n);
    bubble_sort(arr1,n);
    t1 = (clock() -t1);

    t2 = clock();
    //selection_sort(arr_2,n);
    selection_sort(arr2,n);
    t2 = clock()-t2;

    t3 = clock();
    //insertion_sort(arr_3,n);
    insertion_sort(arr3,n);
    t3 = clock()-t3;

    t4 = clock();
    //merge_sort(arr_4,0,n-1);
    merge_sort(arr4,0,n-1);
    t4 = clock()-t4;

    t5 = clock();
    //quick_sort(arr_5, 0, n-1);
    quick_sort(arr5, 0, n-1);
    t5 = clock()-t5;


    //Displaying sorted array
    printf("\n\n---------------TIME COMPARISON-------------");
    printf("\nBubble sort\t:");
    //display(arr1, n);
    printf("Time taken : %f\n",(double)(t1));
    printf("\nSelection sort\t:");
    //display(arr2, n);
    printf("Time taken : %f\n",(double)(t2));
    printf("\nInsertion sort\t:");
    //display(arr3, n);
    printf("Time taken : %f\n",(double)(t3));
    printf("\nMerge sort\t:");
    //display(arr4, n);
    printf("Time taken : %f\n",(double)(t4));
    printf("\nQuick sort\t:");
    //display(arr5, n);
    printf("Time taken : %f\n",(double)(t5));
    printf("---------------------------------------------");


}


//To swap two elements
void swap(int arr[],int i,int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Bubble sort
void bubble_sort(int arr[],int n){
    int i,j;
    for(i=n-1;i>0;i--){              //Number of iterations = n-1 as two items are compared on each pass.
        for(j=0;j<i;j++){            //In every iteration, it moves the max value to the end. Then the next iteration goes on till
            if (arr[j]>arr[j+1])     //one place lesser than the last one as all elements from i to n are already in place.
                swap(arr,j,j+1);
        }
    }
}

//Selection sort
void selection_sort(int arr[], int n){
    int i,j;
    for(i=0;i<n-1;i++){                      //Moving the boundary of the unsorted sub-array one by one.
        int min_position = i;                //The i is given as the minimum position every time.
        for(j=i+1;j<n;j++){                  //As loop goes from i+1 to the last element, it checks if arr[j] is less than arr[min_position]
            if (arr[j]<arr[min_position])    //If it is, then that index becomes min_position. This finds the minimum number from i+1 to end.
                min_position = j;
        }
        swap(arr, min_position, i);         //Now we swap the ith index with min_position thus placing the minimum number at i.
    }                                        //The next iteration will go from i+1 to n and find the next smallest number and put it at pos i+1.
}

//Insertion sort
void insertion_sort(int arr[], int n){
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

//Merging two arrays into one.
/*This method is used for merge sort where two sorted arrays are merged in a way that the merged array is also sorted.*/
void merge(int arr[], int l, int m , int r){
    int i=0,j=0,k=0;
    int n_left = m-l+1;         //The left array will have the elements from beginning to middle.
    int n_right = r-m;          //Right array will have elements from middle+1 to end.
    int L[n_left], R[n_right];
    for(i=0;i<n_left;i++){      //Creating left array
        L[i] = arr[l+i];
    }
    for(j=0;j<n_right;j++){     //creating right array
        R[j] = arr[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n_left && j<n_right){   //Merges two arrays.
        if(L[i]<R[j]){              //If the left ones element is smaller than the right ones corresponding element then left element is inserted
            arr[k] = L[i];          //This goes on till one of the sub arrays are exhausted.
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n_left){                //After that the rest of the items from the bigger sub-array is inserted. They are already sorted.
        arr[k] = L[i];              //If left array has items left, they are inserted.
        i++;
        k++;
    }
    while(j<n_right){               //if right array has items left, they are inserted.
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Merge sort
void merge_sort(int arr[], int l, int r){
    int i,j,m;
    if(l<r){
        m = (l + r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);      //Partitions array into two halves which is repeated till only one item left in each array and then they are
        merge(arr, l,m,r);          //merged using the merge function. The merge function takes care of the fact that the lesser value goes first.
    }
}

/*For the quicksort method. This places the pivot element in the right place in the array
and places all elements lesser to it to tis left and all elements more than it to its right.*/
//Creating a partition.
int partition(int arr[], int low, int high){
    int i = low-1;                      //Here arr[high] is the pivot.
    int j;
    for(j=low;j<high;j++){
        if(arr[j]<arr[high]){           //We traverse from 0 to high and check at each point if arr[j] is less than pivot.
            i++;                        //If it is less, then we increase the i by 1
            swap(arr, j, i);            //and swap that item with arr[i].
        }
    }                                   //This means all items left of i including arr[i] are less than pivot.
    swap(arr, i+1, high);               //Now we swap arr[i+1] and the pivot.This means all items less than pivot ar to its left.
    return (i+1);                       //Returns the index from which partition takes place.
}

//Quick sort
void quick_sort(int arr[], int l, int h){
    if (l<h){
        int partition_index = partition(arr,l,h);  //Gets the partition index
        quick_sort(arr, l, partition_index-1);     //Recursive calls which sort the partitioned arrays and makes further partitions and so on.
        quick_sort(arr, partition_index+1, h);
    }
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
