/*Bradford Smith (bsmith8)
*connect_cancel_cb.c gtk project
*11/20/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, and gpointer data
*post: toggles out the connect button in the main window
*	and allows the window to still get destroyed
*/
void connect_cancel_cb(GtkWidget *w, gpointer data)
{
	if(!gl_env.sockfd)
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.connect_button), FALSE);
}
