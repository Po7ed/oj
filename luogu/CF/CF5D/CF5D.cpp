#include <iostream>
#include <cmath>
using namespace std;

inline double root(double a,double b,double c)
{
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}

double a,v,l,d,w,t1,s1,s2,t2,s3,t3;

int main()
{
	scanf("%lf %lf\n%lf %lf %lf",&a,&v,&l,&d,&w);
	t1=w/a;
	s1=w*t1/2;
	printf("%.10lf\n",s1);
	if(s1>=d)
	{
		printf("%.10lf",root(a/2,0,-l));
	}
	else
	{
		s2=d-s1;
		t2=root(.25,w+a/2,-s2);
		s3=l-d;
		t3=root(a/2,w,-s3);
		printf("%.10lf",t1+t2+t3);
	}
	return 0;
}