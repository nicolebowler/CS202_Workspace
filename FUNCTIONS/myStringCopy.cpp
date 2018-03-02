/*This function copies the contents of the source string passed in 
to the destination string passed in*/
char * myStringCopy(char * destination, const char * source)
{
	
	while (*source != '\0'){
			*destination = *source;
			source++;
			destination++;
	}
	destination++;
	*destination = '\0'
	return destination;

}