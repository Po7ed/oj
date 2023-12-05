#include <iostream>
// #include <cmath>
using namespace std;
int main()
{
	string a,b;
	int c=getchar();
	while(c!='.')
	{
		c=getchar();
	}
	c=getchar();
	while(c!=' ')
	{
		a.push_back(c);
		c=getchar();
	}
	while(c!='.')
	{
		c=getchar();
	}
	c=getchar();
	while(c!='\n')
	{
		b.push_back(c);
		c=getchar();
	}
	int la=a.length(),lb=b.length();
	int l=min(la,lb),i;
	for(i=0;i<l;i++)
	{
		if(a[i]!=b[i])
		{
			puts("NO");
			return 0;
		}
	}
	string s;
	if(la==lb)
	{
		puts("YES");
	}
	else
	{
		if(la>lb)
		{
			s=a;
		}
		else
		{
			s=b;
		}
	}
	for(;i<l;i++)
	{
		if(s[i]!='0')
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
