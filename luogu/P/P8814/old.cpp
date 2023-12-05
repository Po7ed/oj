#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int k;
	scanf("%d",&k);
	double n,e,d,m,q,p;
	while(k--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		n=a;e=b;d=c;
//		printf("!%f %f %f\n",n,e,d);
		m=n-e*d+2;
		if(m*m<4*n)
		{
			puts("NO");
			continue;
		}
		q=(-m+sqrt(m*m-4*n))/(double)(-2);//printf("1#%f;%f\n",q,m);
		p=m-q;
		if(q>0&&q==(unsigned long long)q&&p>0)
		{
			printf("%llu %llu\n",(unsigned long long)min(q,p),(unsigned long long)max(q,p));
			continue;
		}
		else
		{
			q=(-m-sqrt(m*m-4*n))/(double)(-2);//printf("2#%f;%f\n",q,m);
			p=m-q;
			if(q>0&&q==(unsigned long long)q&&p>0)
			{
				printf("%llu %llu\n",(unsigned long long)min(q,p),(unsigned long long)max(q,p));
				continue;
			}
			else
			{
				puts("NO");
			}
		}
	}
	return 0;
}