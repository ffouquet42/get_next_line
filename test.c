#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	char *str = "";

	while (str[i])
		i++;
	printf("%i", i);
	return (0);
}