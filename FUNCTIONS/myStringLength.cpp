/*This function finds the length of the passed in string by incrementing
a variable call 'size' until a null character is found*/
int myStringLength(const char * str)
{
	int size = 0;
	while (*str != '\0'){
		str++;
		size++;

	return size;
}