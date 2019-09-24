// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   splired.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hessabra <hessabra@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/07/28 20:58:06 by hessabra          #+#    #+#             */
// /*   Updated: 2019/07/28 21:40:00 by hessabra         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// int         is_wspace(char c)
// {
//     if (c == ' ' || c == '\t' || c == '\n')
//         return (1);
//     return (0);
// }

// int         nbr_arg(char *str, int *bs)
// {
//     int result;
//     int marq;
//     int j;
//     int i;

//     result = 0;
//     i = -1;
//     j = 0;
//     marq = 1;
//     while(str[j])
//     {
//         i = 1;
		
// 		if (marq == 1 && str[j] == '>')
// 		{
// 			if (!is_wspace(str[j - 1]))
// 				result++;
// 			if (str[j + 1] == '>')
// 			{
// 				j++;
// 				marq = 0;
// 			}
// 			if (!is_wspace(str[j + 1]))
// 				result++;
// 			marq = 1;
// 		}
//         if (str[j] == 92)
//         {
//             (*bs > 0) ? i = 0 : i;
//             j += ft_entier(*bs);
//             bs++;
//         }
//         if (str[j] == 39 || str[j] == 34)
//         {
//             if (marq == 1 && (str[j] == 39 || (str[j] == 34 && i)))
//                 marq = 0;
//             else if (str[j] == 39 || (str[j] == 34 && i))
//                 marq = 1;
//         }
//         if (i && str[j] && (is_wspace(str[j]) && marq) && str[j + 1] && str[j + 1] > 32)
//             result++;
//         j++;
//     }
//     if (i != -1)
//         result++;
//     return (result);
// }

// int         lenarg(char *str, int i, int *bs)
// {
//     int     	i;
// 	int     	mark;
// 	char    	x;
// 	int			mixed;
// 	static int  j = 0;

// 	(m == 0) ? j = 0 : j;
// 	x = 0;
// 	if (arg[0] == 39)
// 		x = 39;
// 	else if (arg[0] == 34)
// 		x = 34;
// 	i = 0;
// 	if (x)
// 		i = 1;
// 	mark = 1;
// 	mixed = 1;
// 	if (!x)
// 	{
// 		while (arg[i] && ((arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n')
// 			|| (mark == 0 && (arg[i] == ' '
// 			|| arg[i] == '\t' || arg[i] == '\n'))))
// 		{
// 			mark = 1;
// 			if (arg[i] == 92)
// 			{
// 				(bs[j] > 0) ? mark = 0 : mark;
// 				i += ft_entier(bs[j]);
// 				j++;
// 			}
// 			(mark == 1 && (arg[i] == 34 || arg[i] == 39)) ? mixed = -1 : mixed;
// 			i++;
// 		}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
// 		i++;
// 	}
// 	else
// 	{
// 		*tok = 0; 
// 		while (arg[i] &&(arg[i] != x || (mixed < 0 && arg[i] > 32) || arg[i] == x))
// 		{
// 			if (arg[i] == 92 && x == 34)
// 			{
// 				(bs[j] > 0) ? mark = 0 : mark;
// 				i += ft_entier(bs[j]) - 1;
// 				(bs[j] > 0 && arg[i + 1] && arg[i + 1] != 39) ? i++ : i;
// 				j++;
// 			}
// 			i++;
// 			if (arg[i] == x && mark == 1 && arg[i + 1] && arg[i + 1] > 32)
// 				mixed = -1;
// 			mark = 1;
// 		}
// 			(mixed < 0) ? i++ : i;
// 	}
// 	return (i * mixed);
// }

// char        **splitred(char *str, int *bs)
// {
//     char    **last;
//     int     *token;
//     int     nbr_ar;
//     int     len;
//     int     i;

//     nbr_ar = nbr_arg(str, bs);
//     last = (char **)malloc(sizeof(char *) * (nbr_ar + 1));
//     token = (int *)malloc(sizeof(int) * (nbr_ar + 1));
//     i = 0;

//     while (i < nbr_ar)
//     {
//         len = len(arg);
//         last[i] = ft_strsub(str, 0, );
//         str += ;

//         i++;
//     }
//     token[i] = -1;
//     last[i] = NULL;
// }