/*Bradford Smith (bsmith8)
*remove_node.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node** pHead
*post: removes the first node in the list pointed to by pHead
*		and returns it's element
*/
void* remove_node(t_node **pHead)
{
	t_node *n;
	void *e;

	if(pHead == NULL)
		return NULL;
	n = *pHead;
	(*pHead) = n->next;
	n->next = NULL;
	e = n->elem;
	n->elem = NULL;
	free(n);
	return e;
}
