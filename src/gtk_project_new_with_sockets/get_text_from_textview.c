/*Bradford Smith (bsmith8)
*get_text_from_textview.c gtk project
*11/19/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *t which is a textview widget
*post: returns a gchar* pointing to the text in t
*/
gchar* get_text_from_textview(GtkWidget *t)
{
	GtkTextIter start;
	GtkTextIter end;
	GtkTextBuffer *buf;
	gchar *text;
	
	buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(t));
	gtk_text_buffer_get_bounds(buf, &start, &end);
	text = gtk_text_buffer_get_text(buf, &start, &end, FALSE);
	#ifdef DEBUG
		my_str("Getting text from textview: '");
		my_str(text);
		my_str("'\n");
	#endif
	return text;
}
