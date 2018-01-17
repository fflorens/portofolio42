/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_AVL3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:46:21 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:42:03 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_avl.h"

t_strlist	*ft_tree_get_all_index(t_tree_avl *root)
{
	t_strlist	*res;
	t_strlist	*tmp;

	res = NULL;
	tmp = NULL;
	if (!root)
		return (NULL);
	ft_strlstaddend(&res, ft_strlstnew(root->index));
	tmp = res;
	while (res->next != NULL)
		res = res->next;
	res->next = ft_tree_get_all_index(root->left);
	while (res->next != NULL)
		res = res->next;
	res->next = ft_tree_get_all_index(root->right);
	return (tmp);
}

int			ft_count_sheet(t_tree_avl *root)
{
	int	i;

	if (!root)
		return (0);
	i = ft_count_sheet(root->left);
	i += ft_count_sheet(root->right);
	return (i);
}
