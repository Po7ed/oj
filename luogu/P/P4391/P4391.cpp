#include <iostream>
using namespace std;

int pf[1145141];
char s[1145141];
int n;

int main()
{
	scanf("%d\n%s",&n,s);
	int j=0;
	for(int i=1;i<n;i++)
	{
		while(j&&s[i]!=s[j])
		{
			j=pf[j-1];
		}
		if(s[i]==s[j])
		{
			pf[i]=++j;
		}
		else
		{
			pf[i]=j;
		}
	}
	printf("%d",n-pf[n-1]);
	return 0;
}