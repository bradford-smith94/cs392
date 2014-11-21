/*Bradford Smith (bsmith8)
*quit_cb.c gtk project
*11/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w and gpointer pWin
*		w is the calling widget, pWin is the main window of the application
*post: produces a pop-up window
*	asks the user if they are sure they want to quit
*		no destroys the pop-up, yes destroy the main window and the pop-up
*/
void quit_cb(GtkWidget *w, gpointer pWin)
{
	static GtkWidget *win;
	if(win == NULL)
	{
		GtkWidget *tab;
		GtkWidget *b;

		win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		g_signal_connect(G_OBJECT(win), "destroy", G_CALLBACK(gtk_widget_destroyed), &win);
		/*the gtk_widget_destroyed callback will set win to NULL*/
		gtk_window_set_title(GTK_WINDOW(win), "Quit?");
		tab = gtk_table_new(2, 2, TRUE);
		gtk_table_set_row_spacings(GTK_TABLE(tab), 5);
		gtk_table_set_col_spacings(GTK_TABLE(tab), 5);

		b = gtk_label_new("Are you sure?");
		gtk_table_attach(GTK_TABLE(tab), b, 0, 2, 0, 1, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		b = gtk_button_new_with_label("Yes");
		g_signal_connect_swapped(G_OBJECT(b), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(pWin));
		g_signal_connect_swapped(G_OBJECT(b), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(win));
		gtk_table_attach(GTK_TABLE(tab), b, 0, 1, 1, 2, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		b = gtk_button_new_with_label("No");
		g_signal_connect_swapped(G_OBJECT(b), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(win));
		gtk_table_attach(GTK_TABLE(tab), b, 1, 2, 1, 2, (GTK_SHRINK | GTK_FILL), (GTK_SHRINK | GTK_FILL), 0, 0);
		gtk_widget_show(b);

		gtk_container_add(GTK_CONTAINER(win), tab);
		gtk_container_set_border_width(GTK_CONTAINER(win), 10);
		gtk_widget_show(tab);
		gtk_widget_show(win);
	}
	else
	{
		gtk_window_present(GTK_WINDOW(win));
	}
}
