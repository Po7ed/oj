#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int,int> P;
/// @brief l[i].first => index | l[i].second => point
P l[200001],win[100001],los[100001];
int li,wini,losi,winj,losj;
int w[200001];
int n,r,q;

bool cmp(P x,P y)
{
	return (x.second==y.second&&x.first<y.first)||x.second>y.second;
}
void play()
{
	wini=0;losi=0;
	for(int i=0;i<n;i+=2)
	{
		if(w[l[i].first]>w[l[i+1].first])
		{
			l[i].second++;
			win[wini++]=l[i];
			los[losi++]=l[i+1];
		}
		else
		{
			l[i+1].second++;
			win[wini++]=l[i+1];
			los[losi++]=l[i];
		}
	}
	li=0;winj=0;losj=0;
	while(winj!=wini&&losj!=losi)
	{
		if((win[winj].second==los[losj].second&&win[winj].first<los[losj].first)||
		win[winj].second>los[losj].second)
		{
			l[li++]=win[winj++];
		}
		else
		{
			l[li++]=los[losj++];
		}
	}
	if(wini!=winj)
	{
		while(wini!=winj)
		{
			l[li++]=win[winj++];
		}
	}
	else
	{
		while(losi!=losj)
		{
			l[li++]=los[losj++];
		}
	}
	return;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d %d %d",&n,&r,&q);n*=2;
	li=0;
	for(int i=1;i<=n;i++)
	{
		P t;
		scanf("%d",&t.second);
		t.first=i;
		l[li++]=t;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(l,l+n,cmp);
	for(int i=1;i<=r;i++)
	{
		play();
	}
	printf("%d",l[q-1].first);
	// system("pause");
	return 0;
}