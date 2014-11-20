/*Bradford Smith (bsmith8)
*connect_confirm_cb.c gtk project
*11/20/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a GtkWidget *w, and gpointer data
*post: establishes a connection to the server given by the text
*	in the text views saved in the gl_env struct
*/
void connect_confirm_cb(GtkWidget *w, gpointer data)
{
	struct sockaddr_in serv_addr;
	struct hostent *server;
	int port;

	port = my_atoi(get_text_from_textview(gl_env.port));
	if(port < 0)
		my_str("ERROR: invalid port number\n");
	if((gl_env.sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		my_str("ERROR: cannot create socket\n");
	if(!(server = gethostbyname(get_text_from_textview(gl_env.server))))
		my_str("ERROR: cannot resolve hostname\n");
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	memcpy(&serv_addr.sin_addr.s_addr, (server->h_addr), server->h_length);

	if(connect(gl_env.sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		my_str("ERROR: cannot connect to socket\n");

	send_msg(get_text_from_textview(gl_env.username));
	read_reply();

	gtk_widget_destroy(data);
}
