#include <stdio.h>
using namespace std;

void getfrt(int a[][2])
{
	*(*(a+1)+0)=9;
	return;
}

int main()
{
	int a[2][2];
	a[1][0]=0;
	getfrt(a);
	printf("%d",a[1][0]);
	return 0;
}