#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
/// @brief l[i].first => index | l[i].second => point
vector<P> l,win,los;
int w[200001];
int n,r,q;

bool cmp(P x,P y)//score from hige to low > > >
{
	return (x.second==y.second&&x.first<y.first)||x.second>y.second;
}
void play()
{
	for(int i=0;i<n;i+=2)
	{
		if(w[l[i].first]>w[l[i+1].first])
		{
			l[i].second++;
			win.push_back(l[i]);
			los.push_back(l[i+1]);
		}
		else
		{
			l[i+1].second++;
			win.push_back(l[i+1]);
			los.push_back(l[i]);
		}
	}
	l.clear();
	while(!win.empty()&&!los.empty())
	{
		if((win.front().second==los.front().second&&win.front().first<los.front().first)||
		win.front().second>los.front().second)
		{
			l.push_back(win.front());
			win.erase(win.begin());//??????
		}
		else
		{
			l.push_back(los.front());
			los.erase(los.begin());//??????
		}
	}
	if(!win.empty())
	{
		while(!win.empty())
		{
			l.push_back(win.front());
			win.erase(win.begin());//??????
		}
	}
	else
	{
		while(!los.empty())
		{
			l.push_back(los.front());
			los.erase(los.begin());//??????
		}
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d %d %d",&n,&r,&q);n*=2;
	for(int i=1;i<=n;i++)
	{
		P t;
		scanf("%d",&t.second);
		t.first=i;
		l.push_back(t);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(l.begin(),l.end(),cmp);
	for(int i=1;i<=r;i++)
	{
		play();
	}
	printf("%d",l[q-1].first);
	system("pause");
	return 0;
}