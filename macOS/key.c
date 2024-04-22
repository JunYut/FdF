# include "struct.h"

int key_hook(int keycode)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return 0;
}

int quit()
{
	exit(EXIT_SUCCESS);
	return (0);
}
