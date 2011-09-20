#include <math.h>
#include <stdio.h>
#include <fenv.h>

double a=12345.5343;
long int b;

void
fun_C(int x, int y, int z)
{
	fesetround(FE_DOWNWARD);
	b=lrint(a);
	printf("%ld\n", b);
}

void
fun_B(int x, int y, int z)
{
	int B_x=x+1, B_y=y+1, B_z=z+1;
	fun_C(B_x, B_y, B_z);
}

void
fun_A(int x, int y, int z)
{
	int A_x=x+1, A_y=y+1, A_z=z+1;
	fun_B(A_x, A_y, A_z);
}

int
main()
{
	int x=3, y=4, z=5;
	fun_A(x, y, z);
	return 0;
}
