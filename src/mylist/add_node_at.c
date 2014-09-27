/*Bradford Smith (bsmith8)
*add_node_at.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node* pNode a t_node** pHead and an unsigned int i
*post: inserts pNode into the list pointed to by pHead at the index i
*/
void add_node_at(t_node *pNode, t_node **pHead, unsigned int i)
{
	t_node *h;
	if(pNode != NULL && pNode->elem != NULL && pHead != NULL)
	{
		if(i == 0)
			add_node(pNode, pHead);
		else
		{
			h = *pHead;
			for( ; h->next != NULL && i > 1; h = h->next, i--)
				;
			if(h->next != NULL)
				pNode->next = h->next;
			h->next = pNode;
		}
	}
}
