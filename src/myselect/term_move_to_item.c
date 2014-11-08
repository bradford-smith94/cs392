/*Bradford Smith (bsmith8)
*term_move_to_item.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in an int pos
*post: moves the selection to the element at index pos
*/
void term_move_to_item(int pos)
{
	int x;
	int y;

	x = gl_env.elements[pos].x;
	y = gl_env.elements[pos].y;
	tputs(tgoto(gl_env.cursor, x, y), 1, my_termprint);
}
