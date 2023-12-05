#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef unsigned long long ull;
typedef pair<int,ull> p;
#define id first
#define w second

/* int f[100000];
int fa(int k)//find
{
	if(f[k]==k)
	{
		return k;
	}
	else
	{
		return f[k]=fa(f[k]);
	}
} */

int l[100000];//l[i]:from deep to i's step (-1)

struct cmp
{
	bool operator () (p a,p b)
	{
		return (a.w==b.w?l[a.id]>l[b.id]:a.w>b.w);
	}
};

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	ull wi[n];
	priority_queue<p,vector<p>,cmp> q;
	fill(l,l+n,0);
	for(int i=0;i<n;i++)//id from:0
	{
		// f[i]=i;
		scanf("%llu",&wi[i]);
		q.push({i,wi[i]});
	}
	int nn=n;
	while((q.size()-1)%(k-1))q.push({nn++,0});
	ull t;
	// int c=0,last=-1,li;
	// bool first=true,same=false;//if(same) last and now is in the same deep(floor) 
	bool plus;//if(plus) l[pops]=c++; else l[pops]=c;
	vector<int> pops;
	while(q.size()!=1)
	{
		t=0;//sum of this time of pops.w (s)
		// c++;
		// li=-1;
		// last=q.top().id;
		pops.clear();
		for(int i=0;i<k&&!q.empty();i++)
		{
printf("#%d(%llu) ",q.top().id,q.top().w);
			if(q.top().id!=-1&&q.top().id<n)
				pops.push_back(q.top().id);
			/* if(!i&&!first)
			{
				same=(fa(last)==fa(q.top().id)?)
			}
			if(i)//union (with last i)
			{
				f[fa(i)]=fa(li);
			} */
			t+=q.top().w;
			plus=(q.top().id==-1)||plus;
			// if(!first&&)
			/* if(q.top().id!=-1)
				// l[q.top().id]=c;
			{
				if(last==-1)
				{
					l[q.top().id]=c;
					// last=q.top().id;
				}
				else
				{
					if()
					l[q.top().id]=
				}
			} */
			q.pop();
			// li=i;
		}
// printf("")
puts((plus?"plus":"no"));
		c+=((int)plus);
		for(int tt:pops)
		{
			l[tt]=c;
		}
		q.push({-1,t});
		// first=false;
	}
	// int m=l[q.top().id];
	ull ans=0;
	/* for(int i=0;i<n;i++)
	{
		m=max(m,l[i]);
	} */
	for(int i=0;i<n;i++)
	{
		ans+=((c-l[i]+1)*wi[i]);
	}
	printf("%llu\n%d",ans,c+1);
	// puts("break");
	return 0;
}