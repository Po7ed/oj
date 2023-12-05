#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string del(string str,const int l,int d)
{
	if(d==0)
		return str;
	bool book=0;
	for(int i=0;i<l;i++)
	{
		if(str[i]>str[i+1])
		{
			for(int j=i;j<l;j++)
				str[j]=str[j+1];
			break;
		}
	}
	return del(str,l-1,d-1);
}

int main()
{
	string n;
	int s=0;
	cin>>n;
	const int len=n.length();
	scanf("%d",&s);
	n.push_back(' ');
	string d=del(n,len,s);
	bool bookfirst=1;
	for(int c=0;c<len-s;c++)
		if(d[c]=='0'&&bookfirst)
		{
			continue;
		}
		else
		{
			printf("%c",d[c]);bookfirst=0;
		}
	return 0;
}
