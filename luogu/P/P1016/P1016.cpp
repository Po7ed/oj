#include <iostream>
using namespace std;

const int N=10;
double dall,c,dpl,ps,d[N],p[N];
int n;

int main()
{
	scanf("%lf %lf %lf %lf %d",&dall,&c,&dpl,&ps,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",d+i,p+i);
	}
	double cost=0;
	p[0]=ps;
	double k,mi,oil=0;
	int nxt,id;
	for(int i=0;i<=n;i++)
	{
		// printf("%d\n",i);
		k=0;
		mi=1e9;
		for(int j=i+1;j<=n;j++)
		{
			if(d[j]-d[i]>c*dpl)break;
			if(mi>p[j])
			{
				id=j;
				mi=p[j];
			}
			if(p[j]<=p[i])
			{
				k=((d[j]-d[i])/dpl-oil)*p[i];
				oil=0;
				nxt=j;
				break;
			}
		}
		if(k)
		{
			cost+=k;
			i=nxt-1;
		}
		else
		{
			if(dall-d[i]<=c*dpl)
			{
			// printf(" ");
				cost+=(((dall-d[i])/dpl-oil)*p[i]);
				oil=0;
				break;
			}
			else if(mi==1e9)
			{
				puts("No Solution");
				return 0;
			}
			else
			{
				cost+=(c*p[i]);
				oil+=(c-(d[id]-d[i])/dpl);
				i=id-1;
			}
		}
	}
	printf("%.2lf",cost);
	return 0;
}