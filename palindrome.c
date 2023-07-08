#include <stdio.h>
#include <string.h>

/*
 * Author: Kristiana Usacka
 * Date: July 7, 2023
 * Description:
    Scenario
    A palindrome is a word (or other sequence of characters) that reads the same backward or forward.

    Write a program that takes one word and prints its palindrome. You can use the for loop, the strlen function, and the %s format in scanf and print.

    You can use a new variable or one declared earlier for holding the reversed value of a word.

    Declare a string big enough to hold long words. For the record, you should use fgets instead of scanf in the future, especially when you want to have long strings with spaces.

    Your version of the program must print the same result as the expected output.

    Sample input
    book

    Expected output
    koob

    Sample input
    dictionary

    Expected output
    yranoitcid

*/

int main()
{
	/* your code */
	char input[255];
	char palindrome[255];
	int length;
	
	
	// after a suggestion in the task description I'll use fgets() instead of scanf():
	fgets(input, sizeof(input), stdin);
	length = strlen(input); // returns the value of characters including \0

    // Remove the newline character if it exists
    // fgets() adds a newline character at the end of input
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

	for(int i = 0; i < length; i++){
	    palindrome[i] = input[length-i]; // I need [length-i-1] so that the '\0' character is not copied to the palindrome[0] position
	}
	
	printf("%s", palindrome);
	
	return 0;
}