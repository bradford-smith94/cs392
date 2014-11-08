/*Bradford Smith (bsmith8)
*term_standend.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: disables highlight
*/
void term_standend()
{
	tputs(gl_env.stand_end, 1, my_termprint);
}
