/*Bradford Smith (bsmith8)
*my_char.c libmy project
*9/3/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a char
*post: prints that char to stdout
*/
void my_char(char c)
{
    write(1, &c, 1);
}
