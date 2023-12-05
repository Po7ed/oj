#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int cnt=0;
			for(int k=i;k<=j;k++)
			{
				if(s[k]=='(')
				{
					cnt++;
				}
				else
				{
					cnt--;
				}
				if(cnt<0)
				{
					goto no;
				}
			}
			if(cnt!=0)
			{
				goto no;
			}
			ans++;
			no:;
		}
	}
	cout<<ans;
	return 0;
}