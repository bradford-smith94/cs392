/*Bradford Smith (bsmith8)
*term_underend.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: disables underline
*/
void term_underend()
{
	tputs(gl_env.under_end, 1, my_termprint);
}
