#include <iostream>
#include <algorithm>
using namespace std;

struct node{int id,x;};
const int N=51411;node a[N];int hav[N],n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].id);
	sort(a+1,a+n+1,[](node x,node y){return x.id<y.id;});
	int cnt=0,lst=-1,tmp;
	for(int i=1;i<=n;i++)tmp=a[i].id,a[i].id=(lst==a[i].id?cnt:++cnt),lst=tmp;
	sort(a+1,a+n+1,[](node x,node y){return x.x<y.x;});
	int r=0,all=cnt,ans=0x3f3f3f3f;cnt=0;
	for(int l=1;l<=n;l++)
	{
		while(cnt<all&&r<=n)cnt+=(hav[a[++r].id]?0:1),hav[a[r].id]++;
		if(r>n)break;
		ans=min(ans,a[r].x-a[l].x),hav[a[l].id]--,cnt-=(hav[a[l].id]?0:1);
	}
	printf("%d",ans);
	return 0;
}