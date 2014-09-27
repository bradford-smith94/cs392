/*Bradford Smith (bsmith8)
*traverse_string.c libmylist project
*9/20/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

/*pre: takes in a t_node* pHead
*post: prints out each element as a string or NULL if the element is NULL
*/
void traverse_string(t_node *pHead)
{
	if(pHead != NULL)
	{
		for( ; pHead != NULL; pHead = pHead->next)
		{
			if(pHead->elem == NULL)
				my_str("NULL");
			else
				my_str((char*)(pHead->elem));
			my_char(' ');
		}
	}
	else
	{
		my_str("The list is empty!\n");
	}
}
