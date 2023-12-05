#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<int> v;
	int res=0,a;
	for(char c:s)
	{
		if(isdigit(c))
		{
			res=res*10+c-'0';
		}
		else if(c=='.')
		{
			v.push_back(res);
			res=0;
		}
		else if(c=='+')
		{
			a=v.back();
			v.pop_back();
			v.back()+=a;
		}
		else if(c=='-')
		{
			a=v.back();
			v.pop_back();
			v.back()-=a;
		}
		else if(c=='*')
		{
			a=v.back();
			v.pop_back();
			v.back()*=a;
		}
		else if(c=='/')
		{
			a=v.back();
			v.pop_back();
			v.back()/=a;
		}
		else
		{
			printf("%d",v.back());
			return 0;
		}
	}
	return 0;
}