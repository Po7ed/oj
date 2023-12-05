#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	char xc;
	double ans;
	int r=1;
	int ch=0,xi=0;
	int d=-1,f=1;
	char c=getchar();
	while(c!='\n')
	{
		if(isalpha(c))
		{
			xc=c;
			if(d==-1)
				d=1;
			xi+=(d*f*r);
			// f=1;
			d=-1;
			c=getchar();
			if(c=='\n')
			{
				d=-1;
				break;
			}
			if(c=='+')
				f=1;
			else if(c=='-')
				f=-1;
			else
			{
				f=1;
				r=-1;
			}
			c=getchar();
			continue;
		}
		if(c=='=')
		{
			ch+=(d*f*(-r));
			r=-1;
			d=-1;
			c=getchar();
			if(c=='+')
				f=1;
			else if(c=='-')
				f=-1;
			else
			{
				f=1;
				continue;
			}
			c=getchar();
		}
		if(c=='-'||c=='+')
		{
			if(d!=-1)
				ch+=(d*f*(-r));
			d=-1;
			if(c=='-')
				f=-1;
			else
				f=1;
		}
		if(isdigit(c))
		{
			if(d==-1)
				d=c-'0';
			else
				d=d*10+c-'0';
		}
		c=getchar();
	}
	if(d!=-1)
		ch+=(d*f*(-r));
	ans=(double)ch/(double)xi;
	if(ans==-0.0)
		ans=0.0;
	printf("%c=%.3lf",xc,ans);
	return 0;
}
//6a-5+1=2-2a