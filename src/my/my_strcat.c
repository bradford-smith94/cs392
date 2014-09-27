/*Bradford Smith (bsmith8)
*my_strcat.c libmy project part 2
*9/14/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in two strings
*post: adds the second string to the end of the first string and returns a pointer to it
*/
char* my_strcat(char *s1, char *s2)
{
	char *result;
	unsigned int i;
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);
	if(s1 != NULL && s2 != NULL){
		if(*s1 == '\0')
			result = s1;
		else{
			for(i = 0; i <= len2; i++)
				s1[len1 + i] = s2[i];
			result = s1;
		}
	}else if(s1 == NULL && s2 != NULL){
		result = NULL;
	}else if(s1 != NULL && s2 == NULL){
		result = s1;
	}else/*both NULL*/
		result = NULL;
	return result;
}
