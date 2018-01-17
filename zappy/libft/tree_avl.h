/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_avl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:26:54 by bgauci            #+#    #+#             */
/*   Updated: 2014/05/16 17:38:51 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_AVL_H
# define TREE_AVL_H
# include "libft.h"
# define MX(x, y) ((x)>(y)?(x):(y))

typedef struct	s_tree_avl
{
	int					hach;
	char				*index;
	char				*result;
	struct s_tree_avl	*left;
	struct s_tree_avl	*right;
	struct s_tree_avl	*root;
	int					len_left;
	int					len_right;
}				t_tree_avl;

t_tree_avl		*ft_tree_new			(char *index, char *result);
void			ft_tree_refresh			(t_tree_avl *root);
t_tree_avl		*ft_tree_balance		(t_tree_avl *root);
t_tree_avl		*ft_tree_left_rotation	(t_tree_avl *root);
t_tree_avl		*ft_tree_right_rotation	(t_tree_avl *root);
void			ft_tree_add				(t_tree_avl **root, t_tree_avl *sheet);
int				ft_tree_add2	(int i, t_tree_avl **tmp, t_tree_avl *sheet);
char			*ft_tree_chr			(t_tree_avl *root, char *index);
int				ft_tree_cmp				(t_tree_avl *root, t_tree_avl *sheet);
int				ft_tree_strcmp			(t_tree_avl *root, char *str);
int				ft_count_sheet			(t_tree_avl *root);
t_strlist		*ft_tree_get_all_index	(t_tree_avl *root);

#endif
