/*scratch file for testing in lab2 of CS202 - 1101 */

/*
void (int a, int b, int * c) 
{
	int temp = 0;
	temp = a + b; 
}
*/

int * printfNonNegatives(int * array)
{
	int *ptr;
	prt = array; 
	while (*ptr >= 0){
		cout << *ptr++;
	}
	return ptr;
}