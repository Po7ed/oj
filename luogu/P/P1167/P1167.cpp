#include <iostream>
#include <algorithm>
using namespace std;

bool rn(int y)
{
	
	if(y%100==0)
		if(y%400==0)
			return 1;
		else
			return 0;
    else
		if(y%4==0)
			return 1;
	else return false;
}

int crn(int y)
{
	int c=0;
	for(int i=0;i<=y;i++)
		if(rn(i))
			c++;
	return c;
}

int m[]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int mrn[]={0,0,31,60,91,121,152,182,213,244,274,305,335};

int main()
{
	// freopen("P1167in","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int y1,m1,d1,h1,mi1;
	int y2,m2,d2,h2,mi2;
	scanf("%d-%d-%d-%d:%d\n%d-%d-%d-%d:%d",&y1,&m1,&d1,&h1,&mi1,&y2,&m2,&d2,&h2,&mi2);
	unsigned long long t1=(y1*365+crn(y1))*24*60+(rn(y1)?mrn[m1]:m[m1])*24*60+(d1-1)*24*60+h1*60+mi1
	,t2=(y2*365+crn(y2))*24*60+(rn(y2)?mrn[m2]:m[m2])*24*60+(d2-1)*24*60+h2*60+mi2;
	int t=t2-t1;
	sort(a+1,a+n+1);
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(t>=a[i])
		{
			t-=a[i];
			c++;
		}
		else break;
	}
	printf("%d",c);
	return 0;
}