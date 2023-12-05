#include <iostream>
#include <cstring>
using namespace std;
int s[1000002];
int main()
{
	int n;
	scanf("%d",&n);
	int c[n+1],maxc=-1,minc=0x3f3f3f3f;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		s[c[i]]++;
		maxc=max(maxc,c[i]);
		minc=min(minc,c[i]);
	}
	long long ans=-1;int ind=-1;
	for(int i=maxc;i>=minc;i--)
	{
		s[i]+=s[i+1];
		if(ans<=i*s[i])
		{
			ans=i*s[i];
			ind=i;
		}
	}
	printf("%lld %d\n",ans,ind);
	/* puts("debug:");
	for(int i=0;i<=maxc;i++)
	{
		cout<<"s[i]="<<s[i]<<";i="<<i<<endl;
	} */
	return 0;
}