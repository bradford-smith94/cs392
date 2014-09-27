/*Bradford Smith (bsmith8)
*my.h libmy project header file
*9/3/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MY_H_
#define _MY_H_
#ifndef NULL
#define NULL ((void*)0)
#endif

#include <unistd.h> /*for use in my_char(char)*/
#include <stdlib.h> /*for use in xmalloc(unsigned int)*/

/* This is the header for the libmy project,
*it is a class full of methods for printing things on the screen
*/

void my_char(char);
void my_str(char*); 
void my_int(int);
void my_num_base(int, char*);
void my_alpha();
void my_digits();
int my_strlen(char*);
int my_revstr(char*);
int my_strpos(char*, char);
int my_strrpos(char*, char);

/*part 2 methods*/
char* my_strdup(char*);
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, unsigned int);
char* my_strcpy(char*, char*);
char* my_strncpy(char*, char*, unsigned int);
char* my_strconcat(char*, char*);
char* my_strcat(char*, char*);
char* my_strnconcat(char*, char*, unsigned int);
char* my_strfind(char*, char);
char* my_strrfind(char*, char);
void* xmalloc(unsigned int);

#endif
