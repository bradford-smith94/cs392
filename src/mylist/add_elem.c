/*Bradford Smith (bsmith8)
*add_elem.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a void* pElem and a t_node** pHead
*post: creates a new node with pElem and inserts it at the front of the list
		pointed to by pHead
*/
void add_elem(void *pElem, t_node **pHead)
{
	if(pElem != NULL && pHead != NULL)
	{
		add_node(new_node(pElem, NULL), pHead);
	}
}
