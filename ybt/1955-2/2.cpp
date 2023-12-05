#include <iostream>
using namespace std;
/// @brief l[i][0] => index | l[i][1] => point
int l[200001][2];
int w[200001];
int n,r,q;
int main()
{
	scanf("%d %d %d",&n,&r,&q);n*=2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l[i][1]);
		l[i][0]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=n;i>1;i--)
		for(int j=1;j<i;j++)
			if((l[j][1]==l[j+1][1]&&l[j][0]>l[j+1][0])||l[j][1]>l[j+1][1])
				swap(l[j],l[j+1]);
	for(int i=1;i<=r;i++)
	{
		for(int i=1;i<n;i+=2)
		{
			if(w[l[i][0]]>w[l[i+1][0]])l[i][1]++;
			else l[i+1][1]++;
		}
		for(int i=n;i>1;i--)
			for(int j=1;j<i;j++)
				if((l[j][1]==l[j+1][1]&&l[j][0]>l[j+1][0])||l[j][1]>l[j+1][1])
					swap(l[j],l[j+1]);
	}
	printf("%d",l[q][0]);
	return 0;
}