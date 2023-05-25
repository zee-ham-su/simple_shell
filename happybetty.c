#include <stdio.h>
#include <stdlib.h>

/**
 * main - prompt, scan and print.
 *
 * Return: Always 0.
 */
int main(void)
{
	int age;

	printf("Enter your age: ");
	scanf("%d", &age);
	printf("You are %d years old \n", age);

	return (0);
}
