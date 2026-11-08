/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <rperez-t@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:23:40 by rperez-t          #+#    #+#             */
/*   Updated: 2026/11/08 13:23:40 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H

# include "libft_libs.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
