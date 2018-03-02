/*This function compares two passed in strings and returns a 0, -1, or -2
based on the result. The characters are compared until they do not match.*/
int myStringCompare(const char * str1, const char * str2)
{

	while (*str1 != *str2){
		str1++;
		str2++;
	}

	if (*str1 > *str2){
		return 2;
	}

	if (*str1 < *str2){
		return -2;
	}

	return 0;
}