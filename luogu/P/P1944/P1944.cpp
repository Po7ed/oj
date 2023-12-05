#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n=s.length();
	int dp[n],m,mi;
	dp[0]=0;
	for(int i=1;i<n;i++)
	{
		dp[i]=((i-1-dp[i-1])>=0
		&&((s[i-1-dp[i-1]]=='['&&s[i]==']')
		||(s[i-1-dp[i-1]]=='('&&s[i]==')'))
		?(dp[i-1]+2)+((i-2-dp[i-1])>=0?dp[i-2-dp[i-1]]:0):0);
		if(m<dp[i])m=dp[i],mi=i;
	}
	for(int i=mi-dp[mi]+1;i<=mi;i++)printf("%c",s[i]);
	return 0;
}