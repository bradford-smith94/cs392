/*Bradford Smith (bsmith8)
*elem_at.c libmylist project
*9/23/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node* pHead and an unsigned int i
*post: returns a pointer to the element at the index i in the list pointed to by pHead
*/
void* elem_at(t_node *pHead, unsigned int i)
{
	t_node *h;

	if(pHead == NULL)
		return NULL;
	h = pHead;
	for( ; h->next != NULL && i > 0; h = h->next, i--)
		;
	return h->elem;
}
