#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

struct stu
{
	int id;
	ll a;
	friend inline bool operator < (stu x,stu y)
	{
		return (x.a==y.a?x.id>y.id:x.a<y.a);
	}
};

const int N=114514,M=114514;
int a[N];
ll b[N];
priority_queue<stu> q[M];

int main()
{
	freopen("election.in","r",stdin);
	freopen("election.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %lld",a+i,b+i);
		q[a[i]].push({i,b[i]});
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",q[i].top().id);
	}
	return 0;
}