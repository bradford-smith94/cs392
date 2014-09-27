/*Bradford Smith (bsmith8)
*new_node.c libmylist project
*9/20/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a void* pElem and a t_node* pNext
*post: returns a pointer to a newly allocated t_node with contents elem and next
*/
t_node* new_node(void *pElem, t_node *pNext)
{
	t_node *n;

	n = (t_node*)xmalloc(sizeof(t_node));
	n->elem = pElem;
	n->next = pNext;
	return n;
}
