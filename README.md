Linked List library in c (hopefully what you guys had in mind)

The list structure has the following members: sum, length, first and last.

The node structure represents a single element in the list and has a member that contains the
data, a pointer to the next node in the list and the previous node.

All of the functions have full documentation in the source file.

The user must avoid updating the nodes directly thruogh a pointer, or else he must update
the list members aswell.
The user must remember to use the function destroy() when he finshed with the list
in order to free any allocated blocks.

I made a small memory check to see what happens when the destroy function is not called
and the resources are not released:

main:

long j, i;
List *l_check;

for (i = 0; i < 100000; ++i)
{
	l_check = init_list();
	for(j = 0; j < 100000; j++)
	{
		add_node(l_check, j % 10);
	}
	printf("%ld\n", i);
}

The result was that the computer got stuck for about 15 minutes (couldn't even check the process memory).

Next I freed everything using destroy()

for (i = 0; i < 100000; ++i)
{
	l_check = init_list();
	for(j = 0; j < 100000; j++)
	{
		add_node(l_check, j % 10);
	}
	destroy(l_check);
	printf("%ld\n", i);
}

Everything worked as intended, process mem and ram were mostly constant.


