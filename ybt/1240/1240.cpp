#include <iostream>
#include <cmath>
using namespace std;
int a[100000];
void binsch(int b,int e,int q)
{
	if(e-b==1)
	{
		if(abs(q-a[b])==abs(q-a[e])){printf("%d\n",a[b]);return;}
		else if(abs(q-a[b])<abs(q-a[e])){printf("%d\n",a[b]);return;}
		else if(abs(q-a[b])>abs(q-a[e])){printf("%d\n",a[e]);return;}
	}
	if(e==b)
	{
		printf("%d\n",a[b]);
		return;
	}
	int mid=(b+e)/2;
	if(a[mid]==q){printf("%d\n",q);return;}
	else if(a[mid]<q){binsch(mid,e,q);}
	else if(a[mid]>q){binsch(b,mid,q);}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int t;
		scanf("%d",&t);
		binsch(0,n-1,t);
	}
	return 0;
}