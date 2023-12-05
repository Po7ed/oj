#include <iostream>
#include <vector>
// #include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> list;
// unordered_map<int,int> pre,nxt;

inline void insert(int x)
{
	auto p=lower_bound(list.begin(),list.end(),x);
	/* if(list.empty())
	{
		list.insert(p,x);
		return;
	}
	if(p==list.end())
	{
		nxt[list.back()]=x;
		pre[x]=list.back();
	}
	else if(*p!=x)
	{
		// cerr<<"*"<<*(p-1)<<" "<<*p<<"\n";
		pre[*p]=x;
		nxt[x]=*p;
		pre[x]=*(p-1);
		nxt[*(p-1)]=x;
	} */
	list.insert(p,x);
}
inline int askth(int x)
{
	auto p=lower_bound(list.begin(),list.end(),x);
	return (p-list.begin()+1);
}
inline int xth(int x)
{
	return list[x-1];
} 
/* inline int prev(int x)
{
	if(pre.count(x))
	{
		return pre[x];
	}
	else
	{
		return -2147483647;
	}
}
inline int next(int x)
{
	if(nxt.count(x))
	{
		return nxt[x];
	}
	else
	{
		return 2147483647;
	}
} */
inline int prev(int x)
{
	auto p=lower_bound(list.begin(),list.end(),x);
	if(p==list.begin())
	{
		return -2147483647;
	}
	return *(p-1);
}
inline int next(int x)
{
	auto p=upper_bound(list.begin(),list.end(),x);
	if(p==list.end())
	{
		return 2147483647;
	}
	return *p;
}

int main()
{
	int n;
	scanf("%d",&n);
	int opt,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&opt,&x);
		if(opt==5)
		{
			insert(x);
		}
		else if(opt==1)
		{
			printf("%d\n",askth(x));
		}
		else if(opt==2)
		{
			printf("*%d\n",xth(x));
		}
		else if(opt==3)
		{
			printf("%d\n",prev(x));
		}
		else if(opt==4)
		{
			printf("%d\n",next(x));
		}
	}
	return 0;
}