#ifndef VARS_H

# define VARS_H

#include <stdbool.h>
#include "../libft/vector.h"

#ifndef LOG

# define LOG true

#endif
 
typedef struct s_stack
{
	int	len;
	int	*nums;
	char c;
	struct s_stack	*other;
} t_stack;

typedef struct
{
	t_stack *a;
	t_stack	*b;
	bool		print_next_command;
	t_ivec	*chunks;
} t_vars;


#endif
