#include <iostream>
#include <vector>
using namespace std;

string s;
#define isyy(c) (c=='A'||c=='E'||c=='I'||c=='O'||c=='U')//判断是否是元音
long long dfs(int dep,int y,int f,bool L)//y：连续元音个数，f：连续辅音个数，L：是否有‘L’
{
	if(y>=3||f>=3)
	{
		return 0;
	}
	if(s.size()<=dep)
	{
		return (long long)L;//有‘L’才“令人愉快”
	}
	long long t=0;
	if(s[dep]=='_')
	{
		//填元音字母
		s[dep]='A';//用‘A’代表元音
		t+=5*dfs(dep+1,y+1/* 连续元音数量加1 */,0/* 连续辅音数量清0。下同。 */,L);//一共可填5种元音
		//填辅音字母
		s[dep]='B';//用‘B’代表辅音
		t+=20*dfs(dep+1,0,f+1,L);//‘L’特殊考虑，26-5-1=20，一共可填20种辅音
		//填‘L’
		s[dep]='L';
		t+=dfs(dep+1,0,f+1,true);
		s[dep]='_';//恢复原状
		return t;
	}
	else
	{
		if(isyy(s[dep]))
		{
			return dfs(dep+1,y+1,0,L);
		}
		else
		{
			if(s[dep]=='L')
			{
				return dfs(dep+1,0,f+1,true);
			}
			else
			{
				return dfs(dep+1,0,f+1,L);
			}
		}
	}
	return 114514;
}

int main()
{
	cin>>s;
	printf("%lld",dfs(0,0,0,false));
	return 0;
}