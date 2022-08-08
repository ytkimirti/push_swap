#ifndef VARS_H

# define VARS_H

#include <stdbool.h>
#include "../libft/vector.h"

#ifndef LOG

# define LOG false

#endif
 
typedef struct
{
	int	len;
	int	*nums;
	char c;
} t_stack;

typedef struct
{
	t_stack *a;
	t_stack	*b;
	bool		print_next_command;
	t_ivec	*chunks;
} t_vars;


#endif
