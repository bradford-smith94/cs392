/*Bradford Smith (bsmith8)
*refreshout.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in an int pos
*post: refreshes the item at pos
*/
void refreshout(int pos)
{
	term_move_to_item(pos);
	if(gl_env.elements[pos].mode)
		term_standout();
	my_str(gl_env.elements[pos].elem);
	term_standend();
}
