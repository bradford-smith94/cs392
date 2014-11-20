/*Bradford Smith (bsmith8)
*key_press_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, GdkEventKey *k, and gpointer data
*post: checks if the key pressed was enter
*	if yes then call the send_cb
*/
gboolean key_press_cb(GtkWidget *w, GdkEventKey *k, gpointer data)
{
	if(k->type == GDK_KEY_PRESS)
	{
		if(k->keyval == GDK_Return)
		{
			send_cb(NULL, data);
			return TRUE;
		}
	}
	return FALSE;
}
