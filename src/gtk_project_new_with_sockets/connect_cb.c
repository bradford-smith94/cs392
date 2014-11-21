/*Bradford Smith (bsmith8)
*connect_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, and gpointer data
*post: produces a pop-up window
*	asks for server information then establishes a connection
*/
void connect_cb(GtkWidget *w, gpointer data)
{	
	static GtkWidget *win;
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w)))
	{
		GtkWidget *tab;
		GtkWidget *b;

		win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(gtk_widget_destroyed), &win);
		/*the gtk_widget_destroyed callback will set win to NULL*/
		gtk_window_set_title(GTK_WINDOW(win), "Connect to a Server");
		tab = gtk_table_new(4, 2, FALSE);

		b = gtk_label_new("Server");
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 0, 1, 0, 1);
		gtk_widget_show(b);

		b = gtk_text_view_new();
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 1, 2, 0, 1);
		gtk_widget_show(b);
		gl_env.server = b;

		b = gtk_label_new("Port");
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 0, 1, 1, 2);
		gtk_widget_show(b);

		b = gtk_text_view_new();
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 1, 2, 1, 2);
		gtk_widget_show(b);
		gl_env.port = b;

		b = gtk_label_new("Username");
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 0, 1, 2, 3);
		gtk_widget_show(b);

		b = gtk_text_view_new();
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 1, 2, 2, 3);
		gtk_widget_show(b);
		gl_env.username = b;

		b = gtk_button_new_with_label("Ok");
		g_signal_connect(G_OBJECT(b), "clicked", G_CALLBACK(connect_confirm_cb), G_OBJECT(win));
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 0, 1, 3, 4);
		gtk_widget_show(b);

		b = gtk_button_new_with_label("Cancel");
		g_signal_connect_swapped(G_OBJECT(b), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(win));
		gtk_table_attach_defaults(GTK_TABLE(tab), b, 1, 2, 3, 4);
		gtk_widget_show(b);

		gtk_container_add(GTK_CONTAINER(win), tab);
		gtk_widget_show(tab);
		gtk_widget_show(win);
	}
	else
	{
		#ifdef DEBUG
			my_str("***DEBUG***Disconnecting via connect button\n");
		#endif
		if(win != NULL)
			gtk_widget_destroy(win);
		cap_sigint();/*disconnect*/
	}
}
