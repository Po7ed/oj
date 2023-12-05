#include <iostream>
#include <string.h>
using namespace std;

int a[21];

int get(int index)
{
	if(a[index]!=-1)
		return a[index];
	a[index]=get(index-1)+get(index-2);
	return a[index];
}

int main()
{
	memset(a,-1,sizeof(a));
	a[1]=1;a[2]=1;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int index;
		scanf("%d",&index);
		printf("%d\n",get(index));
	}
	return 0;
}