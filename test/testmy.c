/*Bradford Smith (bsmith8)
*testmy.c libmy project test main
*9/4/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

int main(int argc, char* argv[])
{
    char s[] = "world\n";
    char hi[] = "hello";
    char em[] = "";

    /*my_char: prints characters on the screen*/
    my_char('a');/*print a*/
    my_char('\0');/*do nothing*/
    my_char('\n');/*print a newline*/
	my_str("------------\n");

    /*my_str: prints strings on the screen*/
    my_str("hello\n");/*prints hello*/
    my_str("-->");
    my_str("");
    my_str("<--\n");/*prints --><--*/
    my_str(NULL);/*do nothing*/
    my_str(s);/*prints world*/
	my_str("------------\n");

    /*my_int: prints base 10 integers on the screen*/
    my_int(42);/*prints 42*/
    my_char('\n');
    my_int(0);/*prints 0*/
    my_char('\n');
	my_int(100);/*prints 100*/
	my_char('\n');
	my_int(10100);/*prints 10100*/
	my_char('\n');
    my_int(-3);/*prints -3*/
    my_char('\n');
    my_int(1 << (8 * sizeof(int) - 1));/*prints int min*/
    my_char('\n');
	my_str("------------\n");

    /*my_num_base: prints integers in the base provided*/
    my_num_base(42, "01");/*prints 101010*/
	my_char('\n');
    my_num_base(190, "zyx");/*print xyzzy ... and then nothing happens*/
	my_char('\n');
    my_num_base(-3, "$");/*prints -$$$*/
	my_char('\n');
    my_num_base(5, NULL);/*prints "Base not valid"*/
	my_char('\n');
    my_num_base(13, "");/*prints "Base not valid"*/
	my_char('\n');
	my_str("------------\n");

    /*my_alpha: prints the alphabet*/
    my_alpha();/*prints abcdefghijklmnopqrstuvwxyz*/
	my_char('\n');
	my_str("------------\n");

    /*my_digits: prints the base 10 digits*/
    my_digits();/*prints 0123456789*/
	my_char('\n');
	my_str("------------\n");

    /*my_strlen: prints the length of the provided string*/
    my_int(my_strlen("two"));/*prints 3*/
	my_char('\n');
    my_int(my_strlen(NULL));/*prints -1*/
	my_char('\n');
    my_int(my_strlen(""));/*prints 0*/
	my_char('\n');
	my_str("------------\n");

    /*my_revstr: reverses the given string and returns the length*/
	my_str(hi);/*prints hello*/
	my_char('\n');
    my_int(my_revstr(hi));/*prints 5*/
	my_char('\n');
	my_str(hi);/*prints olleh*/
	my_char('\n');
    my_int(my_revstr(NULL));/*prints -1*/
	my_char('\n');
    my_int(my_revstr(em));/*prints 0*/
	my_char('\n');
	my_str("------------\n");

    /*my_strpos: prints the first index of the given char in the given string*/
    my_int(my_strpos("racecar", 'r'));/*prints 0*/
	my_char('\n');
    my_int(my_strpos(NULL, '0'));/*prints -1*/
	my_char('\n');
    my_int(my_strpos("team", 'i'));/*prints -1*/
	my_char('\n');
	my_str("------------\n");

    /*my_strrpos: prints te last index of the given char in the given string*/
    my_int(my_strrpos("racecar", 'r'));/*prints 6*/
	my_char('\n');
    my_int(my_strrpos(NULL, '7'));/*prints -1*/
	my_char('\n');
    my_int(my_strrpos("team", 'i'));/*prints -1*/
	my_char('\n');

    return 0;
}
