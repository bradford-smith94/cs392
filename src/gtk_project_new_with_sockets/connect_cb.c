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
	GtkWidget *tab;
	GtkWidget *b;

	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w)))
	{
		win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		g_signal_connect(G_OBJECT(win), "delete-event", G_CALLBACK(connect_cancel_cb), NULL);
		g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(connect_cancel_cb), NULL);
		g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(gtk_widget_destroyed), &win);
		/*the gtk_widget_destroyed callback will set win to NULL*/
		gtk_window_set_title(GTK_WINDOW(win), "Connect to a Server");
		tab = gtk_table_new(4, 2, FALSE);
		gtk_table_set_row_spacings(GTK_TABLE(tab), 5);
		gtk_table_set_col_spacings(GTK_TABLE(tab), 5);

		b = gtk_label_new("Server");
		gtk_table_attach(GTK_TABLE(tab), b, 0, 1, 0, 1, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		b = gtk_text_view_new();
		gtk_table_attach(GTK_TABLE(tab), b, 1, 2, 0, 1, (GTK_FILL | GTK_EXPAND | GTK_SHRINK), GTK_SHRINK, 0, 0);
		gtk_widget_show(b);
		gl_env.server = b;

		b = gtk_label_new("Port");
		gtk_table_attach(GTK_TABLE(tab), b, 0, 1, 1, 2, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		b = gtk_text_view_new();
		gtk_table_attach(GTK_TABLE(tab), b, 1, 2, 1, 2, (GTK_FILL | GTK_EXPAND | GTK_SHRINK), GTK_SHRINK, 0, 0);
		gtk_widget_show(b);
		gl_env.port = b;

		b = gtk_label_new("Username");
		gtk_table_attach(GTK_TABLE(tab), b, 0, 1, 2, 3, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		b = gtk_text_view_new();
		gtk_table_attach(GTK_TABLE(tab), b, 1, 2, 2, 3, (GTK_FILL | GTK_EXPAND | GTK_SHRINK), GTK_SHRINK, 0, 0);
		gtk_widget_show(b);
		gl_env.username = b;

		b = gtk_button_new_with_label("Ok");
		g_signal_connect(G_OBJECT(b), "clicked", G_CALLBACK(connect_confirm_cb), G_OBJECT(win));
		gtk_table_attach(GTK_TABLE(tab), b, 0, 1, 3, 4, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		b = gtk_button_new_with_label("Cancel");
		g_signal_connect_swapped(G_OBJECT(b), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(win));
		gtk_table_attach(GTK_TABLE(tab), b, 1, 2, 3, 4, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		gtk_container_add(GTK_CONTAINER(win), tab);
		gtk_container_set_border_width(GTK_CONTAINER(win), 10);
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
