/*Bradford Smith (bsmith8)
*term_underline.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: enables underline
*/
void term_underline()
{
	tputs(gl_env.underline, 1, m_termprint);
}
