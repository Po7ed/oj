#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int k=m+1,t=0;
	int a[m+n+1];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(k<=m+n)
	{
		for(int i=1;i<=m;i++)
		{
			a[i]--;
			if(a[i]==0)a[i]=a[k],k++;
		}
		t++;
	}
	cout<<t<<endl;
	return 0;
}