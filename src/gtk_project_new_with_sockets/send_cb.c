/*Bradford Smith (bsmith8)
*send_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, and gpointer data
*		data points to a GtkWidget that is a textview
*post: gets the text from the text view and sends it to the server
*/
void send_cb(GtkWidget *w, gpointer data)
{
	#ifdef DEBUG
		my_str("Send called: ");
		my_str(get_text_from_textview(GTK_WIDGET(data)));
		my_str("<\n");
	#endif
	send_msg(get_text_from_textview(GTK_WIDGET(data)));
}
