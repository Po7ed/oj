#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

typedef struct dot
{
	int x,y;
	double d;
	friend bool operator < (dot d1,dot d2)
	{
		return d1.d<d2.d;
	}
}dot;

dot a,b;
int n;
priority_queue<dot> qa,qb;

int main()
{
	scanf("%d %d %d %d",&a.x,&a.y,&b.x,&b.y);
	scanf(" %d",&n);
	for(int i=0;i<n;i++)
	{
		dot t;
		scanf("%d %d",&t.x,&t.y);
		t.d=sqrt(pow(t.x-a.x,2)+pow(t.y-a.y,2));
		qa.push(t);
	}
	double mind=pow(qa.top().d,2);
	while(!qa.empty())
	{
		dot t=qa.top();
		qa.pop();
		t.d=sqrt(pow(t.x-b.x,2)+pow(t.y-b.y,2));
		qb.push(t);
		double d=pow(qa.top().d,2)+pow(qb.top().d,2);
		if(d<mind)mind=d;
	}
	cout<<(int)mind<<endl;
	return 0;
}