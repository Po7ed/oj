#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct index_and_point
{
	int index;
	int point;
	friend operator < (index_and_point a,index_and_point b)
	{
		if(a.point==b.point)return a.index>b.index;
		return a.point>b.point;
	}
}iap;

int n,r,q;
priority_queue<iap> l;
int w[100001];

void game()
{
	for(int i=0;i<n;i+=2)
	{
		if(w[l[i].index]>w[l[i+1].index])l[i].point++;
		else l[i+1].point++;
	}
}

int main()
{
	scanf("%d %d %d",&n,&r,&q);
	n*=2;
	for(int i=1;i<=n;i++)
	{
		iap t;
		t.index=i;
		scanf("%d",&t.point);
		l.push(t);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=0;i<r;i++)
		game();
	printf("%d",l[q].index);
	return 0;
}