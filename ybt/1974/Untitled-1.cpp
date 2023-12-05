#include <iostream>
using namespace std;

bool date_rightful(int date)
{
	int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int m=0,d=0;
	m=date/100;
	d=date%100;
	if(1<=m&&m<=12&&1<=d&&d<=month[m])
		return 1;
	return 0;
}

int main()
{
	int d1,d2,y1,y2,count=0;
	cin>>d1>>d2;
	y1=d1/10000;
	y2=d2/10000;
	for(int i=y1;i<=y2;i++)
	{
		int a,b,c,d;
		a=i/1000;
		b=(i-a*1000)/100;
		c=(i-a*1000-b*100)/10;
		d=i%10;
		int td=d*1000+c*100+b*10+a;
		if(i==y1)
		{
			if(d1%10000>=td)
				continue;
		}
		if(i==y2)
		{
			if(d2%10000<=td)
				continue;
		}
		if(0<=a&&a<=9&&0<=b&&b<=3&&0<=c&&c<=9&&0<=d&&d<=1)
		{
			if(date_rightful(td))
				count++;
		}
	}
	printf("%d",count);
	return 0;
}
