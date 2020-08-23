#include <stdio.h>

static struct fault_info {
	int	code;
	const char *name;
} fault_info[] = {
	{0,		"ttbr address size fault"	},
	{0,		"level 1 address size fault"	}
};
int main()
{
    printf("name : %s\n", fault_info[0].name);
    printf("name : %s\n", fault_info[1].name);
}
