/*Bradford Smith (bsmith8)
*refreshin.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: refresh the current item and stay in place
*/
void refreshin()
{
	term_move_to_item(gl_env.pos);
	term_underline();
	if(gl_env.elements[gl_env.pos].mode)
		term_standout();
	my_str(gl_env.elements[gl_env.pos]);
	term_standend();
	term_underend();
}
