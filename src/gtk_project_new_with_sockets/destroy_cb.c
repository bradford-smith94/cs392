/*Bradford Smith (bsmith8)
*destroy_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: produces a pop-up window
*	asks the user if they are sure they want to quit
*/
void destroy_cb(GtkWidget *w, gpointer data)
{
	gtk_main_quit();
}
