/*Bradford Smith (bsmith8)
*get_char.c termcaps project
*11/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in a char* s
*post: compares s to keypresses that the program is looking for
*	returns 1 (true) if the keypress is handled, and 0 (false) if not
*/
char check_char(char* s)
{
	#ifdef DEBUG
		my_str("checking\n");
	#endif
	if(my_strcmp(s, KU) == 0)
		moveup();
	else if(my_strcmp(s, KD) == 0)
		movedown();
	else if(my_strcmp(s, KL) == 0)
		moveleft();
	else if(my_strcmp(s, KR) == 0)
		moveright();
	else if(my_strcmp(s, " ") == 0) /*spacebar*/
		doselect();
	else if(s[0] == '\033' && s[1] == '\0') /*esc*/
		getout(0);
	else if(s[0] == '\n' && s[1] == '\0') /*enter*/
		getout(1);
	else
		return 0;
	return 1;
}
