#include <stdio.h>
#include "integer-input.h"

void printInt(int n)
{
	size_t nAllocated = 24, i = 0;
	unsigned char *array = calloc(nAllocated, sizeof(*array));
	while (n) {
		if (i == nAllocated) {
			nAllocated += 10;
			unsigned char *tmp = realloc(array, sizeof(*tmp) * nAllocated);
			if (!tmp) {
				fprintf(stderr, "realloc failed.");
				exit(EXIT_FAILURE);
			}
			array = tmp;
		}
		array[i++] = n % 256;
		n /= 256;
	}
	while (i > 0) {
		printf("%02x", array[--i]);
	}
	printf("\n");
	free(array);
}

int main()
{
	int n = 0;
	intFromStdin(&n);
	printf("You entered %d\n", n);
	printInt(n);
	return 0;
}
