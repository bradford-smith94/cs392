/*Bradford Smith (bsmith8)
*count_nodes.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node* pHead
*post: returns an unsigned int of the number of nodes in the list pointed to by pHead
*/
unsigned int count_nodes(t_node *pHead)
{
	unsigned int n = 0;

	if(pHead != NULL)
	{
			for( ; pHead->next != NULL; pHead++, n++)
			;
	}
	return n;
}
