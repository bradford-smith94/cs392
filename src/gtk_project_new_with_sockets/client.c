/*Bradford Smith (bsmith8)
*client.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in an int argc and a char **argv
*post: runs the client application with argc number of command line arguments
*	given by argv
*/
int main(int argc, char **argv)
{
	GtkWidget *win;
	GtkWidget *tab;
	GtkWidget *t;

	gtk_init(&argc, &argv);
	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "mysockets client");
	tab = gtk_table_new(3, 4, TRUE);

	t = gtk_label_new("Msg:");
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 0, 1, 0, 1);
	gtk_widget_show(t);

	t = gtk_text_view_new();
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 0, 3, 1, 2);
	gtk_widget_show(t);

	t = gtk_button_new_with_label("Send");
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 3, 4, 1, 2);
	gtk_widget_show(t);

	t = gtk_button_new_with_label("Connect");
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 0, 2, 2, 3);
	gtk_widget_show(t);

	t = gtk_button_new_with_label("Quit");
	gtk_table_attach_defaults(GTK_TABLE(tab), t, 2, 4, 2, 3);
	gtk_widget_show(t);

	gtk_container_add(GTK_CONTAINER(win), tab);
	gtk_widget_show(tab);
	gtk_widget_show(win);

	gtk_main();
	return 0;
}
