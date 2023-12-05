#include <iostream>
#include <vector>
using namespace std;

string s;
vector<int> _;//存储‘_’位置（下标）
int _l;//有多少‘_’
// long long ans=0;

string ts;
#define isyy(c) (c=='A'||c=='E'||c=='I'||c=='O'||c=='U')//判断是否是元音
bool L=false;//是否有‘L’
long long dfs(int dep)
{
	if(_l==dep)
	{
		return (long long)L;//有‘L’才“令人愉快”
	}
	long long t=0;
	if//填元音字母
	(
		(
			(_[dep]-2>=0?!isyy(ts[_[dep]-2]):true)||
			(_[dep]-1>=0?!isyy(ts[_[dep]-1]):true)//用三目运算符防下标越界
		)&&//前两个不能都是元音（只要前两个有一个辅音），
		   //否则构成3个及以上连续的元音字母。下同。
		(
			(_[dep]-1>=0?!isyy(ts[_[dep]-1]):true)||
			(_[dep]+1<_l?!isyy(ts[_[dep]+1]):true)
		)&&//前后不能都是元音
		(
			(_[dep]+1<_l?!isyy(ts[_[dep]+1]):true)||
			(_[dep]+2<_l?!isyy(ts[_[dep]+2]):true)
		)//后两个不能都是元音
	)
	{
		ts[_[dep]]='A';//用‘A’代表元音
		t+=5*dfs(dep+1);
	}
	if//填辅音字母不再赘述
	(
		(
			(_[dep]-2>=0&&ts[_[dep]-2]!='_'?isyy(ts[_[dep]-2]):true)||
			(_[dep]-1>=0&&ts[_[dep]-1]!='_'?isyy(ts[_[dep]-1]):true)
		)&&//如果遇到‘_’也是可以填辅音的
		(
			(_[dep]-1>=0&&ts[_[dep]-1]!='_'?isyy(ts[_[dep]-1]):true)||
			(_[dep]+1<_l&&ts[_[dep]+1]!='_'?isyy(ts[_[dep]+1]):true)
		)&&
		(
			(_[dep]+1<_l&&ts[_[dep]+1]!='_'?isyy(ts[_[dep]+1]):true)||
			(_[dep]+2<_l&&ts[_[dep]+2]!='_'?isyy(ts[_[dep]+2]):true)
		)
	)
	{
		ts[_[dep]]='B';//用‘B’代表辅音
		t+=20*dfs(dep+1);//‘L’特殊考虑
		
		//填‘L’
		ts[_[dep]]='L';
		bool tL=L;//防止之前已经有‘L’被弄没
		L=true;//标记为有‘L’
		t+=dfs(dep+1);
		L=tL;//恢复标记前状态
	}
	ts[_[dep]]='_';
	return t;
}

int main()
{
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='_')
		{
			_.push_back(i);
		}
		if(s[i]=='L')
		{
			L=true;
		}
	}
	_l=_.size();
	ts=s;
	printf("%lld",dfs(0));
	return 0;
}