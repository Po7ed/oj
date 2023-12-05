#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int,int> P;

#define mid 0
#define up 1
#define down 2
#define left 3
#define right 4

#define x first
#define y second

int lr(int x1,int x2)//A(x1,y1),B(x2,y2)
{
	if(x1==x2)
	{
		return mid;
	}
	if(x1>x2)
	{
		return left;
	}
	if(x1<x2)
	{
		return right;
	}
}

int ud(int y1,int y2)
{
	if(y1==y2)
	{
		return mid;
	}
	if(y1>y2)
	{
		return down;
	}
	if(y1<y2)
	{
		return up;
	}
}

queue<P> q;
int bfs(int x1,int y1,int x2,int y2)
{
	q.push({x1,y1});
	int l,dep=0,d1,d2;
	P t;
	while(1)
	{
		dep++;
		l=q.size();
		for(int i=0;i<l;i++)
		{
			t=q.front();
			q.pop();
			if(t.x==x2&&t.y==y2)
			{
				printf("%d",dep-1);
				return 0;
			}
			d1=lr(t.x,x2);
			d2=ud(t.y,y2);
			if(dep&1)
			{
				if(d1!=up&&d2!=right)
				{
					q.push({t.x-1,t.y-1});
				}
				if(d1!=down&&d2!=left)
				{
					q.push({t.x+1,t.y+1});
				}
			}
			else
			{
				if(d1!=up&&d2!=left)
				{
					q.push({t.x+1,t.y-1});
				}
				if(d1!=down&&d2!=right)
				{
					q.push({t.x-1,t.y+1});
				}
			}
		}
	}
}

int main()
{
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	if((abs(x1-x2)+abs(y1-y2))&1)
	{
		puts("-1");
		return 0;
	}
	bfs(x1,y1,x2,y2);
	return 0;
}