/*Bradford Smith (bsmith8)
*init_main_win.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: initializes and shows the main window of the application
*/
void init_main_win()
{
	GtkWidget *win;
	GtkWidget *tab;
	GtkWidget *t;

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "mysockets client");
	g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(delete_cb), NULL);
	g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(destroy_cb), NULL);
	tab = gtk_table_new(3, 4, TRUE);

	t = gtk_label_new("Msg:");
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 0, 1, 0, 1);
	gtk_widget_show(t);

	t = gtk_text_view_new();
	g_signal_connect(G_OBJECT(t), "key_press_event", G_CALLBACK(key_press_cb), NULL);
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 0, 3, 1, 2);
	gtk_widget_show(t);

	t = gtk_button_new_with_label("Send");
	g_signal_connect(G_OBJECT(t), "clicked", G_CALLBACK(send_cb), NULL);
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 3, 4, 1, 2);
	gtk_widget_show(t);

	t = gtk_toggle_button_new_with_label("Connect");
	g_signal_connect(G_OBJECT(t), "clicked", G_CALLBACK(connect_cb), NULL);
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 0, 2, 2, 3);
	gtk_widget_show(t);

	t = gtk_button_new_with_label("Quit");
	g_signal_connect(G_OBJECT(t), "clicked", G_CALLBACK(quit_cb), G_OBJECT(win));
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 2, 4, 2, 3);
	gtk_widget_show(t);

	gtk_container_add(GTK_CONTAINER(win), tab);
	gtk_widget_show(tab);
	gtk_widget_show(win);
}
