/*Bradford Smith (bsmith8)
*mylist.h libmylist project header file
*9/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MYLIST_H_
#define _MYLIST_H_

#include "my.h"

typedef struct s_node
{
	void *elem;
	struct s_node *next;
}				t_node;

/* This is the header for the libmylist project,
* it is an implementation of a single linked list
*it is made using (void*)'s to make it flexible
*/

t_node* new_node(void*, t_node*);
void add_node(t_node*, t_node**);
void add_elem(void*, t_node**);
void append(t_node*, t_node**);
void add_node_at(t_node*, t_node**, unsigned int);
void* remove_node(t_node**);
void* remove_node_at(t_node**, unsigned int);
void* remove_last(t_node**);
unsigned int count_nodes(t_node*);
void empty_list(t_node**);
t_node* node_at(t_node*, unsigned int);
void* elem_at(t_node*, unsigned int);
void traverse_int(t_node*);
void traverse_char(t_node*);
void traverse_string(t_node*);

#endif
