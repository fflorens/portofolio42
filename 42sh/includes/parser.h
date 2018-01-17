/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:18:12 by nmokrane          #+#    #+#             */
/*   Updated: 2014/03/27 21:39:08 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structs.h"

t_command				*get_command_list(char *cmdline);
t_pipeline				*get_pipeline(void);
t_process				*get_process(int id);
t_redirector			*get_redirector(t_token token, int id);

void					*parse_error(t_token *token);
t_bool					print_parse_error(void);

#endif
