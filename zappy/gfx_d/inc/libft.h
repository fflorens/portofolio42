/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauci <bgauci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 13:44:46 by bgauci            #+#    #+#             */
/*   Updated: 2014/06/24 18:38:42 by bgauci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

char		*ft_strjoin		(char const *s1, char const *s2);
char		*strsub		(char const *s, unsigned int start, size_t len);
void		ft_strjcat		(char **s1, const char *s2);
char		*ft_truncate	(char **s, char c);

#endif
