#include <cstdio>
#include <cstdlib>
int main()
{
	freopen("gcd.in","w",stdout);
	puts("100000");
	srand(*(new unsigned int));
	for(int i=1;i<=100000;i++)
	{
		printf("%d ",rand()%999+2);
	}
}