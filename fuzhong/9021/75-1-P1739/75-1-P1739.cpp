#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<int> v;
	for(char c:s)
	{
		if(c=='(')
			v.push_back(1);
		if(c==')')
		{
			if(v.empty())
			{
				puts("NO");
				return 0;
			}
			else
			{
				v.pop_back();
			}
		}
	}
	if(!v.empty())
	{
		puts("NO");
	}
	else
	{
		puts("YES");
	}
}