#include <stdio.h>
#include <stdlib.h>


//Recursive tower of Hanoi function
int tower_of_hanoi(int no, char from, char to, char aux){
    if(no==1){
        printf("\nMove disk 1 from rod %c to rod %c", from, to);
    }
    else{
        tower_of_hanoi(no-1, from, aux, to);
        printf("\nMove disk %d from rod %c to rod %c", no, from, to);
        tower_of_hanoi(no-1, aux, to, from);
    }
    return 0;
}


int main(){
    int no;
    printf("\nEnter the number of disks you want to experiment with: \t");
    scanf("%d", &no);
    printf("\nThe moves in moving the disks from peg A to C via peg B are:\n\n");
    tower_of_hanoi(no, 'A', 'C', 'B');
    return 0;
}
