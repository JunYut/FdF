# include <stdio.h>
# include "c_libft.h"

int main (void)
{
	t_list *list = ft_lstnew("Hello World!");
	t_list	*current = list;

	ft_lstadd_back(&list, ft_lstnew("This is the second node"));
	while (current != NULL)
	{
		printf("[%s]\n", (char *)current->content);
		current = current->next;
	}

	return (0);
}
