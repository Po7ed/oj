#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int p1,p2,p3;
	cin>>p1>>p2>>p3;
	string s,t,pb;
	cin>>s;
	int ls=s.length();
	for(int i=0;i<ls;i++)
	{
		if(s[i]=='-')
		{
			if(i==0||i==ls-1||s[i-1]>=s[i+1]||((bool)isalpha(s[i-1])!=(bool)isalpha(s[i+1]))||s[i-1]=='-'||s[i+1]=='-')
			{
				t.push_back('-');
				continue;
			}
			if(s[i-1]+1==s[i+1])
			{
				continue;
			}
			for(char b=s[i-1]+1;b<s[i+1];b++)
			{
				if(p1==1)
				{
					for(int j=0;j<p2;j++)
					{
						if(isalpha(b))
						{
							pb.push_back(tolower(b));
						}
						else
						{
							pb.push_back(b);
						}
					}
				}
				else if(p1==2)
				{
					for(int j=0;j<p2;j++)
					{
						if(isalpha(b))
						{
							pb.push_back(toupper(b));
						}
						else
						{
							pb.push_back(b);
						}
					}
				}
				else
				{
					for(int j=0;j<p2;j++)
					{
						pb.push_back('*');
					}
				}
			}
			if(p3==2)
			{
				reverse(pb.begin(),pb.end());
			}
			t.append(pb);
			pb.clear();
		}
		else
		{
			t.push_back(s[i]);
		}
	}
	cout<<t;
	return 0;
}