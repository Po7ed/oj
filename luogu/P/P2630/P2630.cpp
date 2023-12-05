#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct pictrue
{
	int a[3][3];
	void A()//right 90
	{
		int b[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				b[j][2-i]=a[i][j];
			}
		}
		memcpy(*a,*b,sizeof(a));
		/* for(int i=0;i<3;i++)
		{
			for(int j=0;i<3;j++)
			{
				a[i][j]=b[i][j];
			}
		} */
	}
	void B()//left 90
	{
		int b[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				b[2-j][i]=a[i][j];
			}
		}
		memcpy(*a,*b,sizeof(a));
		/* for(int i=0;i<3;i++)
		{
			for(int j=0;i<3;j++)
			{
				a[i][j]=b[i][j];
			}
		} */
	}
	void C()//left-right
	{
		for(int i=0;i<3;i++)
		{
			swap(a[i][0],a[i][2]);
		}
	}
	void D()//up-down
	{
		for(int i=0;i<3;i++)
		{
			swap(a[0][i],a[2][i]);
		}
	}
	void input()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
	}
	bool equal_to(pictrue p)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(a[i][j]!=p.a[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}pic;

int main()
{
	pic b,e;
	b.input();
	e.input();
	pic t=b;
	t.A();
	if(t.equal_to(e))
	{
		puts("A");
		return 0;
	}
	t=b;
	t.B();
	if(t.equal_to(e))
	{
		puts("B");
		return 0;
	}
	t=b;
	t.C();
	if(t.equal_to(e))
	{
		puts("C");
		return 0;
	}
	t=b;
	t.D();
	if(t.equal_to(e))
	{
		puts("D");
		return 0;
	}
	t=b;
	t.A();t.A();
	if(t.equal_to(e))
	{
		puts("AA");
		return 0;
	}
	t=b;
	t.A();t.B();
	if(t.equal_to(e))
	{
		puts("AB");
		return 0;
	}
	t=b;
	t.A();t.C();
	if(t.equal_to(e))
	{
		puts("AC");
		return 0;
	}
	t=b;
	t.A();t.D();
	if(t.equal_to(e))
	{
		puts("AD");
		return 0;
	}
	puts("Poland cannot into space!!!");
	return 0;
}