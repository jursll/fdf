/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrusse <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:33:27 by julrusse          #+#    #+#             */
/*   Updated: 2024/12/14 15:19:47 by julrusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	int		s1_len;

	i = 0;
	j = 0;
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	str = (char *)ft_calloc((s1_len + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (free(s1), NULL);
	if (s1)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
*/
/*
#include <stdio.h>
int	main(void)
{
	char const a[] = "Hello ";
	char const b[] = "World!";
	char const c[] = "";

	printf("%s\n", ft_strjoin(a, b));
	printf("%s\n", ft_strjoin(c, c));
	return (0);
}
*/
