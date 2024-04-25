/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinandfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plangloi <plangloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:08:32 by plangloi          #+#    #+#             */
/*   Updated: 2024/01/03 14:16:26 by plangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinandfree(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;
	int		lens1;
	int		lens2;

	i = -1;
	j = -1;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (++i < lens1)
		join[i] = s1[i];
	while (++j < lens2)
		join[i + j] = s2[j];
	join [i + j] = '\0';
	free (s1);
	return (join);
}
