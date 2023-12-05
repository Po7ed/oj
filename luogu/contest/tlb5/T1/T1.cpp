#include <iostream>
using namespace std;

inline bool p(int a,int b,int c)
{
	return (b-a==c-b);
}

int main()
{
	int t,n;
	// int l1,l2,d1,d2,cur;
	// int ll1,ll2,dd1,dd2;
	int a1,b1,a2,b2,a3,b3,da1,db1,da2,db2,da3,db3;//1,2 2 cases ; a,b 2 sets ; d gc
	int a,b,c,x;
	bool k1=true,k2=true,k3=true;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		// d1=d2=l1=l2=-1;
		scanf("%d %d %d %d",&n,&a,&b,&c);
		/* int a[n+1];
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i]);
		} */
		if(p(a,b,c))
		{
			a1=c;
			da1=c-b;
			b1=-1;
			db1=-1;
			k2=false;
			k3=false;
		}
		else
		{
			a1=c;
			da1=c-a;
			b1=b;
			db1=-1;
			a2=c;
			da2=c-b;
			b2=a;
			db2=-1;
			a3=b;
			da3=b-a;
			b3=c;
			db3=-1;
		}
		for(int j=4;j<=n;j++)
		{
			scanf("%d",&x);
			if(k1)
			{
				if((x-a1)!=da1)
				{//you can only goto b
					if(b1==-1)//there isn't someone
					{
						b1=x;//creat eto-b1
						// db1=-1;
					}
					else//there is someone
					{
						if(db1==-1)//only one,no gangling
						{//creat gnagling
							db1=x-b1;
							b1=x;
						}
						else
						{//have gangling
							if(x-b1==db1)
							{
								b1=x;//welcome to b1,we are tongzhi now
							}
							else
							{
								k1=false;
					//			goto case2;
							}
						}
					}
				}
				else
				{
					a1=x;//welcome to a1,we are tongzhi now
				}
			}
			// continue;
		//	case2:
			if(k2)
			{
				//ao,let's goto 2
				if((x-a2)!=da2)//2(s)
				{//you can only goto b
					if(b2==-1)//there isn't someone
					{
						b2=x;//creat eto-b2
						// db2=-1;
					}
					else//there is someone
					{
						if(db2==-1)//only one,no gangling
						{//creat gangling
							db2=x-b2;
							b2=x;
						}
						else//have gangling
						{
							if(x-b2==db2)
							{
								b2=x;//welcome to b2,we are tongzhi now
							}
							else
							{
								//AO,YOU MUST GO AWAY
								// puts("No");
								k2=false;
								// goto bre;
							//	goto case3;
							}
						}
					}
				}
				else//gangling same
				{
					a2=x;//welcome to a2,we are tongzhi now
				}
			}
			
			
			//case3:
			if(k3)
			{
				//ao,let's goto 3
				if((x-a3)!=da3)//2(s)
				{//you can only goto b
					if(b3==-1)//there isn't someone
					{
						b3=x;//creat eto-b2
						// db2=-1;
					}
					else//there is someone
					{
						if(db3==-1)//only one,no gangling
						{//creat gangling
							db3=x-b3;
							b3=x;
						}
						else//have gangling
						{
							if(x-b3==db3)
							{
								b3=x;//welcome to b2,we are tongzhi now
							}
							else
							{
								//AO,YOU MUST GO AWAY
								// puts("No");
								k3=false;
								// goto bre;
							//	continue;
							}
						}
					}
				}
				else//gangling same
				{
					a3=x;//welcome to a2,we are tongzhi now
				}
			}
			/* printf("*%d:a1=%d b1=%d da1=%d db1=%d a2=%d b2=%d da2=%d db2=%d k1=%d k2=%d\n"
			,j,a1,b1,da1,db1,a2,b2,da2,db2,k1,k2); */
			printf("*%d:k1=%d k2=%d k3==%d\n"
			,j,k1,k2,k3);
		}
		if(!k1&&!k2&&!k3)
			puts("No");
		else
			puts("Yes");
		// bre:;
	}
			/* printf("*5:a1=%d b1=%d da1=%d db1=%d a2=%d b2=%d da2=%d db2=%d k1=%d k2=%d\n"
			,a1,b1,da1,db1,a2,b2,da2,db2,k1,k2); */
	return 0;
}

/*
4
5
1 2 3 5 7
5
1 3 6 10 15
8
1 2 5 6 9 10 13 14
6
1 4 6 7 8 9

*/