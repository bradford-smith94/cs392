/*Bradford Smith (bsmith8)
*my_strncpy.c libmy project part 2
*9/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in two strings and a number
*post: copies up to the given number of character of the second string into the
first string and returns a pointer to it
*/
char* my_strncpy(char *dest, char *src, unsigned int n)
{
    /*assuming the user isn't stupid and dest can fit src*/
    unsigned int i;
    int lenSrc = my_strlen(src);
    if(dest != NULL)
        for(i = 0; lenSrc != -1 && i <= lenSrc && i < n; i++)
            dest[i] = src[i];
    return dest;
}
