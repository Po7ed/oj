#include <iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	int t;
	scanf("%d",&t);
	int xx=0,yy=0,x=0,y=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='E')
			xx++;
		if(s[i]=='W')
			xx--;
		if(s[i]=='N')
			yy++;
		if(s[i]=='S')
			yy--;
	}
	x=(t/l)*xx;
	y=(t/l)*yy;
	int ll=t%l;
	for(int i=0;i<ll;i++)
	{
		if(s[i]=='E')
			x++;
		if(s[i]=='W')
			x--;
		if(s[i]=='N')
			y++;
		if(s[i]=='S')
			y--;
	}
	printf("%d %d",x,y);
	return 0;
}