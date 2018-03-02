char * myStringCat(char * destination, const char * source);


/*This function finds the null character of the desination string\
then copies over character by character of the source string into the 
remaining character indexes*/

char * myStringCat(char * destination, const char * source){

	while (*destination != '\0'){
		destination++;
	}
	while (*source != '\0'){
		*destination = *source;
		destination++;
		source++;
	}
	return destination;
}
