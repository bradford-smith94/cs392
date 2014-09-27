/*Bradford Smith (bsmith8)
*my_int.c libmy project
*9/6/2014 corrected on 9/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in an int
*post: prints that int to stdout
*/
void my_int(int i)
{
	unsigned int u;
	unsigned int exp;

	if(i < 0)
		my_char('-');
	u = (i < 0)? -i : i;
	for(exp = 1; u / exp >= 10; exp *= 10)
		;
	for(; exp; u %= exp, exp /= 10)
		my_char('0' + u / exp);
}
