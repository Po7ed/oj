#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int nn=1<<n;
	for(int i=0;i<nn;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			printf((i&(1<<(j))?"Y":"N"));
		}
		puts("");
	}
	return 0;
}