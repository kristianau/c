#include <stdio.h>
#include <ctype.h>

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