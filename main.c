# include <stdio.h>
# include "c_libft.h"

int main (void)
{
	t_list *list = ft_lstnew("Hello World!");
	t_list	*current = list;

	ft_lstadd_back(&list, ft_lstnew("This is the second node"));
	ft_lstadd_back(&list, ft_lstnew("This is the third node"));
	ft_lstadd_back(&list, ft_lstnew("This is the fourth node"));

	while (current != NULL)
	{
		printf("[%s]\n", (char *)current->content);
		current = current->next;
	}

	ft_lstclear(&list, NULL);
	return (0);
}
