#include <stdio.h>

int main()
{
	int age = 10;
	char *citys[] = {"Almaty", "Astana"};

	for (int i = 0; i < 3; i++) {
		printf("%d city: %s\n", i + 1, citys[i]);
	}

	return 0;
}
