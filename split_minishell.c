/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:12:47 by mcraipea          #+#    #+#             */
/*   Updated: 2020/01/28 14:22:18 by mcraipea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*ft_sdup(char const *src, char c, char quote)
{
	char	*dest;
	int		i;

	i = 0;
	if (src[i] == quote)
	{
		i++;
		while (src[i] && src[i] != quote)
			i++;
	}
	else
	{
		i++;
		while (src[i] && src[i] != c)
			i++;
	}
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	if (src[i] == quote)
	{
		i++;
		dest[i] = src[i];
		i++;
		while (src[i] && src[i] != quote)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		dest[i] = src[i];
		i++;
		while (src[i] && src[i] != c)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

static char			**ft_tab_split(char **tab, char const *s, char c, char quote)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			if (!(tab[j++] = ft_sdup(&s[i], c, quote)))
				return (NULL);
		if (s[i] == quote)
		{
			i++;
			while (s[i] && s[i] != quote)
				i++;
			i++;
		}
		else
		{
			i++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

//   echo coucou a    tous ; echo "max" "et    coucou"

static char			**ft_free(char **tab)
{
	while (*tab)
	{
		free(*tab);
		(*tab)++;
	}
	free(tab);
	return (NULL);
}

char				**ft_split_minishell(char const *s)
{
	int		i;
	int		j;
	char	**tab;
	char	c;
	char	quote;

	c = ' ';
	quote = '"';
	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		if (s[i] == quote)
		{
			i++;
			while (s[i] && s[i] != quote)
				i++;
		}
		else
		{
			i++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	if (!(tab = ft_tab_split(tab, s, c, quote)))
		ft_free(tab);
	return (tab);
}

//   echo coucou a    tous ; echo "max" "et    coucou"
/*while espace au debut
	avancer
if " ou '
	mettre un flag a 1 ou a zero correspondant
	if flag " a 1 
		while pas de "
			copier dans tab
	else if flag ' a 1
		while pas de '
			copier dans tab
else
	while pas de space ou > ou >> ou < ou ; ou |
		copier dans tab
	if space
		i++
	else if > 
		if i++ = >
			copier dans tab nouvelle ligne >>
			i++
		else
			copier dans tab nouvelle ligne >
			i++
	else if < or ; or |
		copier dans tab nouvelle ligne correspondant
		i++
	*/
