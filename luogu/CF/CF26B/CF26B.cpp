#include <iostream>
// #include <vector>
using namespace std;
int main()
{
	int cnt=0,ans=0;
	char c=getchar();
	while(c=='('||c==')')
	{
		if(c=='(')
		{
			cnt++;
		}
		else
		{
			if(cnt)
			{
				cnt--;
				ans+=2;
			}
		}
		c=getchar();
	}
	printf("%d",ans);
	return 0;
}