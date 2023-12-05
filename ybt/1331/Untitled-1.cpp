#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<long long> v;
	string s;
	getline(cin,s);
	while(1)
	{
		long long n=0;
		char c=0;
		if(sscanf(s.c_str(),"%lld",&n))
		{
			v.push_back(n);
			while(s.front()!=' ')
				s.erase(s.begin());
			s.erase(s.begin());
		}
		else if(sscanf(s.c_str(),"%c",&c))
		{
			if(c=='@')
			{
				printf("%lld",v.back());
				break;
			}
			long long a=0,b=0;
			b=v.back();v.pop_back();
			a=v.back();v.pop_back();
			switch(c)
			{
				case '+':v.push_back(a+b);break;
				case '-':v.push_back(a-b);break;
				case '*':v.push_back(a*b);break;
				case '/':v.push_back(a/b);break;
			}
			s.erase(s.begin());
		}
	}
	return 0;
}