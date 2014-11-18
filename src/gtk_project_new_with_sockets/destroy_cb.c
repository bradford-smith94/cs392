/*Bradford Smith (bsmith8)
*destroy_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, and gpointer data
*post: exits the application and allows the window to be destroyed
*/
gboolean destroy_cb(GtkWidget *w, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}
