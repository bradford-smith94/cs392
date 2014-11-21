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
	GtkWidget *b;

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "mysockets client");
	g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(delete_cb), NULL);
	g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(destroy_cb), NULL);
	tab = gtk_table_new(2, 4, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(tab), 5);
	gtk_table_set_col_spacings(GTK_TABLE(tab), 5);

	t = gtk_label_new("Message:");
	gtk_table_attach(GTK_TABLE(tab), t, 0, 1, 0, 1, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
	gtk_widget_show(t);

	t = gtk_text_view_new();
	g_signal_connect(G_OBJECT(t), "key_press_event", G_CALLBACK(key_press_cb), t);
	gtk_table_attach(GTK_TABLE(tab), t, 1, 3, 0, 1, (GTK_FILL | GTK_EXPAND | GTK_SHRINK), GTK_SHRINK, 0, 0);
	gtk_widget_show(t);

	b = gtk_button_new_with_label("Send");
	g_signal_connect(G_OBJECT(b), "clicked", G_CALLBACK(send_cb), t);
	gtk_table_attach(GTK_TABLE(tab), b, 3, 4, 0, 1, GTK_SHRINK, (GTK_SHRINK | GTK_FILL), 0, 0);
	gtk_widget_show(b);

	b = gtk_toggle_button_new_with_label("Connect");
	g_signal_connect(G_OBJECT(b), "clicked", G_CALLBACK(connect_cb), NULL);
	gtk_table_attach(GTK_TABLE(tab), b, 0, 2, 1, 2, GTK_SHRINK, (GTK_SHRINK | GTK_FILL), 0, 0);
	gtk_widget_show(b);
	gl_env.connect_button = b;

	b = gtk_button_new_with_label("Quit");
	g_signal_connect(G_OBJECT(b), "clicked", G_CALLBACK(quit_cb), G_OBJECT(win));
	gtk_table_attach(GTK_TABLE(tab), b, 2, 4, 1, 2, GTK_SHRINK, (GTK_SHRINK | GTK_FILL), 0, 0);
	gtk_widget_show(b);

	gtk_container_add(GTK_CONTAINER(win), tab);
	gtk_container_set_border_width(GTK_CONTAINER(win), 10);
	gtk_widget_show(tab);
	gtk_widget_show(win);
}
