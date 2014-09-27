/*Bradford Smith (bsmith8)
*my_alpha.c libmy project
*9/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: none
*post: prints the alphabet from A-Z
*/
void my_alpha()
{
    char c = 'A';
    for(c; c <= 'Z'; c++)
        my_char(c);
}
