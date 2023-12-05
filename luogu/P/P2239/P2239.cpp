#include <iostream>
using namespace std;
int main()
{
	int n,i,j,m,cur;
	scanf("%d %d %d",&n,&i,&j);
	m=min(min(i,j),min(n+1-i,n+1-j));
	cur=4*(m-1)*(n-m+1);
	if(i==m)
	{
		cur+=(j-m+1);
	}
	else if(j==m)
	{
		cur=4*m*(n-m)+(m-i+1);
	}
	else if(i==n-m+1)
	{
		cur+=(n-2*m+1)*2+(n+1-j)-m+1;
	}
	else if(j==n-m+1)
	{
		cur+=n-2*(m-1)+i-m;
	}
	printf("%d",cur);
	return 0;
}