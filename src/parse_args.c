#include "../libft/vector.h"
#include "../libft/libft.h"
#include "render.h"
#include "utils.h"

bool	does_exist(t_ivec *vec, int num)
{
	int	i;

	i = 0;
	while (i < vec->len)
	{
		if (vec->arr[i] == num)
			return (true);
		i++;
	}
	return (false);
}

t_ivec	*parse_args(int argc, const char **argv)
{
	int		i;
	int		j;
	t_ivec	*vec;
	char		**strs;
	int			num;

	vec = ivec_new(64);
	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], ' ');
		j = 0;
		while (strs[j] != NULL)
		{
			if (!is_integer(strs[j]))
				exit_program();
			num = ft_atoi(strs[j]);
			free(strs[j]);
			if (does_exist(vec, num))
				exit_program();
			ivec_append(vec, num);
			j++;
		}
		free(strs);
		i++;
	}
	return (vec);
}
