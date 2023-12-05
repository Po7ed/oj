#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	bool m[3];//0R 1B 2W
	int cnt=0;
	m[0]=m[1]=m[2]=true;
	for(char c:s)
	{
		if(c=='W')
		{
			if(m[2])
			{
				continue;
			}
			else
			{
				m[2]=true;
				cnt++;
			}
		}
		else if(c=='B')
		{
			if(m[2])
			{
				m[2]=false;
				cnt++;
			}
			if(m[1])
			{
				continue;
			}
			else
			{
				m[1]=true;
				cnt++;
			}
		}
		else
		{
			if(m[2])
			{
				m[2]=false;
				cnt++;
			}
			if(m[1])
			{
				m[1]=false;
				cnt++;
			}
			if(m[0])
			{
				continue;
			}
			else
			{
				m[0]=true;
				cnt++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}