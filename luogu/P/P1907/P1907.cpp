#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct node
{
	double x,y;
};
/* struct edge
{
	int v,w;
}; */
struct ndfp
{
	int id;
	double d;
	friend bool operator < (ndfp a,ndfp b)
	{
		return a.d<b.d;
	}
};

inline double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	double D,R;
	int n;
	scanf("%lf %lf\n%d",&D,&R,&n);
	node p[n+2];
	// vector<edge> e[n+2];
	double e[n+2][n+2];
	fill(*e,*e+(n+2)*(n+2),0x3f3f3f3f);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&p[i].x,&p[i].y);
	}
	int a,b;
	while(true)
	{
		scanf("%d %d",&a,&b);
		if(!(a||b))
			break;
		e[a][b]=R*dist(p[a].x,p[a].y,p[b].x,p[b].y);
		e[b][a]=R*dist(p[a].x,p[a].y,p[b].x,p[b].y);
	}
	double bx,by,ex,ey;
	scanf("%lf %lf %lf %lf",&bx,&by,&ex,&ey);
	p[0].x=bx;
	p[0].y=by;
	p[n+1].x=ex;
	p[n+1].y=ey;
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			if(i!=j)
				e[i][j]=min(e[i][j],D*dist(p[i].x,p[i].y,p[j].x,p[j].y));
		}
	}
	priority_queue<ndfp> q;
	q.push({0,0});
	ndfp t;
	double dis[n+2];
	fill(dis,dis+(n+2),0x3f3f3f3f);
	dis[0]=0;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(t.d!=dis[t.id])
		{
			continue;
		}
		for(int i=0;i<=n+1;i++)
		{
			if(dis[i]>dis[t.id]+e[t.id][i])
			{
				dis[i]=dis[t.id]+e[t.id][i];
				q.push({i,dis[i]});
			}
		}
	}
	printf("%.4lf",dis[n+1]);
	return 0;
}