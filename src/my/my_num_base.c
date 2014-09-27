/*Bradford Smith (bsmith8)
*my_num_base.c libmy project
*9/6/2014 corrected 9/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a int and a string of characters for the base
*post: prints out the int represented in the given base characters
*/
void my_num_base(int i, char* base)
{
	unsigned int u;
	int radix;
	unsigned int exp;

	if((radix = my_strlen(base)) > 0)
	{
		if(i < 0)
			my_char('-');
		u = (i < 0)? -i : i;
		if(radix == 1)
			while(u-- > 0)
				my_char(*base);
		else
		{
			for(exp = 1; u / exp >= radix; exp *= radix)
				;
			for( ; exp; u %= exp, exp /= radix)
				my_char(base[u / exp]);
		}
	}
	else
		my_str("Base not valid\n");
}
