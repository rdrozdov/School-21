/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:19:36 by gcolene           #+#    #+#             */
/*   Updated: 2022/03/15 17:01:39 by gcolene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

static size_t	lines_len(char **lines)
{
	int	i;

	i = 0;
	if (!lines[i])
		return (i);
	while (lines[i])
		i++;
	return (i);
}

t_node	*initiator_parser(int ac, char **av)
{
	int		i;
	int		len;
	t_node	*node;
	t_node	*tmp;
	t_node	*tmp2;

	len = ac - 1;
	node = (t_node *) malloc(sizeof(t_node));
	node->index = 0;
	node->value = ft_atoi(av[1]);
	node->len_a = len;
	node->next = NULL;
	tmp = node;
	i = 2;
	while (av[i])
	{
		tmp2 = (t_node *) malloc(sizeof(t_node));
		tmp2->index = 0;
		tmp2->value = ft_atoi(av[i++]);
		tmp2->len_a = len;
		tmp2->next = NULL;
		tmp->next = tmp2;
		tmp = tmp->next;
	}
	return (node);
}

static t_node	*node_creator(int len, char **lines, t_node *node)
{
	int		i;
	t_node	*tmp;
	t_node	*tmp2;

	tmp = node;
	i = 1;
	while (lines[i])
	{
		tmp2 = (t_node *) malloc(sizeof(t_node));
		tmp2->index = 0;
		tmp2->value = ft_atoi(lines[i++]);
		tmp2->len_a = len;
		tmp2->next = NULL;
		tmp->next = tmp2;
		tmp = tmp->next;
	}
	return (node);
}

t_node	*quote_parser(char **av)
{
	int		len;
	t_node	*node;
	char	**lines;

	lines = NULL;
	if (ft_strlen(av[1]) != 0)
		lines = ft_split(av[1], ' ');
	else
		ft_error();
	len = lines_len(lines);
	node = (t_node *) malloc(sizeof(t_node));
	node->index = 0;
	node->value = ft_atoi(lines[0]);
	node->len_a = len;
	node->next = NULL;
	node_creator(len, lines, node);
	return (node);
}
