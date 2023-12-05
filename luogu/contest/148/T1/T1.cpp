#include <iostream>
using namespace std;
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	n--;
	while(n)
	{
		n/=2;
		cnt++;
	}
	cnt--;
	if(cnt&1)
	{
		cnt--;
	}
	printf("%d",cnt);
	return 0;
}