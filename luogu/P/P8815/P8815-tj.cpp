#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin>>s;
	int sc=0,val=0,len=s.length(),ansor=0,ansand=0;
	#define c s[i]
	for(int i=0;i<len;i++)
	{
		if(sc)
		{
			if(c=='(')
			{
				int k=1;
				while(k)
				{
					i++;
					if(c=='(')
					{
						k++;
					}
					else if(c==')')
					{
						k--;
					}
				}
			}
			else if(c==')'||c=='|'&&sc==1)
			{
				sc=0;
			}
			else if(c=='&'&&sc==1)
			{
				sc=1;
				ansand++;
			}
			else if(c=='|'&&sc==2)
			{
				sc=2;
				ansor++;
			}
		}
		else
		{
			if(c=='0')val=0;
			if(c=='1')val=1;
			if(val==0&&c=='&')
			{
				sc=1;
				ansand++;
			}
			else if(val==1&&c=='|')
			{
				sc=2;
				ansor++;
			}
		}
	}
	printf("%d\n%d %d",val,ansand,ansor);
	return 0;
}