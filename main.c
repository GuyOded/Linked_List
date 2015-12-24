#include <stdio.h>
#include "linked_list.h"

int main()
{
	Node *p = NULL;
	List *l_check;
	int index;
	float average;
	l_check = init_list();

	for(index = 0; index < 10; ++index)
	{
		add_node(l_check, index);
	}
	print_list(l_check);

	average = avg(l_check);
	printf("average: %.3f\n", average);

	p = get_last(l_check);
	printf("delete last element: ");
	p = delete(l_check, p);
	print_list(l_check);

	printf("set last element: ");
	set_val(9, p, l_check);
	print_list(l_check);

	p = get_prev(p);
	printf("second to last element: %d\n", get_val(p));

	p = get_next(p);
	printf("last element: %d\n", get_val(p));

	printf("length: %d\n", get_length(l_check));

	destroy(l_check);


	return 0;
}
