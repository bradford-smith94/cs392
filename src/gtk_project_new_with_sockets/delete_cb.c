/*Bradford Smith (bsmith8)
*delete_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, GdkEvent *e, and gpointer data
*post: prints an error message to the terminal and ignores the delete
*/
gboolean delete_cb(GtkWidget *w, GdkEvent *e, gpointer data)
{
	my_str("ERROR: close window button pressed, use the quit button instead.\n");
	return TRUE;
}
