/*Bradford Smith (bsmith8)
*my_str.c libmy project
*9/5/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: s is a pointer to a string
*post: prints the string s on the screen
*/
void my_str(char* s)
{
    if(s != NULL)
        for(s; *s != '\0'; s++)
            my_char(*s);
}
