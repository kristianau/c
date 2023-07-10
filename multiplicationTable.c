#include <stdio.h>

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

    Your version of the program must print the same result as the expected output.

*/

int main()
{
	/* your code */
	// 1.get the size for the matrix
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
	int multiplication[size][size];
	
	// 3.fill the matrix:
	for(int i = 0; i < size; i++){
	    for(int j = 0; j < size; j++){
	        multiplication[i][j] = (i+1) * (j+1);
	    }
	}
	
	// 4.print the matrix:
	for(int i = -1; i < size; i++){
	    for(int j = -1; j < size; j++){
	        if(i == -1 && j == -1){
	            printf("    ");
	        } else if(i == -1 && j != -1){
	            printf("%4d", multiplication[0][j]);
	        } else if(i != -1 && j == -1){
	            printf("%4d", multiplication[i][0]);
	        } else{
	            printf("%4d", multiplication[i][j]);
	        }
	    }
	    printf("\n");
	}
	return 0;
}