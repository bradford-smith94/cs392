/*Bradford Smith (bsmith8)
*delete_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre:
*post: prints an error message to the terminal
*/
void delete_cb(GtkWidget *w, GdkEvent *e, gpointer data)
{
	my_str("ERROR: close window button pressed, use the quit button instead.\n");
}
