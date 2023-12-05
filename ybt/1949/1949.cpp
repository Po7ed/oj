#include <iostream>
using namespace std;
int main()
{
	int l,r,c=0;
	scanf("%d %d",&l,&r);
	for(int i=l;i<=r;i++)
	{
		if(i%10==2)c++;
		if(i/10%10==2)c++;
		if(i/100%10==2)c++;
		if(i/1000%10==2)c++;
	}
	printf("%d",c);
	return 0;
}