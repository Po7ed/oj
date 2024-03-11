#include <iostream>

int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&a,&b);
		/* if((a&1)&&(b&1))puts("No");
		else  */if(((b&1)||((a<<1)==b&&(b>>1)==a))&&((a&1)||((b<<1)==a&&(a>>1)==b)))puts("No");
		else puts("Yes");
	}
	return 0;
}