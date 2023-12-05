#include <iostream>
using namespace std;
int a[514114],b[514114];
int n;

typedef long long ll;
ll ans=0;

void merge(int l=1,int r=n)
{
	if(l>=r)
	{
		return;
	}
	int mid=(l+r)>>1;
	int i=l,j=mid+1,k=l;
	merge(l,mid);
	merge(mid+1,r);
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
			ans+=(mid-i+1);
		}
	}
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=r)
	{
		b[k++]=a[j++];
	}
	for(k=l;k<=r;k++)
	{
		a[k]=b[k];
	}
	return;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	merge();
	printf("%lld",ans);
	return 0;
}