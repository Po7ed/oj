#include <iostream>
#include <cmath>
using namespace std;

typedef double db;

inline db root(db a,db b,db c)
{
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}

db a,v,l,d,w,t1,s1,s2,t2,s3,t3,tt,ss;

int main()
{
	scanf("%lf %lf\n%lf %lf %lf",&a,&v,&l,&d,&w);
	tt=w/a;
	ss=.5*tt*w;
	t1=v/a;
	s1=.5*t1*v;
	s2=l-s1;
	t2=s2/v;
	if(w>=v||ss>=d)
	{
		if(s1>l)
		{
			printf("%.10lf",root(.5*a,0,-l));
		}
		else
		{
			printf("%.10lf",t1+t2);
		}
	}
	else if(d>)
	{
		
	}
	return 0;
}