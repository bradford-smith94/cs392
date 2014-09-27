/*Bradford Smith (bsmith8)
*testmy2.c libmy project part 2 test main
*9/11/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

int main(int argc, char* argv[])
{
	char *s1;
	char *s2;
	char *s3;

	/*my_strdup: allocates a new string that is a copy of the given string*/
	s1 = my_strdup("hello\n");
	my_str(s1);/*prints hello*/
	if(!my_strdup(NULL))
		my_str("my_strdup: NULL ok\n");
	else
		my_str("my_strdup: NULL FAIL!\n");
	s2 = my_strdup("");
	if(*s2 == '\0')
		my_str("my_strdup: \"\" ok\n");
	else
		my_str("my_strdup: \"\" FAIL!\n");
	free(s1);
	free(s2);
	my_str("----------\n");

	/*my_strcmp: compares strings and returns an int*/
	my_int(my_strcmp(NULL, NULL));/*prints 0*/
	my_char('\n');
	my_int(my_strcmp(NULL, ""));/*prints -1*/
	my_char('\n');
	my_int(my_strcmp("", NULL));/*prints 1*/
	my_char('\n');
	my_int(my_strcmp("abc", "abc"));/*prints 0*/
	my_char('\n');
	my_int(my_strcmp("abc", "cba"));/*prints a number < 0*/
	my_char('\n');
	my_int(my_strcmp("cba", "abc"));/*prints a number > 0*/
	my_char('\n');
	my_int(my_strcmp("abc", "ab"));/*prints 1*/
	my_char('\n');
	my_str("----------\n");

	/*my_strncmp: compares strings up to the given number of characters*/
	my_int(my_strncmp(NULL, NULL, 0));/*prints 0*/
	my_char('\n');
	my_int(my_strncmp(NULL, "", 2));/*prints -1*/
	my_char('\n');
	my_int(my_strncmp("", NULL, 2));/*prints 1*/
	my_char('\n');
	my_int(my_strncmp("abc", "abc", 4));/*prints 0*/
	my_char('\n');
	my_int(my_strncmp("abc", "cba", 3));/*prints a number < 0*/
	my_char('\n');
	my_int(my_strncmp("cba", "abc", 0));/*prints 0*/
	my_char('\n');
	my_int(my_strncmp("abc", "ab", 2));/*prints 0*/
	my_char('\n');
	my_str("----------\n");

	/*my_strcpy: copies src string to dest string and return dest*/
	s1 = my_strdup("###############\n");
	if(my_strcpy(s1, "yay!\n") == s1)
		my_str(s1);/*prints yay!*/
	else
		my_str("my_strcpy: FAIL!\n");
	if(!my_strcpy(NULL, "test"))
		my_str("my_strcpy: copy into NULL ok\n");
	else
		my_str("my_strcpy: copy into NULL FAIL!\n");
	if(my_strcpy(s1, NULL) == s1)
		my_str(s1);/*prints yay!*/
	else
		my_str("my_strcpy: copy NULL FAIL!\n");
	my_str("----------\n");

	/*my_strncpy: copies up to the given number of characters*/
	if(my_strncpy(s1, "boondocks", 3) == s1)
		my_str(s1);/*prints boo!*/
	else
		my_str("my_strncpy: FAIL!\n");
	if(!my_strncpy(NULL, "testing", 4))
		my_str("my_strncpy: copy into NULL ok\n");
	else
		my_str("my_strncpy: copy into NULL FAIL!\n");
	if(my_strncpy(s1, NULL, 1) == s1)
		my_str(s1);/*prints boo!*/
	else
		my_str("my_strncpy: copy NULL FAIL!\n");
	if(my_strncpy(s1, "boot\n", 6) == s1)
		my_str(s1);/*prints boot*/
	else
		my_str("my_strncpy: FAIL!\n");
	if(my_strncpy(s1, "sevens", 6) == s1)
		my_str(s1);/*prints sevens#########*/
	else
		my_str("my_strncpy: FAIL!\n");
	free(s1);
	my_str("----------\n");

	/*my_strconcat: creates a new string that is a concatenation of the two provided strings*/
	s1 = my_strconcat("concat", " worked!\n");
	my_str(s1);/*prints concat worked!*/
	s2 = my_strconcat(NULL, s1);
	if(s2 == s1)
		my_str("my_strconcat: FAIL!");
	else
		my_str(s2);/*prints concat worked!*/
	free(s2);
	s2 = my_strconcat(s1, NULL);
	if(s2 == s1)
		my_str("my_strconcat: FAIL!");
	else
		my_str(s2);/*prints concat worked!*/
	free(s2);
	if(!my_strconcat(NULL, NULL))
		my_str("my_strconcat: NULL ok\n");
	else
		my_str("my_strconcat: NULL FAIL!\n");
	s2 = my_strconcat("", "");
	if(*s2 == 0)
		my_str("my_strconcat: \"\" ok\n");
	else
		my_str("my_strconcat: \"\" FAIL!\n");
	free(s1);
	free(s2);
	my_str("----------\n");

	/*my_strnconcat: creates a new string and concatenates up to the given number of characters 
from the second strng*/
	s1 = my_strdup("hello");
	s2 = my_strdup(" tomato");
	s3 = my_strnconcat(s1, s2, 4);
	my_str(s3);/*prints hello tom*/
	my_char('\n');
	free(s3);
	s3 = my_strnconcat(s1, s2, 100);
	my_str(s3);/*prints hello tomato*/
	my_char('\n');
	free(s3);
	s3 = my_strnconcat(NULL, s2, 3);
	if(s3 != s2)
		my_str(s3);/*prints to*/
	else
		my_str("my_strnconcat: FAIL!");
	my_char('\n');
	free(s3);
	s3 = my_strnconcat(s1, NULL, 1);
	if(s3 != s1)
		my_str(s3);/*prints hello*/
	else
		my_str("my_strnconcat: FAIL!");
	my_char('\n');
	if(!my_strnconcat(NULL, NULL, 2))
		my_str("my_strnconcat: NULL ok\n");
	else
		my_str("my_strnconcat: NULL FAIL!\n");
	free(s3);
	s3 = my_strnconcat("", "", 1);
	if(*s3 == '\0')
		my_str("my_strnconcat: \"\" ok\n");
	else
		my_str("my_strnconcat: \"\" FAIL!\n");
	free(s3);
	s3 = my_strnconcat(s1, s2, 0);
	my_str(s3);/*prints hello*/
	my_char('\n');
	free(s1);
	free(s2);
	free(s3);
	my_str("----------\n");

	/*my_strcat: concatentates the second string on the end of the first string*/
	s1 = my_strdup("###############\n");
	my_strcpy(s1, "cat");
	if(my_strcat(s1, " worked\n") == s1)
		my_str(s1);/*prints cat worked*/
	else
		my_str("my_strcat: FAIL!\n");
	if(!my_strcat(NULL, NULL))
		my_str("my_strcat: NULL ok\n");
	else
		my_str("my_strcat: NULL FAIL!\n");
	if(!my_strcat(NULL, s1))
		my_str("my_strcat: NULL ok\n");
	else
		my_str("my_strcat: NULL FAIL!\n");
	if(my_strcat(s1, NULL) == s1)
		my_str(s1);/*prints cat worked*/
	else
		my_str("my_strcat: NULL FAIL!\n");
	s2 = my_strcat("", "");
	if(*s2 == '\0')
		my_str("my_strcat: \"\" ok\n");
	else
		my_str("my_strcat: \"\" FAIL!\n");
	free(s1);
	s2 = NULL;
	my_str("----------\n");

	/*my_strfind: returns a pointer to the first occurence of the given character in the given string*/
	s1 = my_strdup("racecar\n");
	my_str(my_strfind(s1, 'a'));/*prints acecar*/
	if(!my_strfind(s1, 'f'))
		my_str("my_strfind: not present ok\n");
	else
		my_str("my_strfind: not present FAIL!\n");
	if(!my_strfind(NULL, 'a'))
		my_str("my_strfind: NULL ok\n");
	else
		my_str("my_strfind: NULL FAIL!\n");
	my_str("----------\n");

	/*my_strrfind: return a pointer to the last occurence of the given character in the given string*/
	my_str(my_strrfind(s1, 'a'));/*prints ar*/
	if(!my_strrfind(s1, 'i'))
		my_str("my_strrfind: not present ok\n");
	else
		my_str("my_strrfind: not present FAIL!\n");
	if(!my_strrfind(NULL, 'b'))
		my_str("my_strrfind: NULL ok\n");
	else
		my_str("my_strrfind: NULL FAIL!\n");
	free(s1);
	my_str("----------\n");

	return 0;
}
