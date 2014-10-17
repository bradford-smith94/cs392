/*Bradford Smith (bsmith8)
*testmyatoi.c mysignals project my_atoi() test file
*10/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

int main(int argc, char **argv)
{
	my_int(my_atoi(my_vect2str(&argv[1])));
}
