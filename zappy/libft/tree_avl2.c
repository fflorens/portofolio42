/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_AVL2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:53:24 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:41:51 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_avl.h"
#include "string.h"
#include "libft.h"
#include <stdlib.h>

char		*ft_tree_chr(t_tree_avl *root, char *index)
{
	int	hach;
	int	i;

	if (!index || !root)
		return (NULL);
	hach = ft_strhach_bis(index);
	while (1)
	{
		i = root->hach - hach;
		if (i == 0)
			i = ft_strcmp(root->index, index);
		if (i == 0)
			return (root->result);
		if (i < 0 && root->left != NULL)
			root = root->left;
		else if (i > 0 && root->right != NULL)
			root = root->right;
		else
			return (NULL);
	}
	return (NULL);
}

void		ft_tree_add(t_tree_avl **root, t_tree_avl *sheet)
{
	t_tree_avl	*tmp;
	int			i;

	if (!root || !sheet)
		return ;
	if (*root == NULL)
	{
		*root = sheet;
		return ;
	}
	tmp = *root;
	i = 1;
	while (i)
	{
		i = ft_tree_cmp(tmp, sheet);
		if (!ft_tree_add2(i, &tmp, sheet))
			break ;
	}
	ft_tree_balance(tmp);
}

int			ft_tree_add2(int i, t_tree_avl **tmp, t_tree_avl *sheet)
{
	t_tree_avl	**a;

	a = NULL;
	if (i == 0)
	{
		(*tmp)->hach = sheet->hach;
		(*tmp)->index = sheet->index;
		(*tmp)->result = sheet->result;
		return (0);
	}
	else if (i < 0)
		a = &((*tmp)->left);
	else if (i > 0)
		a = &((*tmp)->right);
	if (a && *a != NULL)
		*tmp = *a;
	else if (a != NULL)
	{
		*a = sheet;
		return (0);
	}
	return (1);
}

int			ft_tree_cmp(t_tree_avl *root, t_tree_avl *sheet)
{
	int	i;

	if (!root || !sheet)
		return (0);
	i = root->hach - sheet->hach;
	if (i != 0)
		return (i);
	return (ft_strcmp(root->index, sheet->index));
}

int			ft_tree_strcmp(t_tree_avl *root, char *str)
{
	int	i;

	if (!root)
		return (0);
	i = root->hach - ft_strhach_bis(str);
	if (i != 0)
		return (i);
	return (ft_strcmp(root->index, str));
}
