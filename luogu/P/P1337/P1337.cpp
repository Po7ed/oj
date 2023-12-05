#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

typedef double d;
const d down=0.997,Beg=1e5,End=1e-15,MAX_TIME=0.8;
const int N=2145;
int n;
d ansx,ansy,answ;

struct node
{
	int x,y,w;
};

node a[N];

d calc(d x,d y)
{
	d r=0,dx,dy;
	for(int i=1;i<=n;i++)
	{
		dx=x-a[i].x;
		dy=y-a[i].y;
		r+=sqrt(dx*dx+dy*dy)*a[i].w;
	}
	return r;
}

void SA()
{
	d t=Beg;
	while(t>End)
	{
		d ex=ansx+(rand()*2-RAND_MAX)*t,ey=ansy+(rand()*2-RAND_MAX)*t;
		// printf("%.5lf %.5lf\n",ex,ey);
		d ew=calc(ex,ey);
		d de=ew-answ;
		if(de<0)
		{
			ansx=ex,ansy=ey,answ=ew;
		}
		else if(exp(-de/t)*RAND_MAX>rand())
		{
			ansx=ex,ansy=ey;
		}
		t*=down;
	}
}

inline void init()
{
	srand(time(NULL));
	srand(rand()+114514);
	srand(rand()+1919810);
	srand(rand());
}

int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
		ansx+=a[i].x;
		ansy+=a[i].y;
	}
	// printf("%d\n",clock());
	// system("pause>nul");
	ansx/=n,ansy/=n;
	answ=calc(ansx,ansy);
	while((double)clock()/CLOCKS_PER_SEC<MAX_TIME)SA();
	// SA();
	// SA();
	printf("%.3lf %.3lf",ansx,ansy);
	return 0;
}