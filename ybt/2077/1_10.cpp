#include <iostream>
#include <stdio.h>
using namespace std;

class node
{
public:
	short frt;
	int q;
	int last,next;
	int on;
};

void del(int n,node a[])
{
	a[a[n].last].next=a[n].next;
	a[a[n].next].last=a[n].last;
	return;
}

void compress(int n,node a[])
{
	for(int i=2;i<=n;i=a[i].next)
	{
		if(a[i].frt==a[a[i].last].frt)
		{
			a[i].q+=a[a[i].last].q;
			del(a[i].last,a);
		}
	}
	return;
}

void getfrt(int n,node a[])
{
	bool bf=0;
	if(a[0].last==n+1)
		return;
	for(int i=1;i<=n;i=a[i].next)
	{
		if(a[i].q==1)
			del(i,a);
		else
		{
			if(bf)
				printf(" ");
			printf("%d",&a[i].on);
			a[i].on++;
			a[i].q--;
			bf=1;
		}
	}
	puts("");
	getfrt(n,a);
	return;
}

int main()
{
	int n=0;
	scanf("%d",&n);
	node ll[n+2];
	ll[0].frt=ll[n+1].frt=-1;
	ll[0].last=ll[n+1].next=-1;
	ll[0].next=1;ll[n+1].last=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ll[i].frt);
		ll[i].q=1;
		ll[i].last=i-1;
		ll[i].next=i+1;
		ll[i].on=i;
	}
	compress(n,ll);
	getfrt(n,ll);
	return 0;
}
