/*Bradford Smith (bsmith8)
*term_get_cap.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in a char *cap
*post: returns a char* of the terminal capability given by cap
*/
char* term_get_cap(char *cap)
{
	static char area[2048];
	char *ret;
	if(!(ret = tgetstr(cap, (char**)&area)))
	{
		if(my_strcmp(cap, "vi") == 0)
			return VICAP;
		if(my_strcmp(cap, "ve") == 0)
			return VECAP;
		my_str("Unable to get termcap: ");
		my_str(cap);
		my_char('\n');
		exit(-1);
	}
	return ret;
}
