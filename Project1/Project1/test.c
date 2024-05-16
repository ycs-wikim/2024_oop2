#include <stdio.h>

void main() {
	int i, total = 0;
	for (i = 0; ;)
	{
		i++;
		if (i % 5 == 0) continue;
		if (i > 100) break;
		total += i;		// total = total + i;

	}
	printf("1+2+ ... + 99 = %d\n", total);
}