/*Bradford Smith (bsmith8)
*myminishell.h myminishell project header file
*10/11/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MYMINISHELL_H_
#define _MYMINISHELL_H_

#include "my.h"

/*This is the header for the myminishell project,
*	it is a basic shell-like program
*	it will handle cd, exit, and bad command warnings on its own
*	it will also be able to run any installed programs (like a normal shell)
*/
int main(int, char**);
void my_err(char*);
void my_chdir(char*);

#endif
