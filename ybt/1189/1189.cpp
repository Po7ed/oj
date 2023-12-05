#include <iostream>
#include <string.h>
using namespace std;
short pell[1000000];
int main()
{
	int max=2;
	memset(pell,0,sizeof(pell));
	int n;
	scanf("%d",&n);
	pell[1]=1;pell[2]=2;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		if(pell[t]!=0)printf("%d\n",pell[t]);
		else
		{
			for(int i=max+1;i<=t;i++)
			{
				pell[i]=(pell[i-2]+2*pell[i-1])%32767;
			}
			printf("%d\n",pell[t]);
		}
		if(t>max)max=t;
	}
	return 0;
}