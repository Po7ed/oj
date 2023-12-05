#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string ans[n];
	// memset(ans,"",sizeof(ans));
	queue<string> up,down;
	string s,ss;
	for(int i=0;i<n;i++)
	{
		ans[i]="";
		cin>>s>>ss;
		if(ss=="UP")
		{
			up.push(s);
		}
		if(ss=="DOWN")
		{
			down.push(s);
		}
		if(ss=="SAME")
		{
			ans[i]=s;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i]=="")
		{
			if(!down.empty())
			{
				ans[i]=down.front();
				down.pop();
			}
			else
			{
				ans[i]=up.front();
				up.pop();
			}
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}