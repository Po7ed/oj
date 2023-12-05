#include <iostream>
// #include <unordered_map>
#include <map>
#include <cmath>
#include <set>
using namespace std;

struct point
{
	int x,y;
};
/* struct line
{
	double k,b;
	friend bool operator < (line x,line y)
	{
		return false;
	}
}; */

//y=kx+b
//y0-kx0=b
#define getk ((double)((double)abs(a[i].y-a[j].y)/(double)abs(a[i].x-a[j].x)))
#define getb ((double)((double)a[i].y-getk*(double)a[i].x))

// #define um unordered_map
// map<line,int> cnt;
map<double,map<double,set<int>>> cnt;

int main()
{
	int n;
	scanf("%d",&n);
	point a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		for(int j=1;j<i;j++)
		{
			cnt[getk][getb].insert(i);
			cnt[getk][getb].insert(j);
		}
	}
	int ans=0;
	for(auto tk:cnt)
	{
		for(auto tb:tk.second)
		{
			ans=max(ans,(int)cnt[tk.first][tb.first].size());
			// printf("k=%.2lf b=%.2lf:cnt=%d\n",tk.first,tb.first,cnt[tk.first][tb.first]);
		}
	}
	printf("%d",ans);
	// cout<<"\n"<<getk(1,1,9,10)<<" "<<getb(1,1,9,10);
	return 0;
}