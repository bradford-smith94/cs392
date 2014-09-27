/*Bradford Smith (bsmith8)
*empty_list.c libmylist project
*9/23/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node** pHead
*post: removes all the nodes in the list pointed to by pHead
*/
void empty_list(t_node **pHead)
{
	if(pHead != NULL)
	{
		while(*pHead != NULL)
			remove_node(pHead);
	}
}
