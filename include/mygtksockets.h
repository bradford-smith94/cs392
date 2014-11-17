/*Bradford Smith (bsmith8)
*mygtksockets.h gtk project header file, mostly copied from mysockets
*11/15/2014
*"I pedge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MYSIGNALS_H_
#define _MYSIGNALS_H_

#include "my.h"
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>/*for memset and memcpy*/

#ifdef SERVER
	struct s_env
	{
		int serverfd;
		int clientfd;
		char *clientname;
		char childflg;
	}		gl_env;
#else
	#include <netdb.h>
	#include <gtk/gtk.h>/*for gtk stuff, compile with pkg-config*/
	#include <gdk/gdkkeysyms.h>/*for key constants, i.e. GDK_Return*/
	int gl_sockfd;	
#endif

/* This is the header for the gtk project,
* it runs a client and server application where the client can send messages
* to the server using sockets. The client application uses gtk to display a 
* graphical program. This application can support multiple client
* connections.
*/
int main(int, char**);
void my_err(char*);
#ifdef SERVER
	void server_exit();
	void send_reply(char*);
	char* read_msg();
	void print_msg(char*);
	void disconnect();
#else
	void client_exit();
	void send_msg(char*);
	char* read_keyboard();
	void read_reply();
	void cap_sigint();
	void init_main_win();
	void delete_cb(GtkWidget*, GdkEvent*, gpointer);
	void destroy_cb(GtkWidget*, gpointer);
	void key_press_cb(GtkWidget*, GdkEventKey*, gpointer);
	void send_cb(GtkWidget*, gpointer);
	void connect_cb(GtkWidget*, gpointer);
#endif

#endif
