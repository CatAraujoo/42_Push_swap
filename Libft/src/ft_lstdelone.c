/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:35:06 by catarina          #+#    #+#             */
/*   Updated: 2025/01/02 11:19:40 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst)
        return ;
    del((void *)lst->content);
    free(lst);
}
/*void	del(void *lst)
{
	free(lst);
}
#include "ft_lstnew.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include <stdio.h>

int	main(void)
{
	char *content = ft_strdup("Hello");
	t_list *node = ft_lstnew(content);
	ft_lstdelone(node, del);
	node = NULL;
}*/