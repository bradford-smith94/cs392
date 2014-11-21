/*Bradford Smith (bsmith8)
*client_exit.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: disconnects the client from the server
*/
void client_exit()
{
	#ifdef DEBUG
		my_str("***DEBUG***Calling client_exit()\n");
	#endif
	if(gl_env.sockfd)
	{
		my_str("\n***Disconnecting the client program...\n");
		close(gl_env.sockfd);
		gl_env.sockfd = 0;
		if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(gl_env.connect_button)))
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(gl_env.connect_button), FALSE);
	}
}
