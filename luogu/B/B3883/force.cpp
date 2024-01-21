#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char tmp[1000];

char* itoa(int num,char* str,int radix)
{
	char index[]="0123456789ABCDEF";
	unsigned unum;
	int i=0,j,k;
	if(radix==10&&num<0)
	{
		unum=(unsigned)-num;
		str[i++]='-';
	}
	else unum=(unsigned)num;
	do
	{
		str[i++]=index[unum%(unsigned)radix];
		unum/=radix;
	}
	while(unum);
	str[i]='\0';
	if(str[0]=='-')k=1;
	else k=0;
	for(j=k;j<=(i-1)/2;j++)
	{
		char temp;
		temp=str[j];
		str[j]=str[i-1+k-j];
		str[i-1+k-j]=temp;
	}
	return str;
}

int main()
{
	freopen("force.log","w",stderr);
	int n,ans=0,len,half;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		itoa(i,tmp,10);
		len=strlen(tmp);
		half=(len>>1)+(len&1);
		for(int j=0;j<half;j++)
		{
			if(tmp[j]!=tmp[len-j-1])
			{
				goto no;
			}
		}
		ans++;
		ans%=20091119;
		fprintf(stderr,"%d\n",i);
		no:;
	}
	printf("%d",ans);
	return 0;
}