/*Bradford Smith (bsmith8)
*init_terminal.c termcaps project
*11/9/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: sets up the terminal and backs up stdio and the terminal settings
*/
void init_terminal()
{
	struct termio line;
	int fd;
	char *name;
	
	ioctl(0, TCGETA, &line);
	gl_env.line_backup = line;
	line.c_lflag &= ~(ICANON | ECHO | ISIG);
	line.c_cc[VMIN] = READMIN;
	line.c_cc[VTIME] = READTIME;
	ioctl(0, TCSETA, &line);

	name = ttyname(0);
	if(!name)
	{
		my_str("ERROR: couldn't get tty name\n");
		exit(-1);
	}
	if((fd = open(name, O_WRONLY)) < 0)
	{
		my_str("ERROR: couldn't open tty name\n");
		exit(-1);
	}
	gl_env.stdio_backup = dup(1);
	dup2(fd, 1);

	init_caps();
	term_vi();
	term_clear();
}
