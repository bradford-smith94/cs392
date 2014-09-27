/*Bradford Smith (bsmith8)
*my_digits.c libmy project
*9/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: none
*post: prints the base 10 digits from 0-9
*/
void my_digits()
{
    char c = '0';
    for(c; c <= '9'; c++)
        my_char(c);
}
