
// C Program to demonstrate use of bitwise operators
#include <stdio.h>
int main()
{
    // a = 37 = 00100101
    // b = 23 = 00010111 unsigned
    char a = 37, b = 23;


	printf("a = %u, b = %u\n", a, b);
	//AND &
	printf("a&b = %d\n", a & b);
    // The result is 00000101 = (1*2^2) + (0*2^1) + (1*2^0) = 4+0+1 = 5

	//OR |
	printf("a|b = %d\n", a | b);
    // The result is 00110111

	// NOT ~
	printf("~a = %d\n", a = ~a);
	// The result is 11011010

	printf("a^b = %d\n", a^b);
	// The result is 00110010 11001101

	printf("a<<3 = %d\n", a << 3);
    // The result is 1|00101000

	printf("a>>3 = %d\n", a >> 3);
    // The result is  00000100
	return 0;

}
