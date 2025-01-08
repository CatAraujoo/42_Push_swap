/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:03:00 by catarina          #+#    #+#             */
/*   Updated: 2024/12/30 18:12:40 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;
    
    if (lst)
    {
        if (*lst)
        {
            last = ft_lstlast(*lst);
            last->next = new;
        }
        else
            *lst = new;
    }
}