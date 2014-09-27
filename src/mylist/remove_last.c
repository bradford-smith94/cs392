/*Bradford Smith (bsmith8)
*remove_last.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node** pHead
*post: removes the last node in the list pointed to by pHead
*		and returns it's element
*/
void* remove_last(t_node **pHead)
{
	void *e;
	t_node *h;
	t_node *p;

	if(pHead == NULL)
		return NULL;
	h = *pHead;
	for( ; h->next != NULL; h = h->next)
		p = h;
	e = h->elem;
	h->elem = NULL;
	free(h);
	p->next = NULL;
	return e;
}
