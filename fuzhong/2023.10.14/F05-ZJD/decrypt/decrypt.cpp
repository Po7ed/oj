#include <iostream>
using namespace std;

char d[27]=" skcvnfyqiatldwogzrjbumexp";

int n,a[30];

int main()
{
	freopen("decrypt.in","r",stdin);
	freopen("decrypt.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%c",d[a[i]]);
	}
	puts("");
	return 0;
 } 
