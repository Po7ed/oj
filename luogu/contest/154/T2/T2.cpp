#include <iostream>
using namespace std;

int d[24][2]=
{
	{-4,0},
	{4,0},
	{0,-4},
	{0,4},
	{-4,-2},
	{4,-2},
	{-2,-4},
	{-2,4},
	{-4,2},
	{4,2},
	{2,-4},
	{2,4},
	{-3,-3},
	{-3,-1},
	{-3,1},
	{-3,3},
	{3,-3},
	{3,-1},
	{3,1},
	{3,3},
	{-1,-3},
	{1,-3},
	{-1,3},
	{1,3}
};
#define dx (mx+d[i][0])
#define dy (my+d[i][1])

int main()
{
	int sx,sy,cx,cy,mx,my;
	cin>>sx>>sy>>cx>>cy>>mx>>my;
	bool s=false,c=false;
	if(abs(sx-mx)+abs(sy-my)==2)
	{
		s=true;
	}
	else
	{
		for(int i=0;i<24;i++)
		{
			if(dx==sx&&dy==sy)
			{
				s=true;
				break;
			}
		}
	}
	if(abs(cx-mx)+abs(cy-my)==2)
	{
		c=true;
	}
	else
	{
		for(int i=0;i<24;i++)
		{
			if(dx==cx&&dy==cy)
			{
				c=true;
				break;
			}
		}
	}
	if(s&&c)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}