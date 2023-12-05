#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string,int>ip;

bool check(string ad)
{
	int a=0,b=0,c=0,d=0,e=0;
	char t1=0,t2=0,t3=0,t4=0;
	sscanf(ad.c_str(),"%d%c%d%c%d%c%d%c%d",&a,&t1,&b,&t2,&c,&t3,&d,&t4,&e);
	if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255||e<0||e>65535)return 0;
	if(t1!='.'||t2!='.'||t3!='.'||t4!=':')return 0;
	stringstream ss;
	ss<<a<<'.'<<b<<'.'<<c<<'.'<<d<<':'<<e;
	if(ss.str()!=ad)return 0;
	return 1;
}

int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string op,ad;
		cin>>op>>ad;
		if(!check(ad))
			printf("ERR\n");
		else
		{
			if(op[0]=='S')
			{
				if(ip[ad]==0)
				{
					ip[ad]=i;
					printf("OK\n");
				}
				else
					printf("FAIL\n");
			}
			else
			{
				if(ip[ad]!=0)
					printf("%d\n",ip[ad]);
				else
					printf("FAIL\n");
			}
		}
	}
	//system("pause>nul");
	return 0;
}