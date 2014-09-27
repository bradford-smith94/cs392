/*Bradford Smith (bsmith8)
*my_strrfind.c libmy project part 2
*9/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a string and a character
*post: returns a pointer to the last occurence of the given char in the given string
*/
char* my_strrfind(char *s, char c)
{
    char *returnIndex = NULL;
    if(s != NULL){
        for(s; *s != '\0'; s++)
            if(*s == c)
                returnIndex = s;
    }
    return returnIndex;
}
