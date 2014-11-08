/*Bradford Smith (bsmith8)
*init_caps.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: initializes all the termcaps in the global struct
*/
void init_caps()
{
	gl_env.left = term_get_cap(LEFT);
	gl_env.right = term_get_cap(RIGHT);
	gl_env.up = term_get_cap(UP);
	gl_env.down = term_get_cap(DOWN);
	gl_env.esc = ESC;
	gl_env.underline = term_get_cap(UNDERLINE);
	gl_env.under_end = term_get_cap(UNDER_END);
	gl_env.standout = term_get_cap(STANDOUT);
	gl_env.stand_end = term_get_cap(STAND_END);
	gl_env.move = term_get_cap(MOVE);
	gl_env.clear = term_get_cap(CLEAR);
	gl_env.cursoroff = VICAP;
	gl_env.cursoron = VECAP;
}
