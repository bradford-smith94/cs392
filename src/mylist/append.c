/*Bradford Smith (bsmith8)
*append.c libmylist project
*9/21/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node* pNode and a t_node** pHead
*post: adds pNode to the end of the list pointed to by pHead
*/
void append(t_node *pNode, t_node **pHead)
{
	if(pNode != NULL && pNode->elem != NULL && pHead != NULL)
	{
		for( ; (*pHead)->next != NULL; pHead++)
			;
		(*pHead)->next = pNode;
	}
}
