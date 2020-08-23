#include <stdio.h>

int main() {
	int a;
	fscanf(stdin, "%d", &a);
	if (a > 0)
		fprintf(stderr, "Error: it is positive\n");
	else
		fprintf(stderr, "Error: it is negative\n");
	fprintf(stdout, "Hello World %-10d\n", a);

}

