#include <cstdlib>
#include <cstdio>
#include <ctime>

int main()
{
	srand(time(0));
	printf("%d\n",(rand()<<15|rand())%int(1e8));
	return 0;
}