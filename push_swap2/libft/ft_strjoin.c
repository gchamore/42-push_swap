/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:52 by gchamore          #+#    #+#             */
/*   Updated: 2023/11/17 11:42:01 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	if (!dest || !src)
		return (NULL);
	dest_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

//	La fonction ft_strjoin concatène deux chaînes de caractères
//	s1 et s2 pour former une nouvelle chaîne de caractères.
//	La nouvelle chaîne est allouée dynamiquement, et la
//	mémoire doit être libérée après utilisation.

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     const char *s1;
//     const char *s2;

// 	s1 = "Hello, ";
// 	s2 = "John!";
//     // Utilisation de strjoin pour concaténer les chaînes
//     char *str = ft_strjoin(s1, s2);

//     // Vérification de l'allocation de mémoire réussie
//     if (str != NULL) 
// 	{
//         printf("%s\n", str);

//         // N'oubliez pas de libérer la mémoire allouée
//         free(str);
//     } 
// 	else 
//         printf("Erreur d'allocation de mémoire.\n");
//     return 0;
// 	free (str);
// }