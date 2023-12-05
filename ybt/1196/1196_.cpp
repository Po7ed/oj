#include <iostream>
using namespace std;


/* int C(int n,int m)
{
	if(memC[n][m]==0)
	{
		if(n==0||m==0||n==m)memC[n][m]=1;
		else memC[n][m]=C(n-1,m-1)+C(n-1,m);
	}
	return memC[n][m];
} */

int C(int n,int m)
{
	if(m>n)return -1;
	int memC[21][21];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(i==0||j==0||i==j)
				memC[i][j]=1;
			else
				memC[i][j]=memC[i-1][j-1]+memC[i-1][j];
	return memC[n][m];
}

int main()
{
	int n=0,sum=0;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		sum+=C(n,i)*2;
	printf("%d",--sum);
	return 0;
}