#include <stdio.h>
#include <ctype.h>

/*
* Author: Kristiana Usacka
* Date: June 7, 2023
* Description:
	Scenario
	Write a program that asks for the IP address in a human readable form, creates three substrings, and prints them.

	These substrings are created from parts 3, 2, and 1 of the last part of the IP address.

	These substrings should be created with the use of pointers or array indexing (whichever you prefer). If a given string doesn't have three dots, then the program should print the message: Error: not a valid address..

	Your program should also check if a given string consists only of digits and dots, and that there are no more than three digits in each block. You don't have to check if the numbers are smaller than 256.

	Note: You can use the isdigit function, but you can also write your own code to check whether or not a character is a digit.

	Your version of the program must print the same result as the expected output.

	Sample input
	255.255.255.255

	Expected output
	Last 3 parts: 255.255.255
	Last 2 parts: 255.255
	Last 1 part: 255

	Sample input
	127.0.0.1

	Expected output
	Last 3 parts: 0.0.1
	Last 2 parts: 0.1
	Last 1 part: 1

	Sample input
	255.2555.255.255

	Expected output
	Error: not a valid address.
*/


int main()
{
	/* your code */
	char input[255];
	printf("IP adress:\n");
	scanf("%s", input); // get the input from console
	printf("%s\n", input);
	
	
	// now I think I could create 3 pointers which point to specific places within the string input
	// and then print from those places
	char *last3Parts;
	char *last2Parts;
	char *last1Part;
	/* I'll assign these pointers within my validity checking loop: */
	
	int i = 0;
	int digitCount = 0;
	int dotCount = 0;
	// check for the input correctness:
	while (input[i] != '\0'){ // iterate through all characters
	    if (isdigit(input[i])) { // current char is a number
	        digitCount++;
	    } else if(input[i] == '.'){ // a dot
	        dotCount++;
	        if(digitCount > 3){
	            printf("Error: not a valid address.\n");
	            return 0;
	        }
	        digitCount = 0;
	        
	        switch(dotCount){
	            case 1:
	                last3Parts = &input[i] + 1;
	                break;
                case 2:
                    last2Parts = &input[i] + 1;
                    break;
                case 3:
                    last1Part = &input[i] + 1;
                    break;
	        }
	        
	    } else { // the current char is a letter or smth else apart from a dot or number
	        printf("Error: not a valid address. else %d\n", input[i]);
	        return 0;
	    }
	    i++;
	}
	// check if there are exactly 3 dots in the address:
	if (dotCount != 3){
	    printf("Error: not a valid address.\n");
        return 0;
	}
	
	// now print the result:
	printf("Last 3 parts: %s\n", last3Parts);
	printf("Last 2 parts: %s\n", last2Parts);
	printf("Last 1 part: %s\n", last1Part);
	
	return 0;
}