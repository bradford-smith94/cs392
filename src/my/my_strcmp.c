/*Bradford Smith (bsmith8)
*my_strcmp.c libmy project part 2
*9/12/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in two strings
*post: returns a number < 0 if the first string is alphabetically before the second
* > 0 if the second string is alphabetically before the first
*and 0 if the strings are alphabetically equivalent
*/
int my_strcmp(char *s1, char *s2)
{
	int n = 0;
	unsigned int i;
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);
	if(s1 != NULL && s2 != NULL){
		for(i = 0; i < len1 && i < len2 && n == 0; i++)
			n = s1[i] - s2[i];
		if(n == 0 && i < len1)/*s2 is shorter*/
			n = 1;
		else if(n == 0 && i < len2)/*s1 is shorter*/
			n = -1;
	}else if(s1 == NULL && s2 != NULL){
		n = -1;
	}else if(s1 != NULL && s2 == NULL){
		n = 1;
	}
	return n;
}
