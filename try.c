#include "push_swap.h"

int main()
{
	t_dlist	*a;
	t_dlist *b;
	t_dlist *c;
	t_dlist *d;

	a = ft_dlstnew(12);
	b = ft_dlstnew(1);
	c = ft_dlstnew(0);
	d = ft_dlstnew(999);
	ft_dlstadd_back(&a, b);
	ft_dlstadd_back(&a, c);
	ft_dlstadd_front(&a, d);
	ft_dlstadd_front(&a, ft_dlstnew(1000));
	ft_dlstadd_back(&a, ft_dlstnew(11));
	ft_dlstadd_front(&a, ft_dlstnew(269));
	printf("Start of my list\n");
	while (a->next != NULL)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("%d\n", a->content);
	printf("End of my list\n");
	while (a->previous != NULL)
	{
		printf("%d\n", a->content);
		a = a->previous;
	}
	printf("%d\n", a->content);
	printf("Start of my list\n");
	// system("leaks a.out");
	return (0);
}
