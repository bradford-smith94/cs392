/*Bradford Smith (bsmith8)
*term_clear.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: clears the terminal
*/
void term_clear()
{
	tputs(gl_env.clear, 1, my_termprint);
}
