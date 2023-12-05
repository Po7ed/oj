#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	string s;
	long long ans,m,cnt,n;
	for(int i=0;i<t;i++)
	{
		m=-1;
		ans=0;
		cnt=0;
		cin>>s;
		n=s.length();
		s.insert(s.end(),s.begin(),s.end());
		for(char c:s)
		{
			if(c=='0')
			{
				cnt=0;
			}
			else
			{
				cnt++;
			}
			m=max(cnt,m);
		}
		m++;
		if(cnt>=n)
		{
			printf("%lld\n",n*n);
		}
		else
		{
			printf("%lld\n",(m/2)*(m-m/2));
		}
	}
	return 0;
}