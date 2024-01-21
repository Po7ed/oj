#include <iostream>
using namespace std;

const int N=1145,C=N;
int c[N],lst[C],llst[C],ma[C],tmp[C],tt[C];

int main()
{
//	freopen("sd.in","r",stdin);
//	freopen("sd.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
	}
	int d,dd;
	for(int i=1;i<=n;i++)
	{
		d=i-lst[c[i]]-1;
		dd=i-llst[c[i]]-1;
		if(lst[c[i]]==0)
		{
			tmp[c[i]]=1;
		}
		else if(d&1)
		{
			ma[c[i]]=max(ma[c[i]],tmp[c[i]]);
			if(dd&1)
			{
				tmp[c[i]]=1;
			}
		}
		else
		{
			tmp[c[i]]++;
		}
		llst[c[i]]=lst[c[i]];
		lst[c[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",max(tmp[i],ma[i]));
	}
	return 0;
}
