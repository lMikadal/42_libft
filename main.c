#include "libft.h"
#include <stdio.h>

void freeList(t_list *head) {if (head) freeList(head->next); free(head);}
void * addOne(void * p) {void * r = malloc(sizeof(int)); *(int*)r = *(int*)p + 1; return (r);}

int	main(void)
{
	int	tab[] = {1, 1, 2, 3};
	t_list *l = ft_lstnew(tab);
	int	i = 1;

	while (i < 4)
		ft_lstadd_back(&l, ft_lstnew(tab + i++));
	t_list *test = l;
	while (test != NULL)
	{
		printf("l %d\n", *(int *)test->content);
		test = test->next;
	}
	t_list *m = ft_lstmap(l, addOne, free);
	test = m;
	while (test != NULL)
	{
		printf("m %d\n", *(int *)test->content);
		test = test->next;
	}
	return (0);
}

