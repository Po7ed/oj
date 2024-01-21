#include <iostream>
#include <ctime>

const int N=1000000;

int main()
{
	freopen("rand.in","w",stdout);
	srand(time(NULL));
	printf("%d %d\n",N,N);
	for(int i=0;i<=N;i++)printf("%d ",rand()%10);
	puts("");
	for(int i=0;i<=N;i++)printf("%d ",rand()%10);
	puts("");
	return 0;
}