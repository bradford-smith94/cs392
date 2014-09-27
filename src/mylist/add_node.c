/*Bradford Smith (bsmith8)
*add_node.c libmylist project
*9/20/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node* pNode and a t_node** pHead
*post: adds pNode to the front of the list pointed to by pHead and updates the head
*		pointer to point to the newly added node
*/
void add_node(t_node *pNode, t_node **pHead)
{
	if(pHead != NULL && pNode != NULL)
	{
		if(pNode->elem != NULL)
		{
			pNode->next = *pHead;
			*pHead = pNode;
		}
	}
}
