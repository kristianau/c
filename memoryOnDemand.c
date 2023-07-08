#include <stdio.h>
#include <stdlib.h>

/*
* Author: Kristiana Usacka
* Date: July 8, 2023
* Description:
	Scenario
	Write a program that allocates memory of a size requested by the user.

	This program requests a number from the user and checks if that number is less than 1 MB (1024*1024). If it's not, then the program prints the message: Too much memory requested..

	In the next step, the program allocates a one-dimesional array of characters (char) and fills this array with characters from "A" to "Z" - the first element (index 0) contains "A", the 26th element (index 25) contains "Z", the 27th element (index 26) contains "A" and so on.

	Then, the program prints the first 400 bytes of an array (or the whole array if it's smaller than 400 characters), 40 characters in each row.

	To simplify the program, you can use the break or continue statements. Remember to free up the array memory at the end of the program.

	Your version of the program must print the same result as the expected output.

	Sample input
	100

	Expected output
	ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN
	OPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZAB
	CDEFGHIJKLMNOPQRSTUV

	Sample input
	500

	Expected output
	ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN
	OPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZAB
	CDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOP
	QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCD
	EFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR
	STUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEF
	GHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRST
	UVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGH
	IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUV
	WXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJ

	Sample input
	1200500

	Expected output
	Too much memory requested.
*/

int main()
{
	/* your code */
	char *chars;
	int userChoice;
	
	printf("Enter size: ");
	scanf("%d", &userChoice);
	
	if(userChoice <=0 || userChoice > 1024*1024){
	    printf("Too much memory requested.");
	    return 1;
	}
	
	chars = (char *) malloc(userChoice * sizeof(char));
	
	int charCode = 65;
	
	// assign those chars:
	for(int i = 0; i < userChoice; i++){
	    if(charCode == 91)
	        charCode = 65;
	    chars[i] = charCode++;
	}
	
	// print:
	int printing = userChoice < 401 ? userChoice : 400;
	for(int i = 0; i < printing; i++){
	    if (i % 40 == 0 && i != 0)
	        printf("\n");
	    printf("%c", chars[i]);
	}
	
	
	free(chars);
	
	return 0;
}