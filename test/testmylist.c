/*Bradford Smith (bsmith8)
*testmylist.c libmylist project test main
*9/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mylist.h"

int main()
{
	t_node *head;
	t_node *n1;
	t_node *n2;
	int *i1;
	int *i2;
	int *i3;
	int i;
	int j;
	int k;
	char *c1;
	char *c2;
	char *c3;
	char a;
	char b;
	char c;

	head = (t_node*)xmalloc(10*sizeof(t_node));
	
	/*new_node*/
	n1 = new_node("one\n", NULL);
	my_str(n1->elem);/*prints one*/
	n1->elem = NULL;
	free(n1);
	n1 = new_node(NULL, NULL);
	if(!n1->elem)
		my_str("create NULL node ok\n");
	else
		my_str("create NULL node FAIL!\n");
	free(n1);
	n1 = new_node("a", NULL);
	n2 = new_node("b", n1);
	my_str(n2->elem);
	my_str((n2->next)->elem);/*prints ba*/
	my_char('\n');
	my_str("---------------------------------------------------------------------\n");

	/*add_node*/
	add_node(n1, &head);
	my_str((*head).elem);/*prints a*/
	my_char('\n');
	add_node(n2, &head);
	my_str((*head).elem);/*prints b*/
	my_char('\n');
	add_node(NULL, &head);
	if(strcmp((*head).elem, n2->elem) == 0)
		my_str("add NULL node ok\n");
	else
		my_str("add NULL node FAIL!\n");
	add_node(new_node("something", NULL), NULL);/*if this line doesn't segfault then we're good!*/
	my_str("---------------------------------------------------------------------\n");

	/*traversals*/
	empty_list(&head);
	i = 3;
	i1 = &i;
	add_node(new_node(i1, NULL), &head);
	j = 2;
	i2 = &j;
	add_node(new_node(i2, NULL), &head);
	k = 1;
	i3 = &k;
	add_node(new_node(i3, NULL), &head);
	traverse_int(head);/*prints 1 2 3 */
	my_char('\n');
	traverse_int(NULL);/*if this doesn't segfault then we're good!*/

	empty_list(&head);
	c = 'c';
	c1 = &c;
	add_node(new_node(c1, NULL), &head);
	b = 'b';
	c2 = &b;
	add_node(new_node(c2, NULL), &head);
	a = 'a';
	c3 = &a;
	add_node(new_node(c3, NULL), &head);
	traverse_char(head);/*prints a b c */
	my_char('\n');
	traverse_char(NULL);/*if this doesn't segfault then we're good!*/

	empty_list(&head);
	add_node(new_node("third", NULL), &head);
	add_node(new_node("second", NULL), &head);
	add_node(new_node("first", NULL), &head);
	traverse_string(head);/*prints first second third */
	my_char('\n');
	traverse_string(NULL);/*if this doesn't segfault then we're good!*/
	empty_list(&head);
	my_str("---------------------------------------------------------------------\n");

	/*add_elem*/
	add_elem("a", &head);
	add_elem("b", &head);
	add_elem("c", &head);
	my_str(head->elem);/*prints c*/
	my_char('\n');
	add_elem(NULL, &head);
	if(strcmp(head->elem, "c") == 0)
		my_str("add NULL elem ok\n");
	else
		my_str("add NULL elem FAIL!\n");
	my_str("---------------------------------------------------------------------\n");
	
	/*append*/
	append(new_node("z", NULL), &head);
	traverse_string(head);/*prints c b a z*/
	my_char('\n');
	append(NULL, &head);
	traverse_string(head);/*prints c b a z*/
	my_char('\n');
	append(new_node("stuff", NULL), NULL);/*if this line doesn't segfault then we're good!*/
	my_str("---------------------------------------------------------------------\n");

	/*add_node_at*/
	add_node_at(new_node("d", NULL), &head, 0);
	traverse_string(head);/*prints d c b a z*/
	my_char('\n');
	add_node_at(new_node("y", NULL), &head, 42);
	traverse_string(head);/*prints d c b a z y*/
	my_char('\n');
	add_node_at(new_node("0", NULL), &head, 4);
	traverse_string(head);/*prints d c b a 0 z y*/
	my_char('\n');
	add_node_at(NULL, &head, 2);
	traverse_string(head);/*prints d c b a 0 z y*/
	my_char('\n');
	add_node_at(new_node("something", NULL), NULL, 7);/*if this line doesn't segfault then we're good!*/
	my_str("---------------------------------------------------------------------\n");

	/*remove_node*/
	my_str(remove_node(&head));/*prints d*/
	my_str(": ");
	traverse_string(head);
	my_char('\n');
	if(!remove_node(NULL))
		my_str("remove node from NULL ok\n");
	else
		my_str("remove node from NULL FAIL!\n");
	my_str("---------------------------------------------------------------------\n");

	/*remove_node_at*/
	my_str(remove_node_at(&head, 0));/*prints c*/
	my_str(": ");
	traverse_string(head);
	my_char('\n');
	my_str(remove_node_at(&head, 42));/*prints y*/
	my_str(": ");
	traverse_string(head);
	my_char('\n');
	my_str(remove_node_at(&head, 2));/*prints 0*/
	my_str(": ");
	traverse_string(head);
	my_char('\n');
	if(!remove_node_at(NULL, 100))
		my_str("remove node from NULL ok\n");
	else
		my_str("remove node from NULL FAIL!\n");
	my_str("---------------------------------------------------------------------\n");

	/*remove_last*/
	my_str(remove_last(&head));/*prints z*/
	my_str(": ");
	traverse_string(head);
	my_char('\n');
	if(!remove_last(NULL))
		my_str("remove last from NULL ok\n");
	else
		my_str("remove last from NULL FAIL!\n");
	my_str("---------------------------------------------------------------------\n");

	/*count_nodes*/
	my_int(count_nodes(head));/*prints 2*/
	my_char('\n');
	my_int(count_nodes(NULL));/*prints 0*/
	my_char('\n');
	my_str("---------------------------------------------------------------------\n");

	/*node_at*/
	my_str((node_at(head, 1))->elem);/*prints a*/
	my_char('\n');
	my_str((node_at(head, 0))->elem);/*prints b*/
	my_char('\n');
	my_str((node_at(head, 42))->elem);/*prints a*/
	my_char('\n');
	if(!node_at(NULL, 12))
		my_str("node at with NULL ok\n");
	else
		my_str("node at with NULL FAIL!\n");
	my_str("---------------------------------------------------------------------\n");

	/*elem_at*/
	my_str(elem_at(head, 0));/*prints b*/
	my_char('\n');
	my_str(elem_at(head, 1));/*prints a*/
	my_char('\n');
	my_str(elem_at(head, 42));/*prints a*/
	my_char('\n');
	if(!elem_at(NULL, 3))
		my_str("elem at with NULL ok\n");
	else
		my_str("elem at with NULL FAIL!\n");
	my_str("---------------------------------------------------------------------\n");

	/*empty_list*/
	my_int(count_nodes(head));/*prints 3*/
	my_char('\n');
	empty_list(&head);
	my_int(count_nodes(head));/*prints 0*/
	my_char('\n');
	empty_list(NULL);/*if this doesn't segfault then we're good!*/
	my_str("---------------------------------------------------------------------\n");

	return 0;
}
