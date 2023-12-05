#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[100];
	while(scanf("%s",s)!=EOF)
	{
		int r[100];int rt=0;
		int l[100];int lt=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='(')
				l[lt++]=i;
			if(s[i]==')')
			{
				if(lt==0)
					r[rt++]=i;
				else
					lt--;
			}
		}
		int rh=0;int lh=0;
		for(int i=0;s[i]!='\0';i++)
			printf("%c",s[i]);
		puts("");
		for(int i=0;s[i]!='\0';i++)
		{
			if((lh!=lt)&&(l[lh]==i))
				printf("$"),lh++;
			else if((rh!=rt)&&(r[rh]==i))
				printf("?"),rh++;
			else
				printf(" ");
		}
		puts("");
	}
	return 0;
}