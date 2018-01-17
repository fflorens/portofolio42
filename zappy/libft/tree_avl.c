/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_AVL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:27:05 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:41:40 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_avl.h"
#include "string.h"
#include "libft.h"
#include <stdlib.h>

t_tree_avl	*ft_tree_new(char *index, char *result)
{
	t_tree_avl	*res;

	if ((res = malloc(sizeof(t_tree_avl))) == NULL)
		return (NULL);
	res->hach = ft_strhach_bis(index);
	res->index = index;
	res->result = result;
	res->left = NULL;
	res->right = NULL;
	res->root = NULL;
	res->len_left = 0;
	res->len_right = 0;
	return (res);
}

void		ft_tree_refresh(t_tree_avl *root)
{
	if (!root)
		return ;
	if (root->left != NULL)
		root->len_left = MX(root->left->len_left, root->left->len_right) + 1;
	else
		root->len_left = 0;
	if (root->right != NULL)
		root->len_right = MX(root->right->len_left, root->right->len_right) + 1;
	else
		root->len_right = 0;
}

t_tree_avl	*ft_tree_balance(t_tree_avl *root)
{
	int			i;
	t_tree_avl	*r;

	if (!root)
		return (NULL);
	i = root->len_left - root->len_right;
	if (root->root != NULL)
	{
		r = root->root->right;
		if (root->root->left == root)
			r = root->root->left;
		r = ((i < -1) ? ft_tree_left_rotation(root) : r);
		r = ((i > 1) ? ft_tree_right_rotation(root) : r);
		return (ft_tree_balance(root->root));
	}
	else if (i < -1)
		return (ft_tree_left_rotation(root));
	else if (i > 1)
		return (ft_tree_right_rotation(root));
	return (root);
}

t_tree_avl	*ft_tree_left_rotation(t_tree_avl *root)
{
	t_tree_avl	*tmp;
	t_tree_avl	*tmp2;

	if (!root)
		return (NULL);
	tmp = root->right;
	if (root->right->right != NULL)
	{
		tmp2 = root->right;
		root->right = root->right->left;
		tmp2->left = NULL;
	}
	else
	{
		root->right->right = root->right->left;
		root->right->left = NULL;
	}
	tmp->left = root;
	tmp->root = root->root;
	root->root = tmp;
	ft_tree_refresh(tmp);
	ft_tree_refresh(root);
	return (tmp);
}

t_tree_avl	*ft_tree_right_rotation(t_tree_avl *root)
{
	t_tree_avl	*tmp;
	t_tree_avl	*tmp2;

	if (!root)
		return (NULL);
	tmp = root->left;
	if (root->left->left != NULL)
	{
		tmp2 = root->left;
		root->left = root->left->right;
		tmp2->right = NULL;
	}
	else
	{
		root->left->left = root->left->right;
		root->left->right = NULL;
	}
	tmp->right = root;
	tmp->root = root->root;
	root->root = tmp;
	ft_tree_refresh(tmp);
	ft_tree_refresh(root);
	return (tmp);
}
