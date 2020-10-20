#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "integer-input.h"

void printInt(void *p, size_t width)
{
	unsigned char *bytes = (unsigned char *)(p);
	for (ssize_t i = width - 1; i >= 0; --i) {
		printf("%02x ", *(bytes + i));
	}  
	printf("\n");
}

int main()
{
	puts("Enter an integer: ");
	int n = 0;
	intFromStdin(&n);
	printInt(&n, sizeof(n));

//	long long l = 16711680;
//	printInt(&l, sizeof(l));
	return 0;
}
