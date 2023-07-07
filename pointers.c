#include <stdio.h>

/*  
* Author: Kristiana Usacka
* Date: July 7, 2023
* Description:
	Scenario
	Check the program in the editor. It copies values from one array to another, adding 1.0. Then it's supposed to print the numbers from the middle point of the new array to both ends, alternately.

	Warning: the midpoint is betwen two cells - one before and one after - start with them.

	We'll use pointers to make a copy, in order to show you this kind of operation (but in this case, you can use array indexing).

	Find all possible compilation errors and logic errors. Fix them. Your version of the program must print the same result as the expected output.

	Before you use the compiler, try to find the errors only by manual code analysis.
*/


int main()
{
	int i;
	float numbers[10] = {3.3, 4.4, 5.2, 2.3, 4.5, 6.8, 9.8, 8.2, 7.5, 9.2};
	float biggerNumbers[10];
	float *source = numbers; // adress of the first element *source == numbers == &numbers[0]
	float *copy = biggerNumbers; // adress of the first element *copy == biggerNumbers == &biggerNumbers[0]
    // this loop just copies values from numbers array to biggerNumbers array
	for (i = 0; i < 10; i++)
	{
		*copy = *source;
		copy++;
		source++;
	}
	/*  okay, so at the last iteration copy == &biggerNumbers[10] !!! this is OUT of the array so weird things can happen
	    and source = &numbers[10] !!! this is OUT of the array so weird things can happen 
    */
    
	float *biggerEnd = copy - 1; // so if copy == &biggerNumbers[10], then -1 should make it to &biggerNumbers[9]
	float *biggerStart = biggerNumbers; // this makes biggerStart == &biggerNumbers[0]
	float *middle1 = biggerNumbers+4; // now middle1 = &biggerNumbers[4] = 4.5 this is the fifth element in the array
	float *middle2 = middle1+1; // and middle2 = &biggerNumbers[6] = 6.8
	for ( ; middle1>=biggerStart ; middle1--, middle2++)
	{
		printf("%.1f\n", *middle1);
		printf("%.1f\n", *middle2);
	}
	return 0;
}