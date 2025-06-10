/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:39:53 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/10 21:39:55 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prot.h"

int draw_line_wrapper(void *ptr)
{
    if (ptr == NULL)
        return (ERR_NULL_VALUE_DETECTED);
    t_structs *val = (t_structs *)ptr;
    draw_line(val);
    return (0);
}
