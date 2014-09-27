/*Bradford Smith (bsmith8)
*remove_node_at.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node** pHead and an unsigned int i
*post: removes the node at the index i from the list pointed to by pHead
*		and returns it's element
*/
void* remove_node_at(t_node **pHead, unsigned int i)
{
	t_node *n;
	t_node *h;
	t_node *p;
	void *e;

	if(pHead == NULL)
		return NULL;
	if(i == 0)
		return remove_node(pHead);
	else
	{
		h = *pHead;
		n = NULL;
		for( ; h->next != NULL && i > 0; h = h->next, i--)
			p = h;
		if(h->next != NULL)
			n = h->next;
		h->next = NULL;
		e = h->elem;
		h->elem = NULL;
		free(h);
		p->next = n;
	}
	return e;
}
