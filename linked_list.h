/*
 * linked_list.h
 *
 *  Created on: Dec 23, 2015
 *      Author: guy
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct list_node {
	struct list_node *next;
	struct list_node *prev;
	int val;
} Node;

typedef struct list{
	Node *first;
	Node *last;
	int length;
	int sum;
}List;

List *init_list();

void destroy(List *l);

Node *delete(List *l, Node *pos);

Node *add_node(List *l, int value);

void set_val(int value, Node *n, List *l);

int get_val(Node *n);

void print_list(List *l);

Node *get_prev(Node *n);

Node *get_next(Node *n);

Node *get_first(List *l);

Node *get_last(List *l);

float avg(List *l);

int get_length(List *l);

#endif /* LINKED_LIST_H_ */
