/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_AVL4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 15:45:31 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:42:10 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_avl.h"

t_tree_avl	*ft_tree_last_descendant(t_tree_avl *root)
{
	if (!root)
		return (NULL);
	if (root->left == NULL)
		return (root);
	return (ft_tree_last_descendant(root->left));
}

t_tree_avl	*ft_tree_found(t_tree_avl *root, char *index)
{
	int	i;

	if (!root)
		return (NULL);
	i = ft_tree_strcmp(root, index);
	if (i == 0)
		return (root);
	else if (i < 0)
		return (ft_tree_found(root->left, index));
	else
		return (ft_tree_found(root->right, index));
}
