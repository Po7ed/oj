#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>

using namespace std;
int main()
{
	int a[201],b[201],c[202];
	char ca[202],cb[202];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%s\n%s",&ca,&cb);
	//gets(ca);gets(cb);
	for(int i=0,j=strlen(ca)-1;j>=0;i++,j--)
		a[i]=ca[j]-48;
	for(int i=0,j=strlen(cb)-1;j>=0;i++,j--)
		b[i]=cb[j]-48;
	int i=0;
	for(;i<=200;i++)
	{
		c[i]+=a[i]+b[i];
		if(c[i]>=10)c[i]%=10,c[i+1]++;
	}
	while(!c[i]&&i!=0)i--;
	for(;i>=0;i--)
		printf("%d",c[i]);
	// cout<<c[i];
	// cout<<endl;
	return 0;
}