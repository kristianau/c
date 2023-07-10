#include <stdio.h>
#include <stdlib.h> // this for malloc and free

/*
* Author: Kristiana Usacka
* Date: July 10, 2023
* Description:
    Scenario
    Write a program that displays the multiplication table of a given size.

    First, your program should ask the user to specify the size (height and weight are equal, so one number should be enough).

    If the size is greater than 20, the program should print the message: Matrix too big..

    Then it should allocate a matrix and fill this matrix with appropriate values (remember: the element of [0][0] should store the multiplication result of 1 and 1).

    Then the program should print the multiplication table, four characters per cell. Finally, all memory must be freed.

    Your version of the program must print the same result as the expected output. */

int main(){
    /* your code */
    // 1.get the size from user
    int size;
    scanf("%d", &size);

    if(size > 20){
        printf("Matrix too big.\n");
        return 0;
    } else if(size < 1){
        printf("Are you kidding?\n");
        return 0;
    }

    // 2.create the matrix:
    int **multiplication; // a pointer to pointer array
    multiplication = (int **) malloc(size * sizeof(int *)); // rows for the table

    for(int i = 0; i < size; i++){ // go through all of the pointers and assign columns
        *(multiplication + i) = (int *) malloc(size * sizeof(int)); // each row will contain a pointer pointing to a region of memory for ints of count 'size'
    }

    // 3.assign the values:
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            *(*(multiplication + i) + j) = (i+1) * (j+1);
            // I should be able to write it like this as well:
            // multiplication[i][j] = (i+1) * (j+1);
        }
    }

    // 4.print the matrix:
    for(int i = -1; i < size; i++){
        for(int j = -1; j < size; j++){
            if(i == -1 && j == -1){
	            printf("    ");
	        } else if(i == -1 && j != -1){
	            printf("%4d", *(*(multiplication) + j)); // multiplication[0][j]
	        } else if(i != -1 && j == -1){
	            printf("%4d", **(multiplication + i)); // multiplication[i][0]
	        } else{
	            printf("%4d", *(*(multiplication + i) + j)); // multiplication[i][j]
	        }
        }
        printf("\n");
    }

    // 5.free the memory:
    for(int i = 0; i < size; i++){
        free(*(multiplication + i)); // iterate through rows and free all pointers to int arrays
    }
    free(multiplication); // free the pointer to poiters as well
}

// is there a way of making sure that I freed all memory?