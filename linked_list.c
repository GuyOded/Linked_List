#include "linked_list.h"
#include <stdlib.h>

/*
 * List *init_list()
 *
 * initialize a new list with zero elements and returns
 * pointer to it.
 *
 */
List *init_list()
{
	/* allocate block for list */
	List *l = (List *)malloc(sizeof(List));
	if(l == NULL)
	{
		return NULL;
	}
	/* initializing list */
	l->first = NULL;
	l->last = NULL;
	l->length = 0;
	l->sum = 0;
	return l;
}

/*
 * void destroy(List *l)
 *
 * removes all elements from the given list l
 * and frees the list
 *
 */
void destroy(List *l)
{
	if(l == NULL)
		return;

	/* check if list is already empty */
	if(l->length == 0)
	{
		return;
	}
	Node *np = l->first;
	while(np != NULL)
	{
		np = delete(l, np);
	}
	free(l);
}

/*
 * Node *delete(List *l, Node *pos)
 *
 * deletes the node pos from the given list l
 * returns the next node of the deleted one, unless
 * it was the last node in which case the function returns
 * its previous node.
 *
 */
Node *delete(List *l, Node *pos)
{
	if(l == NULL)
		return NULL;

	Node *next_pos;
	if(pos == NULL)
	{
		return NULL;
	}

	/* check if pos is first and chain it correctly */
	if(l->first == pos)
	{
		l->first = pos->next;
		next_pos = pos->next;
		/*update the previous element of the new first node*/
		/*The condition is necessary in case the deleted element
		 * is the only element of the list*/
		if(next_pos != NULL)
			next_pos->prev = NULL;
	}
	else if(l->last == pos)
	{
		l->last = pos->prev;
		next_pos = pos->prev;
		next_pos->next = NULL;
	}
	else
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		next_pos = pos->next;
	}

	/* updating all the list properties */
	l->sum -= pos->val;
	l->length--;

	/* releasing memory */
	free(pos);
	return next_pos;
}

/*
 * Node *add_node(List *l, int val)
 *
 * Given an integer value, a node is added to the end of
 * the list. Its pointer is returned.
 *
 */
Node *add_node(List *l, int value)
{
	if(l == NULL)
		return NULL;

	/* allocate block for the node and assign data */
	Node *np = (Node *)malloc(sizeof(Node));
	if(np == NULL)
	{
		return NULL;
	}

	np->next = NULL;
	np->prev = NULL;
	np->val = value;
	if(l->length == 0)
	{
		l->first = np;
		l->last = np;
	}
	else
	{
		np->prev = l->last;
		l->last->next = np;
		np->next = NULL;
		l->last = np;
	}

	l->length++;
	l->sum += np->val;
	return np;
}

/*
 * void set_val(int value, Node *n, List *l)
 *
 * given an integer and a node sets the node current val
 * member to the given value.
 * The list pointer is given as a parameter so the members
 * sum and length will be correctly updated.
 *
 */
void set_val(int value, Node *n, List *l)
{
	if(n == NULL || l == NULL)
	{
		return;
	}
	l->sum += value - n->val;
	n->val = value;
}

/*
 *  void print_list(List *l)
 *
 * This function is for debugging purposes only !
 * Given a list pointer, all nodes values will be printed
 *
 *
 */
#ifdef DEBUG
#include <stdio.h>
void print_list(List *l)
{
	if(l == NULL)
		return;

	Node *np = l->first;
	while(np != NULL)
	{
		printf("%d ", np->val);
		np = np->next;
	}
	printf("\n");
}
#endif
/*
 * Node *get_prev(Node *n)
 *
 * given a node n returns the pointer to
 * the previous node in the list.
 * NULL(0) is returned if either n or the previous
 * Node points to NULL
 *
 */
Node *get_prev(Node *n)
{
	if(n == NULL)
	{
		return NULL;
	}
	return n->prev;

}

/*
 * Node *get_next(Node *n)
 *
 * given a node n returns the pointer to
 * the following node in the list.
 * NULL(0) is returned if either n or the following
 * Node points to NULL
 *
 */
Node *get_next(Node *n)
{
	if(n == NULL || n->next == NULL)
	{
		return NULL;
	}
	return n->next;
}

/*
 * Node *get_first(List *l)
 *
 * given a list pointer l, returns the first node
 * of the list. NULL is returned if the first node
 * or l is NULL
 *
 */
Node *get_first(List *l)
{
	if(l == NULL)
	{
		return NULL;
	}
	return l->first;
}

/*
 * Node *get_last(List *l)
 *
 * given a list pointer l, returns the last node
 * of the list. NULL is returned if the last node
 * or l equals to NULL
 *
 */
Node *get_last(List *l)
{
	if(l == NULL)
	{
		return NULL;
	}
	return l->last;
}

/*
 * int get_val(Node *n)
 *
 * given a node n, returns its val member
 *
 */
int get_val(Node *n)
{
	if(n == NULL)
		return 0;

	return n->val;
}

/*
 * float avg(List *l)
 *
 * returns a float represents the average value of the list
 *
 */
float avg(List *l)
{
	if(l == NULL)
	{
		return 0.0;
	}
	return l->length == 0 ? 0.0 : (float)l->sum / l->length;
}

/*
 * int get_length(List *l)
 *
 * returns the given list's length
 *
 */
int get_length(List *l)
{
	if(l == NULL)
	{
		return 0;
	}
	return l->length;
}

