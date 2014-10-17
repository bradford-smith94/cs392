/*Bradford Smith (bsmith8)
*my_atoi.c mysignals project
*10/16/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a char *s
*post: returns the integer represented in s or 0 if there is no integer in s
*/
int my_atoi(char *s)
{
	int r;/*return value*/
	char n;/*negative flag*/

	r = 0;
	n = 0;
	if(s != NULL)
	{
		for( ; *s == ' ' || *s == '\t'; s++)
			;/*skipping over leading whitespaces*/
		for( ; *s == '+' || *s == '-'; s++)
			(*s == '-') ? n ^= 1 : n;/*n is set to 1 for odd numbers of -'s*/
		for( ; *s >= '0' && *s <= '9'; s++)
		{
			r *= 10;
			r += *s - '0';
		}/*read number*/
		if(n)
			r *= -1;
	}
	return r;
}
